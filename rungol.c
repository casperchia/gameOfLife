//Casper Chia
//20 Dec 2012
//Game Of Life

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "gol.h"

int main(int argc, char *argv[]){
	char check, answer;
	Grid oldGrid = createGrid();
	Grid newGrid;
	int q, r;

	printf("Use preset? [y/n]\n");
	assert(scanf("%c", &answer) == 1);
	if(answer == 'y'){
		setGrid(oldGrid, 23, 23);
		setGrid(oldGrid, 23, 24);
		setGrid(oldGrid, 23, 26);
		setGrid(oldGrid, 23, 27);
		setGrid(oldGrid, 24, 23);
		setGrid(oldGrid, 24, 24);
		setGrid(oldGrid, 24, 26);
		setGrid(oldGrid, 24, 27);
		setGrid(oldGrid, 25, 24);
		setGrid(oldGrid, 25, 26);
		setGrid(oldGrid, 26, 24);
		setGrid(oldGrid, 26, 26);
		setGrid(oldGrid, 27, 24);
		setGrid(oldGrid, 27, 26);
		setGrid(oldGrid, 28, 22);
		setGrid(oldGrid, 28, 28);		
		setGrid(oldGrid, 26, 22);
		setGrid(oldGrid, 26, 28);
		setGrid(oldGrid, 27, 22);
		setGrid(oldGrid, 27, 28);
		setGrid(oldGrid, 28, 23);
		setGrid(oldGrid, 28, 27);
	}else{
		printf("Please enter coordinates. [x y]\nWhen finished, enter 999 999.\n");
		q = 0;
		while(q != 999){
			assert(scanf("%d %d", &q, &r) == 2);
			if(q != 999){
				setGrid(oldGrid, q, r);
			}
		}
	}

	countNeighbors(oldGrid);
	printGrid(oldGrid);
	assert(scanf("%c", &check) == 1);
	int iterations;

	for(iterations = 0; iterations < 1000; iterations++){
		assert(scanf("%c", &check) == 1);
		newGrid = doa(oldGrid);
		countNeighbors(newGrid);
		printGrid(newGrid);
		oldGrid = newGrid;
	}
//	int k, j, x;
//	x = 0;
//	while(x < 100){
//		assert(scanf("%d %d", &k, &j) == 2);
//		printGrid(grid);
//		printf("%d\n", getNeighbors(grid, k, j));
//	}
	return EXIT_SUCCESS;
}	