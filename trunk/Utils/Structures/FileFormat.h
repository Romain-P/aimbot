/*
 * Base class for objects that will need to be written to files
 */

#ifndef fileformat_h
#define fileformat_h

#include <vector>
#include <string>
#include <fstream>

typedef char byte;

using std::vector;
using std::string;
using std::fstream;

class FileAttribute
{
	int numBytes;
	bool bigEndian;
	byte* data;

public:
	FileAttribute(int bytes, byte* dat, bool endian = false) :
		numBytes(bytes),
		data(dat),
		bigEndian(endian)
	{
	}
};

class FileFormat
{
	string filename;
	vector<FileAttribute> attributes;

	FileFormat(string& name) :
		filename(name)
	{
	}

	virtual void read() throw() = 0;
	virtual void write() throw() = 0;
};

#endif
