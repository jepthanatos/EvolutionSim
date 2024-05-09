//============================================================================
// Name        : Astar.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : File to find the optimal way to move between two points.
//============================================================================

#ifndef ASTAR_H_
#define ASTAR_H_

#include <vector>
#include <stack>

// Local includes.
#include "Tile.h"

//==============================================================================
/* Astar */
//==============================================================================

/*------------------------------------------------------------------------------
 * Class to find the optimal way to move between two points.
 */
class Astar {
public:
	// Constructor and destroyer.
	Astar(const int w, const int h, std::vector<Tile> map);
	~Astar(){}

	// Public functions
	std::stack<int> getPath(Tile start, Tile end);

private:
	// Private functions
	int Index(int i, int j);
	Tile getLowestF(std::vector<int> openSet);
	int findIndex(int index, std::vector<int> set);
	void AddNeighbours(Tile &c);
	int heuristic(Tile p, Tile end);

	// Private variables
	int width, height;
	Tile start, end;
	std::vector<Tile> grid;
	std::vector<int> openSet;
	std::vector<int> closedSet;
	std::stack<int> path;
};
//------------------------------------------------------------------------------
#endif /* ASTAR_H_ */