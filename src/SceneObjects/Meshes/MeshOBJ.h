/*
 * Vertex / face format with texture coordinates and simple materials
 */

#ifndef meshobj_h
#define meshobj_h

#include <string>
#include <sstream>
#include "Mesh.h"
#include "../../Input/ImageReader.h"
#include "../../Utils/Misc/Tokenizer.h"
#include "../../Utils/Structures/Position2.h"
#include "../../Utils/Structures/Vector3.h"

using std::string;
using std::fstream;
using std::stringstream;

// obj files indices start from 1 :C
class TexFace : public Face
{
public:
	int texIndices[4];

	TexFace(int a, int b, int c, int d,
			int e, int f, int g, int h) : Face(a -1, b - 1, c - 1, d - 1)
	{
		texIndices[0] = e - 1;
		texIndices[1] = f - 1;
		texIndices[2] = g - 1;
		texIndices[3] = h - 1;
	}

	TexFace(int a, int b, int c,
			int d, int e, int f) : Face(a - 1, b - 1, c - 1 )
	{
		texIndices[0] = d - 1;
		texIndices[1] = e - 1;
		texIndices[2] = f - 1;
	}
};


class MeshOBJ : public Mesh
{
private:
	vector<Position2> texCoords;
	vector<Vector3> normals;
	vector<TexFace> texFaces;
	vector<int> normIndices;

	float tx, ty;
	float x, y, z;
	int a, b, c, d;
	bool haveNormals;
	bool haveTexCoords;

	void processLine(const string& str)
	{
		string first;
		stringstream ss;

		ss << str;
		ss >> first;

		if (first == "v")
		{
			ss >> x >> y >> z;
			vertices.push_back(Position3(x, y, z));
		}
		else if (first == "vt")
		{
			haveTexCoords = true;
			ss >> tx >> ty;
			texCoords.push_back(Position2(tx, ty));
		}
		else if (first == "vn")
		{
			haveNormals = true;
			ss >> x >> y >> z;
			normals.push_back(Vector3(x, y, z));
		}
		else if(first == "f")
		{
			static int num = 1 + int(haveNormals) + int(haveTexCoords);
			parseIndices(str, num);
		}
	}

	// face indices are in format: f v1/t1/n v2/t2/n v3/t3/n ... vi/ti/n
	void parseIndices(const string& str, int numCoordTypes)
	{
		Tokenizer tokens(str, " /");

		//absorb the 'f'
		tokens.nextToken();

		vector<int> ind = tokens.getInts();

		int numVerts = ind.size() / numCoordTypes;
		if(numVerts == 3)
		{
			texFaces.push_back(TexFace(
					ind.at(numCoordTypes * 0),
					ind.at(numCoordTypes * 1),
					ind.at(numCoordTypes * 2),
					ind.at(numCoordTypes * 0 + 1),
					ind.at(numCoordTypes * 1 + 1),
					ind.at(numCoordTypes * 2 + 1)));
			normIndices.push_back(ind.at(2));
		}
		else if(numVerts == 4)
		{
			texFaces.push_back(TexFace(
					ind.at(numCoordTypes * 0),
					ind.at(numCoordTypes * 1),
					ind.at(numCoordTypes * 2),
					ind.at(numCoordTypes * 3),
					ind.at(numCoordTypes * 0 + 1),
					ind.at(numCoordTypes * 1 + 1),
					ind.at(numCoordTypes * 2 + 1),
					ind.at(numCoordTypes * 3 + 1)));
			normIndices.push_back(ind.at(2));
		}
		else
		{
			cout << "Irregular polygon of order " << numVerts << endl;
		}
	}

public:
	int textureID;

	MeshOBJ()
	{
		haveNormals = false;
		haveTexCoords = false;
	}

	void read(const string& filename)
	{
		fstream in;

		try
		{

			in.open(filename.c_str(), std::ios::in);
			if (in.fail() || in.eof()) {
				cout << "Opening " << filename << " failed." << endl;
				return;
			}

			string line;
			while (getline(in, line)) {
				processLine(line);
			}


		} catch (exception& e)
		{
			cout << e.what() << endl;
		}

	}

	void loadTexture(const string& filename)
	{
		textureID = ImageReader::loadTexture(filename);
	}

	vector<TexFace>& getTexFaces()
	{
		return texFaces;
	}

	vector<Position2>& getTexCoords()
	{
		return texCoords;
	}

};

#endif
