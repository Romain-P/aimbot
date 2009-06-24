#ifndef KDTree_h
#define KDTree_h

#include "Vector3.h"
#include "Position3.h"
#include "Node.h"
#include "../Algo/MergeSort.h"
#include <vector>

using std::vector;

class KDTree
{
public:


	KDTree (vector<Position3*> pointList, int length, int depth)
	{
		Node* root = new Node();
		constructTree(pointList, length, depth, root);
	}

	static Node constructTree(vector<Position3*> pointList, int length, int depth, Node*& node)
	{


		if (length == 0)
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

			//Create node sand subtrees
			Position3* median = pointList.at(length/2);
			node.setPoint(median);


			//vector<Position3*> firstHalf(pointList.begin(), pointList.begin() + length/2);
			//vector<Position3*> secondHalf(pointList.begin()+ length/2, pointList.end());

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

			KDTree(firstHalf, length/2, depth++, node.leftChild);
			KDTree(secondHalf, length/2, depth++, node.rightChild);

			return node;
		}
	}

	static bool vectorSortX(const Position3& a, const Position3& b)
	{
		return a.x < b.x;
	}

	static bool vectorSortY(const Position3& a, const Position3& b)
	{
		return a.y < b.y;
	}

	static bool vectorSortZ(const Position3& a, const Position3& b)
	{
		return a.z < b.z;
	}


};

#endif
