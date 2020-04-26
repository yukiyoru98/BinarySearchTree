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

/*#pragma once
#include "TreeNode.h"
#include <queue>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Tree
{
public:
	Tree();
	Tree(vector<int>);
	~Tree();
	
	//members
	int depth;
	int num_of_nodes;
	TreeNode* root;
	queue<TreeNode*> bfs_queue;

	//functions
	void Insert(int);//insert a TreeNode with a given value
	//void Delete();//delete last node
	void Preorder(TreeNode*);//start Preorder Traversal from the given node
	void Postorder(TreeNode*);//start Postorder Traversal  from the given node
	void Inorder(TreeNode*);//start Inorder Traversal from the given node
	void BFS(TreeNode*);//start BFS from the given node
	void printBFS(TreeNode*);
	void printTree();
	void printInfo();
};

*/