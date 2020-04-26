#pragma once
#include <iostream>
using namespace std;

class Tree;//forward declaration

class TreeNode
{
	friend class Tree;//allows Tree to use TreeNode's private member
public:
	TreeNode();//default constrcutor
	TreeNode(int);//constructor with given key
	~TreeNode();//destructor
	void printInfo();
private:
	TreeNode* parent;
	TreeNode* leftchild;
	TreeNode* rightchild;
	int key; 
	int address; //the address of the node in the tree
	int depth;

};