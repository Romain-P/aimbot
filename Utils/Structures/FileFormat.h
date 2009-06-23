/*
 * Base class for objects that will need to be written to files
 */

#ifndef fileformat_h
#define fileformat_h

#include <vector>
#include <string>
#include <fstream>

using std::vector;
using std::string;
using std::fstream;

class FileAttribute
{
public:
	int numBytes;
	char* data;
	bool bigEndian;

	FileAttribute(int bytes, char* dat, bool endian = false) :
		numBytes(bytes), data(dat), bigEndian(endian)
	{
	}
};

class FileFormat
{
	string filename;
	fstream in;
	fstream out;
	vector<FileAttribute> attributes;

	FileFormat(string& name) :
		filename(name)
	{
	}

	void read()
	{
		in.open(filename.c_str(), std::ios::in);
		for (unsigned int i = 0; i < attributes.size(); i++) {
			out.read(attributes.at(i).data, attributes.at(i).numBytes);
		}
	}
	void write()
	{
		out.open(filename.c_str(), std::ios::out);
		for (unsigned int i = 0; i < attributes.size(); i++) {
			out.write(attributes.at(i).data, attributes.at(i).numBytes);
		}
		out.close();
	}
};

#endif
