#ifndef node_h
#define node_h

#include "Position3.h"

class Node
{
public:

	Position3 point;
	Node *rightChild, *leftChild;

	Node()
	{
	}

	void setPoint(Position3& p)
	{
		point = p;
	}

};

#endif /* NODE_H_ */
