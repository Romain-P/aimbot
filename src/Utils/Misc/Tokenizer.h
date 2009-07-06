/**
 * Adapted from code by James Fancy
 *
 * TODO: see if we can eliminate redundant start/end calls
 */

#ifndef tokenizer_h
#define tokenizer_h

#include <string>
#include <cstdlib>

using std::string;

class Tokenizer
{
protected:
	int offset;
	string text;
	string delimiters;

public:
	Tokenizer(const string& str) :
		offset(0),
		text(str),
		delimiters(" \t\n\r")
    {
    }

	Tokenizer(const string& str, const string& del) :
		offset(0),
		text(str),
		delimiters(del)
	{
	}

	string nextToken()
	{
		unsigned int start = text.find_first_not_of(delimiters, offset);
		if(start == string::npos)
		{
			offset = text.length();
			return "";
		}

		unsigned int end = text.find_first_of(delimiters, start);
		if(end == string::npos)
		{
			offset = text.length();
			return text.substr(start);
		}

		offset = end;
		return text.substr(start, end - start);

	}

	float nextInt()
	{
		return atoi(nextToken().c_str());
	}

	float nextFloat()
	{
		return atof(nextToken().c_str());
	}

	bool hasMoreTokens()
	{
		unsigned int start = text.find_first_not_of(delimiters, offset);
		unsigned int end = text.find_first_of(delimiters, start);
		return start != string::npos && end != string::npos;
	}
};

#endif
