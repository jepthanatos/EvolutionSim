//============================================================================
// Name        : Creature.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : File to define and generate a creature.
//============================================================================

#ifndef _CREATURE_H_
#define _CREATURE_H_

#include <vector>
#include <stack>

// Local includes.
#include "Color.h"
#include "Utils.h"
#include "Room.h"

//==============================================================================
/* Creature */
//==============================================================================

/*------------------------------------------------------------------------------
 * Class to define and generate a Creature.
 */
class Creature
{
public:
	// Constructor and destructor.
	Creature(int _col, int _row, int _vR, int _size,
			 int _speed, int _strength, int _health);
	~Creature(void) {}

	// Public functions.
	int getCol(void) { return col; }
	int getRow(void) { return row; }
	bool isDead(void) {	return health <= 0; }
	Color getColor(void) {	return color; }
	void printInfo(void);
	void playTurn(Room &room);

private:
	// Private functions.
	bool findFood(Room &room);
	void move(Room &room);
	void moveRandom(Room &room);
	int checkNeighbours(Room &room);
	bool canMove(void){ return neighbours.size() > 0; }
	bool isHungry(void){ return isFilled < 100; }
	bool hasFood(void){ return foodNumber > 0; }
	void eat(void){ isFilled+=5; foodNumber--; health++; }

	// Private enums
	enum STATES { IDLE, MOVE, EAT };
	enum MOVE_STATES { RANDOM, FOOD, NONE };

	std::vector<std::string> STATES_STRINGS = { "IDLE", "MOVE", "EAT" };
	std::vector<std::string> MOVE_STRINGS = { "RANDOM", "FOOD", "NONE" };

	// Private variables
	int state;
	int secondaryState;
	int turnNumber;
	int foodNumber;
	int col, row;
	int isFilled;
	int generation;
	int genre;
	Color color;
	int visionRange;
	int size;
	int speed;
	int strength;
	int health;
	std::vector<int> neighbours;
	std::vector<int> foodPlaces;
};

//------------------------------------------------------------------------------
#endif /* _CREATURE_H_ */
