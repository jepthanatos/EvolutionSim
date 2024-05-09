//============================================================================
// Name        : Room.cpp
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : File to define and generate a Room.
//============================================================================

#include "Room.h"

// Local includes.
#include "Color.h"


//==============================================================================
/* Room */
//==============================================================================

/*------------------------------------------------------------------------------
 * Constructor.
 */
Room::Room(const int _cols, const int _rows) : cols{_cols}, rows{_rows} {
	for (int j = 0; j < rows; ++j) {
		for (int i = 0; i < cols; ++i) {
			Tile tile(i, j, true);
			grid.push_back(tile);
		}
	}

	oldGrid = grid;
}

/*------------------------------------------------------------------------------
 * Function to get the index of a tile.
 * Returns -1 if the col or the row are out of the array.
 */
int Room::index(int col, int row) {
	if (col < 0 or row < 0 or col >= cols or row >= rows){
		return -1;
	}
	return col + row * cols;
}

/*------------------------------------------------------------------------------
 * Procedure to print an already generated Room.
 */
void Room::printRoom(void) {
	Img img(cols * 10, rows * 10, "Generated Room");

	while (!img.isClosed()) {
		for (int j = 0; j < rows; ++j) {
			for (int i = 0; i < cols; ++i) {
				Tile tile = grid[index(i, j)];

				// Print each tile blue.
				img.drawRectangle(i * 10, j * 10, i * 10 + 10, j * 10 + 10, 
					tile.getColor());

				printWalls(i, j, tile, img);
			}
		}
		img.display();
	}
}

/*------------------------------------------------------------------------------
 * Procedure to print a Room's walls.
 */
void Room::printWalls(int i, int j, const Tile &tile, Img &img){
	// Top.
	if (tile.getWall(0)) {
		img.drawLine(i * 10, j * 10, i * 10 + 10, j * 10, Color::black());
	}

	// Bottom.
	if (tile.getWall(2)) {
		img.drawLine(i * 10, j * 10 + 10, i * 10 + 10,	j * 10 + 10, Color::black());
	}

	// Right.
	if (tile.getWall(1)) {
		img.drawLine(i * 10 + 10, j * 10, i * 10 + 10,	j * 10 + 10, Color::black());
	}

	// Left.
	if (tile.getWall(3)) {
		img.drawLine(i * 10, j * 10, i * 10, j * 10 + 10, Color::black());
	}
}

//==============================================================================
