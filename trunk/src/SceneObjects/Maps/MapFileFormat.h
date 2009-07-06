#ifndef mapfileformat_h
#define mapfileformat_h

#include "../../Utils/Structures/FileFormat.h"
#include "../Maps/Map.h"
#include "../Meshes/Mesh.h"

class MapFileFormat : public FileFormat
{
private:
	Mesh** meshes;
public:
	MapFileFormat()
	{
		attributes.push_back(FileAttribute(8, (char*)"MAP_"));
		attributes.push_back(FileAttribute(4, (char*)totalBytes));

		//
	}
};

#endif
