#ifndef KDTree_h
#define KDTree_h

#include "Vector3.h"
#include "Position3.h"
#include "../Algo/MergeSort.h"
#include <vector>

using std::vector;

class KDTree
{
public:

	char axis = null;

	KDTree (vector<Vector3*> pointList, ,int length, int depth)
	{
		constructTree(pointList, length, depth);
	}

	static Node constructTree(vector<Position3*> pointList, ,int length, int depth, Node node)
	{


		if (pointList == null)
		{
			// Base case, do nothing noamsayin
		}
		else
		{

			// Sort depending on which axis you are splitting on
			int axisNum = depth % 3;
			switch (axisNum){

				case 0:
					sort(pointList.begin(), pointList.end(), vectorSortX);
					break;
				case 1:
					sort(pointList.begin(), pointList.end(), vectorSortY);
					break;
				case 2:
					sort(pointList.begin(), pointList.end(), vectorSortZ);
					break;
			}

			//Create node and subtrees
			Position3 median = pointList.at(length/2);
			node = median;

			vector<Position3*> firstHalf;
			for(int i = 0; i < length/2; i++)
			{
				firstHalf.at(i) = pointList.at(i);
			}

			vector<Position3*> secondHalf;
			for (int i = 0; i < length/2; i++)
			{
				secondHalf.at(i) = pointList.at(i + length/2);
			}

			node.leftChild = KDTree(firstHalf, length/2, depth++);
			node.rightChild = KDTree(secondHalf, length/2, depth++);

			return Node;
		}
	}

	static bool vectorSortX(const Vector3& a, const Vector3& b)
	{
		return a.x < b.x;
	}

	static bool vectorSortY(const Vector3& a, const Vector3& b)
	{
		return a.y < b.y;
	}

	static bool vectorSortZ(const Vector3& a, const Vector3& b)
	{
		return a.z < b.z;
	}


};

#endif
