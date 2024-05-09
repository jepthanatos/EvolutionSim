//============================================================================
// Name        : Utils.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : File with useful functions.
//============================================================================

#ifndef UTILS_H_
#define UTILS_H_

#include <cstdlib>
#include <ctime>

//==============================================================================
/* Utils */
//==============================================================================

/*------------------------------------------------------------------------------
 * Class to define useful functions.
 */
class Utils {

public:

	static void initRamdom(void){
		srand(time(NULL));
	}

	static int pickRandom(int min, int max) {
		return rand() % (max - min + 1) + min;
	}

};

//------------------------------------------------------------------------------
#endif /* UTILS_H_ */
