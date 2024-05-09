//============================================================================
// Name        : Color.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : File to define RGB colors used by CImg library.
//============================================================================

#ifndef COLOR_H_
#define COLOR_H_

#include <cstdint>

//==============================================================================
/* Color */
//==============================================================================

class Color
{
public:
	// Constructors and destructor.
	Color(void);
	Color(unsigned char _r, unsigned char _g, unsigned char _b);
	~Color(void) {}

	// Predefined colors.
	static const Color &blue(void);
	static const Color &black(void);
	static const Color &yellow(void);
	static const Color &red(void);

	bool isBlack(void) { return r == 0 and g == 0 and b == 0; }

	unsigned char getR(void){ return r; } 
	unsigned char getG(void){ return g; } 
	unsigned char getB(void){ return b; } 

private:
	unsigned char r;
	unsigned char g;
	unsigned char b;

};

//------------------------------------------------------------------------------
#endif /* COLOR_H_ */
