#include <iostream>
#include<cstdlib>

#include "BST.cpp"

using namespace std;

int main()
{
	int TreeKeys[16] = {50, 76, 23, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};
	BST myTree;

	cout << "Printing the tree in order \nBefore adding numbers\n";

	myTree.PrintInOrder();

	for (int i = 0; i < 16; i++) {
		myTree.AddLeaf(TreeKeys[i]);
	}

	cout << "Printing the tree in order\nAfter adding numbers\n";
	myTree.PrintInOrder();
	cout << endl;

	cout << "The smallest value in the tree is " << myTree.FindSmallest() << "\n";
	return 0;
}
