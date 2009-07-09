#ifndef imagereader_h
#define imagereader_h

// get the zip at http://www.lonesock.net/soil.html
// SOIL.h -> include dir, libSOIL.a -> lib dir
// don't forget to link to it in the project, and before the ogl libs

#include <SOIL.h>
#include <string>
#include "../Utils/Misc/Tokenizer.h"

using std::string;

class ImageReader
{
public:
	static int loadTexture(const string& filename)
	{
		return SOIL_load_OGL_texture
		(
			filename.c_str(),
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_INVERT_Y
		);
	}
};

#endif
