//============================================================================
// Name        : Img.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : File to wrap CImg library.
//============================================================================

#ifndef IMG_H_
#define IMG_H_

#include <string>

// Local includes.
#include "CImg.h"
#include "Color.h" 


//==============================================================================
/* Img */
//==============================================================================

/*------------------------------------------------------------------------------
 * Class to wrap CImg library.
 */
class Img {

public:

	// Constructor and destructor.
	Img(int w, int h, std::string title);
	~Img(void) {}

	// Functions to get the height and width of the image.
	int getHeight(void) const;
	int getWidth(void) const;

	// Function to know if the image is closed.
	bool isClosed(void) const;

	// Procedure to set the title of the window.
	void setTitle(const char *title);

	// Draw procedures.
	void drawPoint(int col, int row, Color color);
	void drawCircle(int col, int row, Color color);
	void drawLine(int x0, int y0, int x1, int y1, Color color);
	void drawRectangle
		(const int x0, const int y0, const int x1, const int y1,
		 Color color, const float opacity = 1);

	// Procedure to display the image.
	void display(void);

	// Function to know if the left mouse button has been clicked.
	// Returns true (false) if the left mouse button has (not) been clicked.
	bool mouseClick(void);

private:

	cimg_library::CImg<unsigned char> img;
	cimg_library::CImgDisplay disp;

};

//------------------------------------------------------------------------------
#endif /* IMG_H_ */
