//============================================================================
// Name        : Tile.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : File to define a tile used in the room.
//============================================================================

#ifndef TILE_H_
#define TILE_H_

#include <vector>

// Local includes.
#include "Utils.h"
#include "Color.h"

//==============================================================================
/* Tile */
//==============================================================================

/*------------------------------------------------------------------------------
 * Class to define a tile used in the room.
 */
class Tile
{

public:
	// Default constructor.
	Tile(void) : col{-1}, row{-1}, walkable{false}, tileIsFood{false}
	{
		f = g = h = 0;
		previous = -1;
	}

	// Initialize constructor.
	Tile(int i, int j, bool v) : col{i}, row{j}, walkable{v}, tileIsFood{false}
	{
		f = g = h = 0;
		previous = -1;
	}

	// Initialize constructor.
	Tile(int i, int j, bool v, bool f) : col{i}, row{j}, walkable{v}, tileIsFood{f}
	{
		f = g = h = 0;
		previous = -1;
	}

	// Destructor.
	~Tile(void) {}

	void clearNeighbours(void)
	{
		neighbours.clear();
	}

	// Operators.
	bool operator==(const Tile &tile)
	{
		return tile.col == col and tile.row == row;
	}

	Tile operator+(const Tile &tile)
	{
		return Tile(tile.col + col, tile.row + row, false);
	}

	// Getters.
	int getCol(void) const
	{
		return col;
	}

	int getRow(void) const
	{
		return row;
	}

	int getF(void) const
	{
		return f;
	}

	int getG(void) const
	{
		return g;
	}

	int getH(void) const
	{
		return h;
	}

	int getPrevious(void) const
	{
		return previous;
	}

	int isWalkable(void) const
	{
		return walkable;
	}

	bool isFood(void) const
	{
		return tileIsFood;
	}

	Color getColor(void) const
	{
		return color;
	}

	bool getWall(int pos) const
	{
		return walls[pos];
	}

	int getRandomNeighbour(void) const
	{
		return neighbours[Utils::pickRandom(0, neighbours.size() - 1)];
	}

	std::vector<int> getNeighbours(void) const
	{
		return neighbours;
	}

	// Setters.
	void setWalkable(bool value)
	{
		walkable = value;
	}

	void setIsFood(bool value)
	{
		tileIsFood = value;
	}

	void setColor(Color value)
	{
		color = value;
	}

	void addNeighbour(int index)
	{
		neighbours.push_back(index);
	}

	void setWall(int pos, bool value)
	{
		walls[pos] = value;
	}

	void setF(int value)
	{
		f = value;
	}

	void setG(int value)
	{
		g = value;
	}

	void setH(int value)
	{
		h = value;
	}

	void setPrevious(int value)
	{
		previous = value;
	}

	// Other functions.
	bool hasNeighbours(void)
	{
		return neighbours.size() > 0;
	}

	void clearFGH()
	{
		f = g = h = 0;
		previous = -1;
	}

private:
	// Private variables
	int col, row;
	std::vector<bool> walls = {false, false, false, false};
	std::vector<int> neighbours;
	bool walkable;
	bool tileIsFood;
	Color color = Color(255, 255, 225);
	int f, g, h;
	int previous;
};

//------------------------------------------------------------------------------
#endif /* TILE_H_ */
