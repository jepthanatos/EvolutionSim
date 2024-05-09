//============================================================================
// Name        : Room.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : File to define and generate a Room.
//============================================================================

#ifndef Room_H_
#define Room_H_

#include <vector>

// Local includes.
#include "Tile.h"
#include "Img.h"

//==============================================================================
/* Room */
//==============================================================================

/*------------------------------------------------------------------------------
 * Class to define and generate a Room.
 */
class Room {
public:
	// Constructor and destructor.
	Room(const int _cols, const int _rows);
	~Room(void) {}

	// Public functions.
	void printRoom(void);
	int index(int i, int j);

	bool isWalkable(int i, int j){
		return grid[index(i,j)].isWalkable();
	}

	bool isWalkable(int index){
		return grid[index].isWalkable();
	}

	bool isFood(int index){
		return grid[index].isFood();
	} 

	/*int getFood(int i, int j){
		return grid[index(i,j)].getFood();
	}*/

	void addCreature(const int col, const int row, Color color) {
		grid[index(col,row)].setWalkable(false);
		grid[index(col,row)].setColor(color);

		if (color.isBlack()) 
			grid[index(col,row)].setIsFood(true);
	}

	void resetGrid(void){
		grid = oldGrid;
	} 

	// Getters.
	std::vector<Tile> getGrid(void) {
		return grid;
	}

	const Tile getTile(int i, int j){
		return grid[index(i,j)];
	}

	const Tile getTile(int index){
		return grid[index];
	}

	const int getCols(void) const{
		return cols;
	} 

	const int getRows(void) const{
		return rows;
	} 

private:

	// Private functions.
	int checkNeighbours(Tile &c);
	void removeWalls(Tile &a, Tile &b);
	void printWalls(int i, int j, const Tile &tile, Img &img);

	// Private variables
	int cols, rows;
	std::vector<Tile> grid;
	std::vector<Tile> oldGrid;
};

//------------------------------------------------------------------------------
#endif /* Room_H_ */
