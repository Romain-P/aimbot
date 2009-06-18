#ifndef KDTree_h
#define KDTree_h

#include "Vector3.h"

class KDTree
{
public:



	KDTree (Vector3 pointList[], ,int length, int depth)
	{
		constructTree(pointList, length, depth);
	}

	static Node constructTree(Vector3 pointList[], ,int length, int depth)
	{


		if (pointList == null)
		{
			// Base case, do nothing noamsayin
		}
		else
		{

			int axis = depth % 3;

			//Sort the list and get the median
			Vector3 median = null;
			for(int i =0; i < length;i++)
			{
				// you know how to quickly make a merge sort?
			}

			//Create node and subtrees
			Node node = new Node(median);

			Vector3 firstHalf[length/2];
			for(int i = 0; i < length/2; i++)
			{
				firstHalf[i] = pointList[i];
			}

			Vector3 secondHalf[length/2];
			for (int i = 0; i < length/2; i++)
			{
				secondHalf[i] = pointList[i + length/2];
			}

			Node.leftChild = KDTree(firstHalf, length/2, depth++);
			Node.rightChild = KDTree(secondHalf, length/2, depth++);

			return Node
		}
	}

};

#endif
