// BitmapPicture.cpp - BitmapPicture class implementation
// Ryan Geiger

#pragma once
#include "BitmapPicture.h"
#include <vector>

// init constructor
BitmapPicture::BitmapPicture( string hex )
{
	SetHexToBitmap( hex );
	Zoom = 1;
}

// accept a string of hexadecimal input and convert it into a bitmap
void BitmapPicture::SetHexToBitmap( string hex )
{
	Bitmap = "";

	for( unsigned int i = 0; i < hex.length(); i++ )
	{
		hex[i] = toupper( hex[i] );

		switch( hex[i] )
		{
			case '0': Bitmap += "    "; break;
			case '1': Bitmap += "   x"; break;
			case '2': Bitmap += "  x "; break;
			case '3': Bitmap += "  xx"; break;
			case '4': Bitmap += " x  "; break;
			case '5': Bitmap += " x x"; break;
			case '6': Bitmap += " xx "; break;
			case '7': Bitmap += " xxx"; break;
			case '8': Bitmap += "x   "; break;
			case '9': Bitmap += "x  x"; break;
			case 'A': Bitmap += "x x "; break;
			case 'B': Bitmap += "x xx"; break;
			case 'C': Bitmap += "xx  "; break;
			case 'D': Bitmap += "xx x"; break;
			case 'E': Bitmap += "xxx "; break;
			case 'F': Bitmap += "xxxx"; break;
			case ' ': Bitmap += "\n"; break;
			default: break;
		}
	}
}

// Zoom in to a max of x4 by duplicating bits horizontally and vertically
void BitmapPicture::ZoomIn()
{
	// verify Zoom is x1 or x2
	if( Zoom == 1 || Zoom == 2 )
	{
		// predetermine bitmap length, as it will be changing in loop
		int BitmapLength = Bitmap.length();

		// traverse through bitmap via i, use bitPos to keep track of changing position in bitmap, use endLine to keep track of end of prev line
		for( int i = 0, bitPos = 0, endLine = 0; i < BitmapLength; i++ )
		{
			if( Bitmap[bitPos] != '\n' )
			{
				// duplicate each bit
				Bitmap.insert( bitPos + 1, Bitmap.substr( bitPos, 1 ) );
				// adjust bitPos accordingly
				bitPos += 2;
			}
			// if we hit end of line
			else if( Bitmap[bitPos] == '\n' )
			{
				// duplicate the line
				Bitmap.insert( bitPos + 1, Bitmap.substr( endLine, bitPos - endLine + 1 ) );
				// adjust bitPos (must account for entirely new added line), endLine
				bitPos += bitPos - endLine + 2;
				endLine = bitPos;
			}
		}

		// adjust Zoom
		Zoom = Zoom * 2;
	}

	// notify user of error
	else
	{
		cout << "Sorry, you can only zoom in to x4" << endl << endl;
	}
}

// Zoom out after zooming in
void BitmapPicture::ZoomOut()
{
	// verify Zoom is x2 or x4
	if( Zoom == 2 || Zoom == 4 )
	{
		// traverse through bitmap via i, use endLine to keep track of end of prev line
		for( unsigned int i = 0, endLine = 0; i < Bitmap.length(); i++ )
		{
			if( Bitmap[i] != '\n' )
			{
				// erase duplicate bit
				Bitmap.erase( i + 1, 1 );
			}
			// if we hit end of line
			else if( Bitmap[i] == '\n' )
			{
				// erase next line, length will be (i - endLine)*2 + 1 to account for zoomed out length and '\n' character
				Bitmap.erase( i + 1, ( i - endLine ) * 2 + 1 );
				// adjust endLine
				endLine = i + 1;
			}
		}

		// adjust Zoom
		Zoom = Zoom/2;
	}

	// notify user of error
	else
	{
		cout << "Sorry, you cannot zoom out any further" << endl << endl;
	}
}

// Rotate clockwise 90 degrees
void BitmapPicture::RotateCW()
{

}

// Rotate counter-clockwise 90 degrees
void BitmapPicture::RotateCCW()
{

}

// Flip the bits in the bitmap, turning on those that were off and vice versa
void::BitmapPicture::Invert()
{
	for( unsigned int i = 0; i < Bitmap.length(); i++ )
	{
		// if there is an x, replace it with a space
		if( Bitmap[i] == 'x' )
		{
			Bitmap[i] = ' ';
		}

		// if there is a space, replace it with an x
		else if( Bitmap[i] == ' ' )
		{
			Bitmap[i] = 'x';
		}
	}
}