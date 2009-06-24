#ifndef kdtree_h
#define kdtree_h

#include <vector>
#include "Position3.h"

using std::vector;

// we can embed this, we'll never need a kdnode without a kdtree
class KDNode
{
public:
	Position3 position;

	KDNode *rightChild;
	KDNode *leftChild;

	KDNode(Position3 pos)
	{
		position = pos;
	}
};


class KDTree
{
private:
	enum { X, Y, Z };

	KDNode root;
public:

	KDTree(vector<Position3>& points)
	{
		root = constructTree(points, 0);
	}

	KDNode getRoot()
	{
		return root;
	}

	KDNode constructTree(vector<Position3>& points, int depth)
	{
		if (points.empty())
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
		KDNode node(points.at(half));

		vector<Position3> left(points.begin(), points.begin() + half);
		vector<Position3> right(points.begin() + half, points.end());

		node.leftChild = constructTree(left, depth + 1);
		node.rightChild = constructTree(right, depth + 1);

		return node;
	}

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
};

#endif
