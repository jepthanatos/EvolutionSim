//============================================================================
// Name        : Creature.cpp
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : File to define and generate a Creature.
//============================================================================

#include "Creature.h"

#include <iostream>

// Local includes.
#include "Color.h"
#include "Astar.h"


//==============================================================================
/* Creature */
//==============================================================================

/*------------------------------------------------------------------------------
 * Constructor.
 */
Creature::Creature(int _col, int _row, int _vR, int _size,
				   int _speed, int _strength, int _health) :
				col{_col}, row{_row}, visionRange{_vR}, size{_size},
				speed{_speed}, strength{_strength}, health{_health}
{
	// Color changes in function of other skills.
	// +Size = -Speed = Red
	// Health = Green
	// Strength = Blue
	int red = 100;

	if (speed > size)
		red -= (speed * 10);
	else
		red += (size * 10);

	color = Color(red, health * 10, strength * 10);

	generation = 0;
	genre = Utils::pickRandom(0, 1);

	isFilled = 100;
	turnNumber = 0;
	foodNumber = 0;

	state = STATES::IDLE;
	secondaryState = MOVE_STATES::NONE;

	foodPlaces.clear();
}

/*------------------------------------------------------------------------------
 * Function to ...
 */
int Creature::checkNeighbours(Room &room) {
	std::vector<int> vectorIndex = {
		room.index(col -1 , row - 1), 	// Top-left
		room.index(col, row - 1), 		// Top
		room.index(col + 1, row - 1), 	// Top-right
		room.index(col + 1, row),		// Right
		room.index(col + 1, row + 1),	// Bottom-right
		room.index(col, row + 1),		// Bottom
		room.index(col - 1, row + 1),	// Bottom-left
		room.index(col - 1, row) 		// Left
	};

	neighbours.clear();

	for (unsigned int i = 0; i < vectorIndex.size(); ++i) {
		int index = vectorIndex[i];
		if (index > -1 and room.isWalkable(index)){
			neighbours.push_back(i);
		}
		if (index > -1 and !room.isWalkable(index) and !room.isFood(index)){
			//algo
		}
	}

	if (neighbours.size() > 0) {
		return neighbours[Utils::pickRandom(0, neighbours.size() - 1)];
	} else {
		return -1;
	}
}

/*------------------------------------------------------------------------------
 * Function to ...
 */
bool Creature::findFood(Room &room){
	int oldCol = col;
	int oldRow = row;

	for (int i = col - visionRange; i < col + visionRange; ++i){
		for (int j = row - visionRange; j < row + visionRange; ++j){
			int index = room.index(i,j);
			if (index > -1 and room.isFood(index)){
				// If the creature already know the index of the food is not
				// add again to the list of know food places.
				if (foodPlaces.empty()){
					foodPlaces.push_back(index);
				}
				else if (!std::count(foodPlaces.begin(), foodPlaces.end(), index)){
					foodPlaces.push_back(index);
				}
			}
		}
	}

	if (!foodPlaces.empty()){
		Astar astar(room.getCols(), room.getRows(), room.getGrid());
		std::stack<int> path = astar.getPath(room.getTile(col,row), room.getTile(foodPlaces.back()));
		//std::cout << "Food in " << room.getTile(foodPlaces.back()).getCol() << ":" << room.getTile(foodPlaces.back()).getRow() << std::endl;
		if (!path.empty()){
			path.pop();
			if (!path.empty()){
				int index = path.top();
				Tile t = room.getTile(index);
				//std::cout << "Moving to " << t.getCol() << ":" << t.getRow() << std::endl;
				col = t.getCol();
				row = t.getRow();
			}
			else
				foodNumber++;
			return true;
		}
	}

	return false;
}

/*------------------------------------------------------------------------------
 * Function to move randomly a creature.
 */
void Creature::moveRandom(Room &room)
{
	int oldCol = col;
	int oldRow = row;

	std::vector<std::vector<int>> vectorColRow = {
		{col -1 , row - 1}, 	// Top-left
		{col, row - 1}, 		// Top
		{col + 1, row - 1}, 	// Top-right
		{col + 1, row},			// Right
		{col + 1, row + 1},		// Bottom-right
		{col, row + 1},			// Bottom
		{col - 1, row + 1},		// Bottom-left
		{col - 1, row} 			// Left
	};

	int index = checkNeighbours(room);

	if (index != -1){
		col = vectorColRow[index][0];
		row = vectorColRow[index][1];
	}
}


/*------------------------------------------------------------------------------
 * Function to move a creature.
 */
void Creature::move(Room &room)
{
	if (secondaryState == MOVE_STATES::RANDOM){
		moveRandom(room);
	}
	else if (secondaryState == MOVE_STATES::FOOD){
		if (!findFood(room))
			moveRandom(room);
	}

	if (isHungry())
		health--;
}

/*------------------------------------------------------------------------------
 * Function to play a creatures turn.
 */
void Creature::playTurn(Room &room){

	turnNumber++;
	if (turnNumber % 10 == 0) isFilled--;

	checkNeighbours(room);

	switch (state) {
		case STATES::IDLE :
			if (isHungry()){
				if (hasFood()){
					state = STATES::EAT;
					secondaryState = MOVE_STATES::NONE;
				}
				else if (canMove()) {
					state = STATES::EAT;
					secondaryState = MOVE_STATES::FOOD;
				}
			}
			else if (canMove()){
				state = STATES::MOVE;
				secondaryState = MOVE_STATES::RANDOM;
			}
			break;

		case STATES::MOVE :
			if (isHungry()){
				if (hasFood()){
					state = STATES::EAT;
					secondaryState = MOVE_STATES::NONE;
				}
				else if (canMove()) {
					state = STATES::MOVE;
					secondaryState = MOVE_STATES::FOOD;
					move(room);
				}
				else {
					state = STATES::IDLE;
					secondaryState = MOVE_STATES::NONE;
				}
			}
			else if (canMove()){
				move(room);
			}
			else {
				state = STATES::IDLE;
				secondaryState = MOVE_STATES::NONE;
			}
			break;

		case STATES::EAT :
			if (isHungry()){
				if (hasFood()){
					eat();
				}
				else if (canMove()){
					state = STATES::MOVE;
					secondaryState = MOVE_STATES::FOOD;
				}
				else{
					state = STATES::IDLE;
					secondaryState = MOVE_STATES::NONE;
				}
			}
			else{
				state = STATES::IDLE;
				secondaryState = MOVE_STATES::NONE;
			}
			break;
	}
}

/*------------------------------------------------------------------------------
 * Function to print info.
 */
void Creature::printInfo(void){
	const std::string pipe(" | ");
	std::cout << "(" << col << "," << row << "): ";
	std::cout << "state - " << STATES_STRINGS[state] << pipe;
	std::cout << "2state - " << MOVE_STRINGS[secondaryState] << pipe;
	std::cout << "foodNumber - " << foodNumber << pipe;
	std::cout << "isFilled - " << isFilled << pipe;
	std::cout << "health - " << health << std::endl;
	/*std::cout << generation << ", " << genre << ", " << visionRange << ", " <<
	size << ", " <<	speed << ", " << strength << ", " << health << std::endl;*/
}

//==============================================================================
