//Casper Chia
//20 Dec 2012
//Game Of Life

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "gol.h"

typedef struct _grid{
	char cell[ROWS][COLUMNS];
	int neighbors[ROWS][COLUMNS];
}GRID;

Grid createGrid(void){
	int i, j;
	Grid newGrid = malloc(sizeof(GRID));
	for(i = 0; i < ROWS; i++ ){
		for(j = 0; j < COLUMNS; j++){
			newGrid->cell[i][j] = DEAD;
			newGrid->neighbors[i][j] = 0;
		}
	}
	return newGrid;
}

void disposeGrid(Grid grid){

}

Grid doa(Grid oldGrid){
	int x, y;
	Grid newGrid = createGrid();
	for(x = 0; x < ROWS; x++){
		for(y = 0; y < COLUMNS; y++){
			if(oldGrid->cell[x][y] == ALIVE){
				//rule 1: Any live cell with fewer than 2 live neighbour dies.
				if(oldGrid->neighbors[x][y] < 2){
					newGrid->cell[x][y] = DEAD;
				//rule 2: Any live cell with two or three live neighbours lives on
				//        to the next generation.
				}else if(oldGrid->neighbors[x][y] == 2 || oldGrid->neighbors[x][y] == 3){
					newGrid->cell[x][y] = ALIVE;
				//rule 3: Any live cell with more than three live neighbours dies.
				}else{
					newGrid->cell[x][y] = DEAD;
				}
			//rule 4: Any dead cell with exactly three live neighbours becomes 
			//        a live cell.	
			}else{
				if(oldGrid->neighbors[x][y] == 3){
					newGrid->cell[x][y] = ALIVE;
				}
			}
		}
	}
	return newGrid;
}

void printGrid(Grid grid){
	int i, j;
	for(i = 0; i < ROWS; i++ ){
		for(j = 0; j < COLUMNS; j++){
			printf("%c", grid->cell[i][j]);
//			printf("%d", grid->neighbors[i][j]);		
			printf(" ");			
		}
		printf("\n");
	}
}

Grid setGrid(Grid grid, int row, int col){
	grid->cell[row][col] = ALIVE;
	return grid;
}

void countNeighbors(Grid grid){
	int x,y;
	int i,j;
	for(x = 0; x < ROWS; x++){
		for(y = 0; y < COLUMNS; y++){
			grid->neighbors[x][y] = 0;
			//case 1: (0, 0)
			if(x == 0 && y == 0){
				if(grid->cell[x][y + 1] == ALIVE){
					grid->neighbors[x][y]++;
				}
				if(grid->cell[x + 1][y] == ALIVE){
					grid->neighbors[x][y]++;
				}
				if(grid->cell[x + 1][y + 1] == ALIVE){
					grid->neighbors[x][y]++;
				}
			//case 2: (0, last)
			}else if(x == 0 && y == COLUMNS - 1){
				if(grid->cell[x][y - 1] == ALIVE){
					grid->neighbors[x][y]++;
				}
				if(grid->cell[x + 1][y - 1] == ALIVE){
					grid->neighbors[x][y]++;
				}
				if(grid->cell[x + 1][y] == ALIVE){
					grid->neighbors[x][y]++;
				}				
			//case 3: (last, 0)
			}else if(x == ROWS - 1 && y == 0){
				if(grid->cell[x - 1][y] == ALIVE){
					grid->neighbors[x][y]++;
				}
				if(grid->cell[x - 1][y + 1] == ALIVE){
					grid->neighbors[x][y]++;
				}
				if(grid->cell[x][y + 1] == ALIVE){
					grid->neighbors[x][y]++;
				}				
			//case 4: (last, last)
			}else if(x == ROWS - 1 && y == COLUMNS - 1){
				if(grid->cell[x][y - 1] == ALIVE){
					grid->neighbors[x][y]++;
				}
				if(grid->cell[x - 1][y - 1] == ALIVE){
					grid->neighbors[x][y]++;
				}
				if(grid->cell[x - 1][y] == ALIVE){
					grid->neighbors[x][y]++;
				}				
			//case 5: (0, any between 0 and last)
			}else if(x == 0 && 0 < y && y < COLUMNS - 1){
				for(i = x; i <= x + 1; i++){
					for(j = y - 1; j <= y + 1; j++){
						if(grid->cell[i][j] == ALIVE){
							grid->neighbors[x][y]++;
						}
					}
				}
				//to remove "double" count
				if(grid->cell[x][y] == ALIVE){
					grid->neighbors[x][y]--;
				}
			//case 6: (any between 0 and last, 0)
			}else if(0 < x && x < ROWS - 1 && y == 0){
				for(i = x - 1; i <= x + 1; i++){
					for(j = y; j <= y + 1; j++){
						if(grid->cell[i][j] == ALIVE){
							grid->neighbors[x][y]++;
						}
					}
				}
				//to remove "double" count
				if(grid->cell[x][y] == ALIVE){
					grid->neighbors[x][y]--;
				}	
			//case 7: (last, any between 0 and last)
			}else if(x == ROWS - 1 && 0 < y && y < COLUMNS - 1){
				for(i = x - 1; i <= x; i++){
					for(j = y - 1; j <= y + 1; j++){
						if(grid->cell[i][j] == ALIVE){
							grid->neighbors[x][y]++;
						}
					}
				}
				//to remove "double" count
				if(grid->cell[x][y] == ALIVE){
					grid->neighbors[x][y]--;
				}				
			//case 8: (any between 0 and last, last)
			}else if(0 < x && x < ROWS - 1 && y == COLUMNS - 1){
				for(i = x - 1; i <= x + 1; i++){
					for(j = y - 1; j <= y; j++){
						if(grid->cell[i][j] == ALIVE){
							grid->neighbors[x][y]++;
						}
					}
				}
				//to remove "double" count
				if(grid->cell[x][y] == ALIVE){
					grid->neighbors[x][y]--;
				}
			//case 9: everything else
			}else{
				for(i = x - 1; i <= x + 1; i++){
					for(j = y - 1; j <= y + 1; j++){
						if(grid->cell[i][j] == ALIVE){
							grid->neighbors[x][y]++;
						}
					}
				}
				//to remove "double" count
				if(grid->cell[x][y] == ALIVE){
					grid->neighbors[x][y]--;
				}				
			}
		}
	}
}

int getNeighbors(Grid grid, int row, int col){
	return grid->neighbors[row][col];
}