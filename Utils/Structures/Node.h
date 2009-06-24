/*
 * Node.h
 *
 *  Created on: Jun 17, 2009
 *      Author: Corey
 */

#ifndef NODE_H_
#define NODE_H_

#include "Position3.h"

class Node
{



public:

	Position3 point;
	Node rightChild, leftchild;

	Node(Position3 point) {
		this->point = point;
	}

};

#endif /* NODE_H_ */
