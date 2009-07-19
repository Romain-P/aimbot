#ifndef kdtree_h
#define kdtree_h

#include <vector>
#include <iostream>
#include <algorithm>
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

class KDPair
{
public:
	KDNode* node;
	float dist;

	KDPair(KDNode* n, float d) : node(n), dist(d) {}
	bool operator<(const KDPair& other) const
	{
		return dist < other.dist;
	}
	inline bool operator==(const KDPair& other) const
	{
		return node == other.node;
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

	vector<KDPair> findNearest(
		const Position3& target,
		int kNearest)
	{
		static vector<KDPair> nearest;
		nearest.clear();

		struct local {
			static void checkNearest(
				KDNode* node,
				const Position3& target,
				unsigned int kNearest)
			{
				float dist = target.dist2(node->position);
				if(nearest.size() < kNearest || dist < nearest.back().dist)
				{
					KDPair pair(node, dist);
					vector<KDPair>::iterator it = find(nearest.begin(), nearest.end(), pair);
					if(it == nearest.end() || nearest.size() == 0)
						nearest.push_back(pair);

					sort(nearest.begin(), nearest.end());

					if(nearest.size() > kNearest)
						nearest.pop_back();
				}
			}
			static void nearestNode(
				KDNode* node,
				const Position3& target,
				unsigned int kNearest,
				int depth)
			{
				int axis = depth % 3;
				KDNode* nearer, *further;
				if(node->leftChild == NULL && node->rightChild == NULL) {
					checkNearest(node, target, kNearest);
					return;
				}
				if(node->rightChild == NULL ||
					node->leftChild != NULL &&
					target[axis] <= node->position[axis])
				{
					nearer = node->leftChild;
					further = node->rightChild;
				} else {
					nearer = node->rightChild;
					further = node->leftChild;
				}

				nearestNode(nearer, target, kNearest, depth + 1);

				if(further != NULL)
				{
					float dist = target[axis] - node->position[axis];
					if(nearest.size() < kNearest || dist * dist < nearest.back().dist)
						nearestNode(further, target, kNearest, depth + 1);
				}
				checkNearest(node, target, kNearest);
			}
		};

		local::nearestNode(root, target, kNearest, 0);

		return nearest;
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
