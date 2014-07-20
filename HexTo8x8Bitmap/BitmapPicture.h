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
	BitmapPicture() { Zoom = 1; };
	BitmapPicture( string hex );
	void SetHexToBitmap( string hex );
	string GetBitmap() { return Bitmap; }

	// Zoom in to a max of 4x by duplicating bits horizontally and vertically
	void ZoomIn();
	// Zoom out after zooming in
	void ZoomOut();

	// Rotate clockwise
	void RotateCW();
	// Rotate counter-clockwise
	void RotateCCW();

	// Flip the bits in the bitmap, turning on those that were off and vice versa
	void Invert();
};