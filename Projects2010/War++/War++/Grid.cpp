//Include Statements
#include "stdafx.h"
#include "Tile.h"

class Grid {
	private: 
		//Create a Default Grid
		const int ROWS;
		const int COLS;

		int **grid;
	public:

		Grid::Grid(int x=10, int y=10): ROWS(x),COLS(y)
		{
			//Grid to Correct Size
			grid=new int*[ROWS];

			for(int i=0; i<ROWS; i++)
				grid[i]=new int [COLS];
		}

		void Grid::reSizeGrid(int x, int y) {
			//Todo
		}
		Tile Grid::getTile(int x, int y) {
			return grid[x][y];
		}
};