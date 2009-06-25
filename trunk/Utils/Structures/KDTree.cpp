#include "KDTree.h"
#include <cmath>

void treeTest()
{
	int x[] = { 3, 7, 6, 5, 0, 5, 4, 2, 9, 6, 7, 1, 0, 4, 2, 7, 5, 3, 9, 6 };
	int y[] = { 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6 };
	int z[] = { 2, 6, 4, 3, 3, 8, 3, 2, 7, 9, 5, 0, 2, 8, 8, 4, 1, 9, 7, 1 };

	vector<Position3> points;
	for(int i = 0; i < 20; i++)
		points.push_back(Position3(x[i], y[i], z[i]));

	KDTree tree(points);

	vector<Position3> traversal = tree.getTraversal();
	vector<Position3>::iterator it;

	for(it = traversal.begin(); it != traversal.end(); ++it)
		cout << it->print() << endl;
}
