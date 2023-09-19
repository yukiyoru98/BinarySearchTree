#pragma once
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include "TreeNode.h"

using namespace std;

class Tree
{
public:
	Tree(); //default constructor
	~Tree(); //destructor

	void BFS(queue<TreeNode*>&); //for convenience when printing the tree
	void Setup(); //setup the address and depth for all nodes, and also the height of the tree
	void printTree();

	//Tree Operations
	void Insert(TreeNode*);
	void Transplant(TreeNode*, TreeNode*);
	void Delete(TreeNode*);
	TreeNode* IterativeTreeSearch(TreeNode*, int);
	TreeNode* Minimum(TreeNode*);
	TreeNode* Maximum(TreeNode*);
	TreeNode* Successor(TreeNode*);
	TreeNode* Predecessor(TreeNode*);

	//members
	int height;
	int num_of_nodes;
	TreeNode* root;
	

};
