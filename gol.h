//Casper Chia
//20 Dec 2012
//Game Of Life

#define DEAD ' '
#define ALIVE 'X'
#define TRUE 1
#define FALSE 0
#define COLUMNS 50
#define ROWS 50

typedef struct _grid *Grid;

// create grid of size n * n
Grid createGrid(void);

//dispose of grid
void disposeGrid(Grid grid);


//changes cell in new grid to Dead Or Alive according to the following rules.
//rule 1: Any live cell with fewer than 2 live neighbour dies.
//rule 2: Any live cell with two or three live neighbours lives on
//        to the next generation.
//rule 3: Any live cell with more than three live neighbours dies.
//rule 4: Any dead cell with exactly three live neighbours becomes 
//        a live cell.
Grid doa(Grid oldGrid);

//prints the grid
void printGrid(Grid grid);

//sets grid at row,col to ALIVE
Grid setGrid(Grid grid, int row, int col);

//checks and updates each cell with current number of neighbors
void countNeighbors(Grid grid);

int getNeighbors(Grid grid, int row, int col);