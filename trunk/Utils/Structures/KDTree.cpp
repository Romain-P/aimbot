#include "KDTree.h"


/*

//I was debugging with this in a separate project
//just start it up (with gdb) and observe what happens, the base
//case is fuckign stuff up with the right branches

------

x: 3 7 6 5 0 5 4 2 9 6 7 1 0 4 2 7 5 3 9 6
y: 1 4 1 5 9 2 6 5 3 5 8 9 7 9 3 2 3 8 4 6
z: 2 6 4 3 3 8 3 2 7 9 5 0 2 8 8 4 1 9 7 1

x: 0 0 1 2 2 3 3 4 4 5
y: 9 7 9 5 3 1 8 6 9 5
z: 3 2 0 2 8 2 9 3 8 3

x: 3 2 2 5 4
y: 1 3 5 5 6
z: 2 8 2 3 3

x: 3 2
y: 1 5
z: 2 2

x: 2
y: 5
z: 2

x:
y:
z:

x: 2
y: 5
z: 2

x:
y:
z:

x: 2
y: 5
z: 2


---------





#include "KDTree.h"
#include <cmath>

int main()
{
	int x[] = { 3, 7, 6, 5, 0, 5, 4, 2, 9, 6, 7, 1, 0, 4, 2, 7, 5, 3, 9, 6 };
	int y[] = { 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6 };
	int z[] = { 2, 6, 4, 3, 3, 8, 3, 2, 7, 9, 5, 0, 2, 8, 8, 4, 1, 9, 7, 1 };
	vector<Position3> points;
	for(int i = 0; i < 20; i++)
		points.push_back(Position3(x[i], y[i], z[i]));
	KDTree tree(points);
	KDNode* node = tree.root;


	return 0;
}



 */
