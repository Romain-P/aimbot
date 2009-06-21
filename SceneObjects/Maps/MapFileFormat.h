#ifndef mapfileformat_h
#define mapfileformat_h

#include "../../Utils/Structures/FileFormat.h"
#include "../Mesh.h"

class MapFileFormat : public FileFormat
{
public:
	MapFileFormat()
	{
		int totalBytes = 0;
		attributes.push_back(FileAttribute(8, (char*)"MAP_"));
		attributes.push_back(FileAttribute(4, (char*)totalBytes));
	}
};

#endif
