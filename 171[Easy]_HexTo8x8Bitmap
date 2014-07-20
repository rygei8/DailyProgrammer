// Name:	Hex to 8x8 Bitmap
// Author:	Ryan Geiger
// Date:	7/20/14

#include <iostream>
#include <string>
using namespace std;

string hexToBitmap( string hex );

int main()
{
	// Testing
	cout << hexToBitmap( "18 3c 7E 7e 18 18 18 18" );

	return 0;
}

string hexToBitmap( string hex )
{
	string bitmap = "";

	for( unsigned int i = 0; i < hex.length(); i++ )
	{
		hex[i] = toupper( hex[i] );

		switch( hex[i] )
		{
			case '0': bitmap += "    "; break;
			case '1': bitmap += "   x"; break;
			case '2': bitmap += "  x "; break;
			case '3': bitmap += "  xx"; break;
			case '4': bitmap += " x  "; break;
			case '5': bitmap += " x x"; break;
			case '6': bitmap += " xx "; break;
			case '7': bitmap += " xxx"; break;
			case '8': bitmap += "x   "; break;
			case '9': bitmap += "x  x"; break;
			case 'A': bitmap += "x x "; break;
			case 'B': bitmap += "x xx"; break;
			case 'C': bitmap += "xx  "; break;
			case 'D': bitmap += "xx x"; break;
			case 'E': bitmap += "xxx "; break;
			case 'F': bitmap += "xxxx"; break;
			case ' ': bitmap += "\n"; break;
			default: break;
		}
	}

	return bitmap;
}
