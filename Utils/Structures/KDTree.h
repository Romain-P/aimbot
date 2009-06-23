#ifndef KDTree_h
#define KDTree_h

#include "Vector3.h"
#include "../Algo/MergeSort.h"

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

			int axisNum = depth % 3;
			char axis = null;
			switch (axisNum){

				case 0:
					axis = x;
				case 1:
					axis = y;
				case 2:
					axis = z;
			}


			for(int i = 0; i < length; i++)
			{

			}

			//Sort the list and get the median
			Algorithms::mergeSort();
			Vector3 median = null;

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

			return Node;
		}
	}

};

#endif
