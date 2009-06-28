#include "Mesh2.h"

Mesh2::Mesh2()
{
	numVerts = numFaces = numNormals = 0;
	points = NULL;
	flatNorms = NULL;
	faces = NULL;
	smoothNorms = NULL;
	useSmoothNormals = false;
}

Mesh2::~Mesh2()
{
	if(points) 		delete [] points;
	if(flatNorms) 	delete [] flatNorms;
	if(faces) 		delete [] faces;
	if(smoothNorms) delete [] smoothNorms;
}

int Mesh2::readFile(string filename)
{
	fstream infile;
	infile.open(filename.c_str(), std::ios::in);
	if(infile.fail() || infile.eof())
		return -1;

	infile >> numVerts >> numNormals >> numFaces;

	points = new Vector3[numVerts];
	flatNorms = new Vector3[numNormals];
	smoothNorms = new Vector3[numVerts];
	faces = new Face[numFaces];

	if( !points || !flatNorms || !faces)
		return -1;

	for(int point = 0; point < numVerts; point++)
		infile >> points[point].x >> points[point].y >> points[point].z;

	for(int normal = 0; normal < numNormals; normal++)
		infile >> flatNorms[normal].x >> flatNorms[normal].y >> flatNorms[normal].z;

	for(int face = 0; face < numFaces; face++) {
	   infile >> faces[face].nVerts;
	   int nv = faces[face].nVerts;

	   faces[face].verts = new VertexID[nv];

	   for(int i = 0; i < nv; i++)
		   infile >> faces[face].verts[i].vertIndex;
	   for(int i = 0; i < nv; i++)
		   infile >> faces[face].verts[i].normIndex;
	}

	return 0;
}

void Mesh2::writeMesh(string filename)
{
	if(numVerts == 0 || numNormals == 0 || numFaces == 0)
		return;
	fstream outStream(filename.c_str(), std::ios::out);
	if(outStream.fail()) {
		cout << "can't make new file: " << filename << endl;
		return;
	}
	outStream << numVerts << " " << numNormals << " " << numFaces << "\n";
	for(int i = 0; i < numVerts; i++)
		outStream << points[i].x << " " << points[i].y << " " << points[i].z << "\n";
	for(int i = 0; i < numNormals; i++)
		outStream  << flatNorms[i].x << " " << flatNorms[i].y << " " << flatNorms[i].z << "\n";
	for(int f = 0; f < numFaces; f++) {
		int n = faces[f].nVerts;
		outStream << n << "\n";
		for(int v = 0; v < n; v++)
		   outStream << faces[f].verts[v].vertIndex << " ";
		outStream << "\n";
		for(int k = 0; k < n; k++)
		   outStream << faces[f].verts[k].normIndex << " ";
		outStream << "\n";
	}
	outStream.close();
}

void Mesh2::writeNormFile(string filename)
{
	if(!smoothNorms) {
		std::cout << "No smooth normal array" << std::endl;
		return;
	}

	ofstream outfile(filename.c_str(), std::ios::out);
	for(int i = 0; i < numVerts; i++)
		outfile << smoothNorms[i].x << " " << smoothNorms[i].y << " " << smoothNorms[i].z << endl;
	outfile.close();
}

void Mesh2::readSmoothNormals(string filename)
{
	ifstream in(filename.c_str(), std::ios::in);
	if(in.fail())	return;
	useSmoothNormals = true;
	smoothNorms = new Vector3[numVerts];
	for(int i = 0; i < numVerts; i++)
		in >> smoothNorms[i].x >> smoothNorms[i].y >> smoothNorms[i].z;
}

//brute force n*m, n=#vertices m=#faces
void Mesh2::generateSmoothNormals()
{
	useSmoothNormals = true;
	smoothNorms = new Vector3[numVerts];
	for(int vIndex = 0; vIndex < numVerts; vIndex++) {
		std::vector<Face*>* vFaces = getConnectedFaces(vIndex);
		smoothNorms[vIndex] = getSmoothNormal(vFaces);
		delete vFaces;
	}
}

Vector3 Mesh2::getSmoothNormal(std::vector<Face*>* vFaces)
{
	Vector3 m(0);
	for(unsigned int face = 0; face < vFaces->size(); face++) {
		int nIndex = (*vFaces->at(face)).verts[0].normIndex;
		m += flatNorms[nIndex];
	}
	m.normalize();
	cout << m.print() << endl;
	return m;
}

std::vector<Face*>* Mesh2::getConnectedFaces(int vIndex)
{
	std::vector<Face*>* vFaces = new std::vector<Face*>;
	for(int face = 0; face < numFaces; face++) {
		for(int vert = 0; vert < faces[face].nVerts; vert++)
			if(faces[face].verts[vert].vertIndex == vIndex)
				vFaces->push_back(&faces[face]);
	}
	return vFaces;
}

void Mesh2::readRawFile(string filename)
{
	string input;
	stringstream sstream;

	vector<vector<int>*>* faceVertIndices = new vector<vector<int>*>();
	vector<Vector3*>* coords = new vector<Vector3*>();
	vector<Vector3*>* normals = new vector<Vector3*>();

	ifstream in(filename.c_str(), std::ios::in);
	if(in.fail())
		std::cout << "No raw file " + filename << std::endl;

	while(std::getline(in, input)) {
		vector<int>* fIndices = new vector<int>();
		sstream.str(input);
		Vector3 temp;
		while(sstream >> temp.x >> temp.y >> temp.z) {
			Vector3* vertex = new Vector3(temp);
			unsigned int index = getVertIndex(vertex, coords);
			if(index == coords->size())
				coords->push_back(vertex);
			fIndices->push_back(index);
		}
		sstream.clear();
		if(fIndices->size() == 0) {
			cout << "Failed to parse lines" << endl;
			return;
		}
		Vector3* normal = getNormal(fIndices, coords);
		normals->push_back(normal);
		faceVertIndices->push_back(fIndices);
	}

	numFaces = faceVertIndices->size();
	numVerts = coords->size();
	numNormals = normals->size();

	faces = new Face[numFaces];
	for(int i = 0; i < numFaces; i++) {
		faces[i].nVerts = faceVertIndices->at(i)->size();
		faces[i].verts = new VertexID[faces[i].nVerts];
		for(int j = 0; j < faces[i].nVerts; j++) {
			faces[i].verts[j].vertIndex = faceVertIndices->at(i)->at(j);
			faces[i].verts[j].normIndex = i;
		}
	}

	points = new Vector3[numVerts];
	for(int i = 0; i < numVerts; i++)
		points[i] = Vector3(*coords->at(i));

	flatNorms = new Vector3[numNormals];
	for(int i = 0; i < numNormals; i++)
		flatNorms[i] = Vector3(*normals->at(i));

	for(int i = 0; i < numFaces; i++)
		delete faceVertIndices->at(i);
	for(int i = 0; i < numVerts; i++)
		delete coords->at(i);
	for(int i = 0; i < numNormals; i++)
		delete normals->at(i);
	delete faceVertIndices;
	delete coords;
	delete normals;
}

int Mesh2::getVertIndex(Vector3* vertex, vector<Vector3*>* coords)
{
	int index = coords->size();
	for(unsigned int i = 0; i < coords->size(); i++)
		if(*coords->at(i) == *vertex)
			index = i;
	return index;
}

Vector3* Mesh2::getNormal(vector<int>* indices, vector<Vector3*>* v)
{
	int size = indices->size();
	Vector3* normal = new Vector3();
	for(int i = 0; i < size; i++) {
		int a = indices->at(i);
		int b = indices->at((i+1)%size);
		normal->x += (v->at(a)->y - v->at(b)->y) * (v->at(a)->z + v->at(b)->z);
		normal->y += (v->at(a)->z - v->at(b)->z) * (v->at(a)->x + v->at(b)->x);
		normal->z += (v->at(a)->x - v->at(b)->x) * (v->at(a)->y + v->at(b)->y);
	}
	normal->normalize();
	return normal;
}

void Mesh2::print()
{
	cout << "Address: " << this << endl;
	cout << "Faces: " << numFaces << endl;
	cout << "Verts: " << numVerts << endl;
	cout << "Normals: " << numNormals << endl;
}
