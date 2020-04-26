#include "TreeNode.h"

TreeNode::TreeNode() //default constructor:key=0, address=1
	:parent(nullptr), leftchild(nullptr), rightchild(nullptr), key(0), address(1), depth(0)
{
}

TreeNode::TreeNode(int k) //constructor with given key, default address=1
	: parent(nullptr), leftchild(nullptr), rightchild(nullptr), key(k), address(1), depth(0)
{
}


TreeNode::~TreeNode() //destructor
{
}

void TreeNode::printInfo()
{
	if (this == nullptr) {
		cout << "NIL" << endl;
		return;
	}

	cout << "Key:" << key << endl;
	cout << "Depth:" << depth << "\t Address:" << address << endl;

	cout << "Parent:";
	if (parent != nullptr) {
		cout << parent->key << endl;
	}
	else {
		cout << "NIL" << endl;
	}

	cout << "Left:";
	if (leftchild != nullptr) {
		cout << leftchild->key << endl;
	}
	else {
		cout << "NIL" << endl;
	}

	cout << "Right:";
	if (rightchild != nullptr) {
		cout << rightchild->key << endl;
	}
	else {
		cout << "NIL" << endl;
	}

	cout << endl;
}
