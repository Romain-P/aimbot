/**
 * Adapted from code by James Fancy
 *
 * TODO: see if we can eliminate redundant start/end calls
 */

#ifndef tokenizer_h
#define tokenizer_h

#include <string>

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
		text(str),
		offset(0),
		delimiters(del)
	{
	}

	string nextToken()
	{
		int start = text.find_first_not_of(delimiters, offset);
		if(start == string::npos)
		{
			offset = text.length();
			return "";
		}

		int end = text.find_first_of(delimiters, start);
		if(end == string::npos)
		{
			offset = text.length();
			return text.substr(start);
		}

		offset = end;
		return text.substr(start, end - start);

	}

	bool hasMoreTokens()
	{
		int start = text.find_first_not_of(delimiters, offset);
		int end = text.find_first_of(delimiters, start);
		return start != string::npos && end != string::npos;
	}
};

#endif
