#ifndef kdtree_h
#define kdtree_h

#include <vector>
#include <iostream>
#include "Position3.h"

using std::vector;
using std::cout;
using std::endl;

class KDNode
{
public:
	Position3 position;

	KDNode *leftChild;
	KDNode *rightChild;

	KDNode(Position3 pos)
	{
		position = pos;
		leftChild = NULL;
		rightChild = NULL;
	}
};


class KDTree
{
private:
	vector<Position3>* localPoints;
	enum { X, Y, Z };

	static bool sortX(const Position3& a, const Position3& b)
	{
		return a.x < b.x;
	}

	static bool sortY(const Position3& a, const Position3& b)
	{
		return a.y < b.y;
	}

	static bool sortZ(const Position3& a, const Position3& b)
	{
		return a.z < b.z;
	}


public:
	KDNode* root;

	KDTree(const vector<Position3>& points)
	{
		localPoints = new vector<Position3>(points.begin(), points.end());
		root = constructTree(*localPoints, 0);
	}
	~KDTree()
	{
		destroy();
	}

	KDNode* constructTree(vector<Position3>& points, int depth)
	{
		if (points.size() <= 1)
			return NULL;

		switch (depth % 3)
		{
			case X:
				sort(points.begin(), points.end(), sortX);
				break;
			case Y:
				sort(points.begin(), points.end(), sortY);
				break;
			case Z:
				sort(points.begin(), points.end(), sortZ);
				break;
		}

		int half = points.size() / 2;
		KDNode* node = new KDNode(points.at(half));

		vector<Position3> left(points.begin(), points.begin() + half);
		vector<Position3> right(points.begin() + half, points.end());

		node->leftChild = constructTree(left, depth + 1);
		node->rightChild = constructTree(right, depth + 1);

		return node;
	}

	Position3& closestPoint(const Position3& point)
	{
		KDNode* node = root;

		float distance = 0;
		float leftDist = 0;
		float rightDist = 0;

		while(true)
		{
			distance = node->position.dist(point);
			if(node->leftChild != NULL && node->rightChild != NULL)
			{
				leftDist = node->leftChild->position.dist(point);
				rightDist = node->rightChild->position.dist(point);

				if(leftDist < distance)
					node = node->leftChild;
				else if(rightDist < distance)
					node = node->rightChild;
				else
					return node->position;
			}
			else
				return node->position;
		}
	}

	void destroy()
	{
		struct local {
			static void deleteNode(KDNode* node) { delete node; }
		};
		traverse(local::deleteNode, root);
	}

	vector<Position3> getTraversal()
	{
		static vector<Position3> temp;
		temp.clear();
		struct local {
			static void pushNode(KDNode* node) { temp.push_back(node->position); }
		};
		traverse(local::pushNode, root);
		return temp;
	}

	/**
	 * @param operate -- pointer to function which takes a node and
	 * 					 performs some operation with it. This means
	 * 					 we don't have to rewrite a local bst traversal for
	 * 					 each of several possible operations on nodes.
	 * @param node -- pointer to KDNode
	 * @awesomeness -- > 9000
	 */
	void traverse(void(*operate)(KDNode* node), KDNode* node)
	{
		if(node->leftChild == NULL && node->rightChild == NULL)
		{
			(*operate)(node);
			return;
		}

		if(node->leftChild != NULL)
			traverse(operate, node->leftChild);
		if(node->rightChild != NULL)
			traverse(operate, node->rightChild);
	}


	void printOut(vector<Position3>& points)
	{
		cout << "x: ";
		for(unsigned int i = 0; i < points.size(); i++)
			cout << points.at(i).x << " ";
		cout << endl << "y: ";
		for(unsigned int i = 0; i < points.size(); i++)
			cout << points.at(i).y << " ";
		cout << endl << "z: ";
		for(unsigned int i = 0; i < points.size(); i++)
			cout << points.at(i).z << " ";
		cout << endl << endl << endl;
	}
};

#endif
