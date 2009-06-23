#ifndef KDTree_h
#define KDTree_h

#include "Vector3.h"
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

	static Node constructTree(vector<Vector3*> pointList, ,int length, int depth)
	{


		if (pointList == null)
		{
			// Base case, do nothing noamsayin
		}
		else
		{

			int axisNum = depth % 3;
			switch (axisNum){

				case 0:
					axis = x;
				case 1:
					axis = y;
				case 2:
					axis = z;
			}

			//Sort the list and get the median
			sort(pointList.begin(), pointList.end(), vectorSort);
			Vector3 median = pointList.at(length/2);

			//Create node and subtrees
			Node node = new Node(median);

			vector<Vector3*> firstHalf;
			for(int i = 0; i < length/2; i++)
			{
				firstHalf.at(i) = pointList.at(i);
			}

			vector<Vector3*> secondHalf;
			for (int i = 0; i < length/2; i++)
			{
				secondHalf.at(i) = pointList.at(i + length/2);
			}

			Node.leftChild = KDTree(firstHalf, length/2, depth++);
			Node.rightChild = KDTree(secondHalf, length/2, depth++);

			return Node;
		}
	}

	static bool vectorSort(const Vector3& a, const Vector3& b)
	{

		switch(axis)
		{
			case y:
				return a.y < b.y;
			case z:
				return a.z < b.z;
		}
		return a.x < b.x;

	}



};

#endif
