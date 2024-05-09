//============================================================================
// Name        : Food.cpp
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : File to define and generate a Food.
//============================================================================

#include "Food.h"

#include <iostream>

// Local includes.
#include "Color.h"

//==============================================================================
/* Food */
//==============================================================================

/*------------------------------------------------------------------------------
 * Constructor.
 */
Food::Food(int _col, int _row, int _health) : 
	col{_col}, row{_row}, health{_health}, color{Color(0, 0, 0)}
{}

/*------------------------------------------------------------------------------
 * Function to print info.
 */
void Food::printInfo(void)
{
	std::cout << "(" << col << "," << row << "): ";
	std::cout << health << std::endl;
}

//==============================================================================
