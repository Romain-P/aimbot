/*
 * Vertex / face format with texture coordinates and simple materials
 */

#ifndef meshobj_h
#define meshobj_h

#include <string>
#include "Mesh.h"
#include "../../Utils/Misc/Tokenizer.h"
#include "../../Utils/Structures/Position2.h"
#include "../../Utils/Structures/Vector3.h"

using std::string;
using std::fstream;



class MeshOBJ : public Mesh
{
private:
	vector<Position2> texCoords;
	vector<Vector3> normals;
	vector<Face> texFaces;
	vector<int> normIndices;

	float tx, ty;
	float x, y, z;
	int a, b, c, d;
	bool haveNormals;
	bool haveTexCoords;


	// TODO: this is quick and fuckin dirty, if there are any regex libs,
	// 		 they would clean this up with supernatural vigour.
	void processLine(const fstream& in, const string& str)
	{
		string first;
		in >> first;

		if (first == "v")
		{
			in >> x >> y >> z;
			vertices.push_back(Position3(x, y, z));
		}
		else if (first == "vt")
		{
			haveTexCoords = true;
			in >> tx >> ty;
			texCoords.push_back(Position2(tx, ty));
		}
		else if (first == "vn")
		{
			haveNormals = true;
			in >> x >> y >> z;
			normals.push_back(Vector3(x, y, z));
		}
		else if(first == "f")
		{
			static int num = 1 + int(haveNormals) + int(haveTexCoords);
			parseIndices(in, str, num);
		}
	}

	// face indices are in format: f v1/t1/n1 v2/t2/n2 v3/t3/n3 ...
	void parseIndices(const fstream& in, const string& str, int num)
	{
		vector<int> ind;
		Tokenizer tkn(str, " /");
		tkn.nextToken(); // remove the 'f'

		while(tkn.hasMoreTokens())
		{
			for(int n = 0; n < num; n++)
				ind.push_back(tkn.nextInt());
		}
		int verts = ind.size() / numIndices;
		if(verts == 3)
		{
			faces.push_back(Face(
					ind.at(num * 0),
					ind.at(num * 1),
					ind.at(num * 2)));
			texFaces.push_back(Face(
					ind.at(num * 0) + 1,
					ind.at(num * 1) + 1,
					ind.at(num * 2) + 1));
			normIndices.push_back(ind.at(2));
		}
		else if(verts == 4)
		{
			faces.push_back(Face(
					ind.at(num * 0),
					ind.at(num * 1),
					ind.at(num * 2),
					ind.at(num * 3)));
			texFaces.push_back(Face(
					ind.at(num * 0) + 1,
					ind.at(num * 1) + 1,
					ind.at(num * 2) + 1,
					ind.at(num * 3) + 1));
			normIndices.push_back(ind.at(2));
		}
	}

public:
	MeshOBJ(const string& filename)
	{
		haveNormals = false;
		haveTexCoords = false;

		read(filename);
	}

	void read(const string& filename)
	{
		fstream in;
		int numVertices, numFaces, numEdges;
		string format;

		try
		{

			in.open(filename.c_str(), std::ios::in);
			if (in.fail() || in.eof())
			{
				cout << "Opening " << filename << " failed." << endl;
				return;
			}

			string line;
			while(getline(in, line))
			{
				processLine(in, line);
			}

		} catch (exception& e) {
			cout << e.what() << endl;
		}
	}
};

#endif
