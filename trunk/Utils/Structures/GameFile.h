/*
 * Base class for objects that will need to be written to files
 */

#ifndef gamefile_h
#define gamefile_h

#include <vector>
#include <string>
#include <fstream>

typedef char byte;

using std::vector;
using std::string;
using std::fstream;

class FileAttribute
{
	int fileOffset;
	int numBytes;
	bool bigEndian;
	byte* data;
};

class GameFile
{
	string filename;
	vector<FileAttribute> attributes;

	GameFile(string& name) :
		filename(name)
	{
	}

	virtual void read() throw() = 0;
	virtual void write() throw() = 0;
};

#endif
