// BitmapPicture.h - BitmapPicture class declaration
// Ryan Geiger

#pragma once
#include <iostream>
#include <string>
using namespace std;

class BitmapPicture
{
private:
	string Bitmap;
	int Zoom;

public:
	// Default/Init constructor, Destructor
	BitmapPicture() { Zoom = 1; }
	BitmapPicture( string hex );
	~BitmapPicture() {}

	// Set/Get Bitmap methods
	void SetHexToBitmap( string hex );
	string GetBitmap() { return Bitmap; }

	// Zoom in to a max of 4x by duplicating bits horizontally and vertically
	void ZoomIn();
	// Zoom out after zooming in
	void ZoomOut();

	// Rotate 90 degrees - cw if bool passed is true, ccw otherwise (assumes bitmap is square)
	void Rotate( bool cw );

	// Flip the bits in the bitmap, turning on those that were off and vice versa
	void Invert();
};