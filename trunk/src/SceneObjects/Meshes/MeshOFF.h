/**
 * Simple vertex / face format, no texture coordinates
 */

#ifndef meshoff_h
#define meshoff_h

#include "Mesh.h"

class MeshOFF : public Mesh
{
public:
	MeshOFF(const string& filename)
	{
		read(filename);
	}

	void read(const string& filename)
	{
		fstream in;
		int numVertices, numFaces, numEdges;
		string format;

		try
		{
			float x, y, z;
			int order, a, b, c, d;

			in.open(filename.c_str(), std::ios::in);
			if (in.fail() || in.eof()) {
				cout << "Opening " << filename << " failed." << endl;
				return;
			}

			in >> format;
			in >> numVertices >> numFaces >> numEdges;

			for (int i = 0; i < numVertices; i++) {
				in >> x >> y >> z;
				vertices.push_back(Position3(x, y, z));
			}

			for (int i = 0; i < numFaces; i++) {
				in >> order;
				if (order == 4) {
					in >> a >> b >> c >> d;
					faces.push_back(Face(a, b, c, d));
				}
				else if (order == 3) {
					in >> a >> b >> c;
					faces.push_back(Face(a, b, c));
				}
			}
		} catch (exception& e) {
			cout << e.what() << endl;
		}
	}
};

#endif
