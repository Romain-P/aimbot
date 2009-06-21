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
		FileAttribute header(8, (char*)"MAP_");
		FileAttribute filesize(4, (char*)totalBytes);
	}

	void read()
	{

	}

	void write()
	{

	}
};

#endif
