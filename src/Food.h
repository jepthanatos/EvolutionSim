//============================================================================
// Name        : Food.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : File to define and generate a food.
//============================================================================

#ifndef Food_H_
#define Food_H_

#include <vector>
#include <stack>

// Local includes.
#include "Color.h"
#include "Utils.h"
#include "Room.h"

//==============================================================================
/* Food */
//==============================================================================

/*------------------------------------------------------------------------------
 * Class to define and generate a Food.
 */
class Food
{
public:
	// Constructor and destructor.
	Food(int _col, int _row, int _health);
	~Food(void) {}

	// Public functions.
	int getCol(void)
	{
		return col;
	}

	int getRow(void)
	{
		return row;
	}

	Color getColor(void)
	{
		return color;
	}

	void printInfo(void);

private:
	// Private functions.

	// Private variables
	int col, row;
	Color color;
	int health;
};

//------------------------------------------------------------------------------
#endif /* Food_H_ */