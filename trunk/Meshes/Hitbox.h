#ifndef hitbox_h
#define hitbox_h

#include "Mesh.h"

class Hitbox
{
private:
	Mesh* hitboxMesh;
	Mesh* meshToSurround;

	Hitbox(Mesh* toSurround) : meshToSurround(toSurround)
	{
		calculatedSurroundingMesh();
	}

	void calculateSurroundingMesh()
	{
		// insert speedy argolizm ici
	}

};

#endif
