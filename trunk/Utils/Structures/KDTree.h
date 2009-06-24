#ifndef kdtree_h
#define kdtree_h

#include <vector>
#include "Position3.h"
#include "Node.h"

using std::vector;

class KDTree
{
public:

	KDTree (vector<Position3>& pointList, int length, int depth)
	{
		Node root;
		constructTree(pointList, length, depth, root);
	}

	Node constructTree(vector<Position3>& pointList, int length, int depth, Node& node)
	{
		int half = length / 2;

		if (length == 0)
		{
			// Base case, do nothing noamsayin
		}
		else
		{
			// Sort depending on which axis you are splitting on
			int axisNum = depth % 3;

			switch (axisNum)
			{
				case 0:
					sort(pointList.begin(), pointList.end(), sortX);
					break;
				case 1:
					sort(pointList.begin(), pointList.end(), sortY);
					break;
				case 2:
					sort(pointList.begin(), pointList.end(), sortZ);
					break;
			}

			//Create node sand subtrees
			Position3 median = pointList.at(half);
			node.setPoint(median);

			vector<Position3> firstHalf(pointList.begin(), pointList.begin() + half);
			vector<Position3> secondHalf(pointList.begin() + half, pointList.end());

			depth++;

			constructTree(firstHalf, half, depth, *(node.leftChild));
			constructTree(secondHalf, half, depth, *(node.rightChild));

			return node;
		}
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
