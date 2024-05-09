//============================================================================
// Name        : Astar.cpp
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : File to find the optimal way to move between two points.
//============================================================================

#include "Astar.h"

#include <iostream>

// Local includes.
#include "Color.h"
#include "Utils.h"
#include "Tile.h"
#include "Img.h"

//==============================================================================
/* Astar */
//==============================================================================

/*------------------------------------------------------------------------------
 * Constructor.
 */
Astar::Astar(const int cols, const int rows, std::vector<Tile> map) :
	width{cols}, height{rows}, grid{map} 
{
	for (unsigned int i = 0; i < grid.size(); ++i)
	{
		AddNeighbours(grid[i]);
	}
}

/*------------------------------------------------------------------------------
 * Constructor.
 */
int Astar::Index(int i, int j)
{
	if (i < 0 or j < 0 or i >= width or j >= height)
	{
		return -1;
	}
	return i + j * width;
}

/*------------------------------------------------------------------------------
 * Function to get the lowest F.
 */
Tile Astar::getLowestF(std::vector<int> openSet)
{
	int lowestValue = 9999;
	Tile c;
	for (unsigned int i = 0; i < openSet.size(); ++i)
	{
		if (grid[openSet[i]].getF() < lowestValue)
		{
			lowestValue = grid[openSet[i]].getF();
			c = grid[openSet[i]];
		}
	}
	return c;
}

/*------------------------------------------------------------------------------
 * Function to get the index into a set.
 */
int Astar::findIndex(int index, std::vector<int> set)
{
	for (unsigned int i = 0; i < set.size(); ++i)
	{
		if (set[i] == index)
		{
			return i;
		}
	}
	return -1;
}

/*------------------------------------------------------------------------------
 * Procedure to update the neighbours of a tile.
 */
void Astar::AddNeighbours(Tile &c)
{
	std::vector<int> vectorIndex = {
		Index(c.getCol(), c.getRow() - 1), // Top
		Index(c.getCol() + 1, c.getRow()), // Right
		Index(c.getCol(), c.getRow() + 1), // Bottom
		Index(c.getCol() - 1, c.getRow())  // Left
	};

	c.clearNeighbours();

	for (unsigned int i = 0; i < vectorIndex.size(); ++i)
	{
		int index = vectorIndex[i];
		if (index > -1 and !c.getWall(i) and c.isWalkable())
		{
			c.addNeighbour(index);
		}
	}

	vectorIndex.clear();

	vectorIndex = {
		Index(c.getCol() + 1, c.getRow() - 1), // Top-Right
		Index(c.getCol() + 1, c.getRow() + 1), // Bottom-Right
		Index(c.getCol() - 1, c.getRow() + 1), // Bottom-Left
		Index(c.getCol() - 1, c.getRow() - 1)  // Top-Lef
	};

	for (unsigned int i = 0; i < vectorIndex.size(); ++i)
	{
		int index = vectorIndex[i];
		if (index > -1 and c.isWalkable())
		{
			if ((!c.getWall(i) and
				 !grid[index].getWall((i + 3) % vectorIndex.size())) or
				(!c.getWall((i + 1) % vectorIndex.size()) and
				 !grid[index].getWall((i + 2) % vectorIndex.size())))
			{
				c.addNeighbour(index);
			}
		}
	}
}

/*------------------------------------------------------------------------------
 * Heuristic function.
 */
int Astar::heuristic(Tile p, Tile end)
{
	int x = end.getCol() - p.getCol();
	int y = end.getRow() - p.getRow();
	return (x * x) + (y * y);
}

/*------------------------------------------------------------------------------
 * Procedure to generate the path from the start tile to the end tile.
 */
std::stack<int> Astar::getPath(Tile start, Tile end)
{
	for (unsigned int i = 0; i < grid.size(); ++i)
	{
		grid[i].clearFGH();
	}

	this->start = start;
	this->end = end;
	int currentIndex = Index(start.getCol(), start.getRow());

	openSet.clear();
	closedSet.clear();

	openSet.push_back(currentIndex);

	while (!openSet.empty())
	{
		Tile c = getLowestF(openSet);
		currentIndex = Index(c.getCol(), c.getRow());

		// If the actual tile is the end we have ended.
		if (c == end)
		{
			/*for (int i = 0; i < 4; ++i)
			{
				std::cout << c.getWall(i) << " ";
			}
			std::cout << std::endl;*/
			while (!path.empty())
			{
				path.pop();
			}
			//path.push(currentIndex);
			while (grid[currentIndex].getPrevious() != -1)
			{
				std::cout << " " << grid[currentIndex].getCol() << ":" << grid[currentIndex].getRow();
				currentIndex = grid[currentIndex].getPrevious();
				path.push(currentIndex);
			}
			std::cout << std::endl;
			return path;
		}

		openSet.erase(openSet.begin() + findIndex(currentIndex, openSet));
		closedSet.push_back(currentIndex);

		for (int neighbour : c.getNeighbours())
		{
			// Neighbour is not in the Closed Set.
			if (findIndex(neighbour, closedSet) == -1)
			{
				int tempG = grid[currentIndex].getG() + 1;

				// Neighbour is on the Open Set.
				if (findIndex(neighbour, openSet) != -1)
				{
					if (tempG < grid[neighbour].getG())
					{
						grid[neighbour].setG(tempG);
						grid[neighbour].setH(heuristic(grid[neighbour], end));
						grid[neighbour].setF
							(grid[neighbour].getG() + grid[neighbour].getH());
						grid[neighbour].setPrevious(currentIndex);
					}
				}
				else
				{
					grid[neighbour].setG(tempG);
					openSet.push_back(neighbour);
					grid[neighbour].setH(heuristic(grid[neighbour], end));
					grid[neighbour].setF(grid[neighbour].getG() + grid[neighbour].getH());
					grid[neighbour].setPrevious(currentIndex);
				}
			}
		}
	}

	while (!path.empty())
	{
		path.pop();
	}
	return path;
}