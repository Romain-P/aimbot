#ifndef mesh_h
#define mesh_h

#include <math.h>
#include <iostream>
#include <vector>
#include <fstream>
#include "../Graphics/GraphicIncludes.h"
#include "../Utils/Vector3.h"

using namespace std;

class VertexID
{
public:
	int vertIndex;
	int normIndex;
};

class Face
{
public:
	int nVerts;
	VertexID * verts;
	Face()
	{
		nVerts = 0;
		verts = NULL;
	}
	~Face()
	{
  		delete [] verts;
  		nVerts = 0;
  	}
};

class Mesh
{
private:
	bool useSmoothNormals;
	std::vector<Face*>* getConnectedFaces(int vIndex);
	Vector3 getSmoothNormal(std::vector<Face*>* vFaces);
	Vector3* getNormal(vector<int>* indices, vector<Vector3*>* v);

public:
	int numVerts;
	int numNormals;
	int numFaces;
	Vector3* points;
	Vector3* flatNorms;
	Vector3* smoothNorms;
	Face* faces;

	Mesh();
	~Mesh();
	int readFile(string filename);
	void generateSmoothNormals();
	void readSmoothNormals(string filename);
	void writeMesh(string filename);
	void writeNormFile(string filename);
	void readRawFile(string filename);
	int getVertIndex(Vector3* vertex, vector<Vector3*>* coords);
	void print();
};

#endif