// Project:	Zoom, Rotate, Invert Hex to Bitmap Picture
// Author:	Ryan Geiger
// Date:	7/20/14

#include <iostream>
#include "BitmapPicture.h"
using namespace std;

int main()
{
	// Testing
	BitmapPicture test;
	
	// Initialize Bitmap
	test.SetHexToBitmap( "18 3c 7E 7e 18 18 18 18" );
	cout << test.GetBitmap() << endl << endl;

	// Zoom 2x
	test.ZoomIn();
	cout << test.GetBitmap() << endl << endl;
	// Zoom 4x
	test.ZoomIn();
	cout << test.GetBitmap() << endl << endl;
	// Attempt to Zoom 8x
	test.ZoomIn();
	// Zoom out twice
	test.ZoomOut();
	cout << test.GetBitmap() << endl << endl;
	test.ZoomOut();
	cout << test.GetBitmap() << endl << endl;

	// Rotate cw, then ccw
	test.Rotate( true );
	cout << test.GetBitmap() << endl << endl;
	test.Rotate( false );
	cout << test.GetBitmap() << endl << endl;

	// Invert
	test.Invert();
	cout << test.GetBitmap() << endl << endl;

	return 0;
}