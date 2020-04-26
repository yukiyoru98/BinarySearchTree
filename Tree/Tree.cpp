#include "Tree.h"

Tree::Tree()
	:height(0), root(nullptr), num_of_nodes(0)
{
}

Tree::~Tree()
{
}

void Tree::BFS(queue<TreeNode*> &BFS_Queue)
{
	queue<TreeNode*> tmp;
	TreeNode* x;

	tmp.push(root);//start from root
	while (!tmp.empty()) { //do until no more elements in queue
		x = tmp.front(); //get the front element in queue
		if (x != nullptr) {
			BFS_Queue.push(x); //put this node in BFS_Queue
			tmp.push(x->leftchild); //put left and right child in queue
			tmp.push(x->rightchild);
		}
		tmp.pop(); //pop the first element so as to continue processing the next element
	}
}

void Tree::Setup() {

	queue<TreeNode*> BFS_Queue;
	BFS(BFS_Queue);//do BFS first

	TreeNode* tmp;
	int newHeight = 0;

	tmp = BFS_Queue.front();
	
	while (!BFS_Queue.empty()) {
		tmp = BFS_Queue.front();
		if (tmp->parent == nullptr) { //root
			tmp->address = 1;
			tmp->depth = 0;
		}
		else {
			if (tmp == tmp->parent->leftchild) {
				tmp->address = tmp->parent->address * 2;
			}
			else {
				tmp->address = tmp->parent->address * 2 + 1;
			}
			tmp->depth = tmp->parent->depth + 1;
		}
		if (tmp->depth > newHeight) {
			newHeight = tmp->depth;
		}

		BFS_Queue.pop();
	}

	height = newHeight;
	
}

void Tree::printTree()
{
	queue<TreeNode*> BFS_Queue;
	BFS(BFS_Queue);//do BFS first

	TreeNode* ptr = BFS_Queue.front();
	int nodesPrinted = 1;
	int numOfDash = pow(2, height);
	int currentAddr = ptr->address;

	for (int k = 0; k < numOfDash-1; k++) {
		cout << "==";
	}
	cout << "TREE";
	for (int k = 0; k < numOfDash-1; k++) {
		cout << "==";
	}

	cout << "\nNumber of Nodes: " << num_of_nodes << "\nHeight: " << height << "\n\n";

	for (int i = 0; i <= height; i++) {
		for (int j = 0; j < pow(2, i); j++) {

			for (int k = 0; k < numOfDash; k++) {
				cout << "__";
			}
			if (currentAddr != nodesPrinted) {
				cout << "  ";
			}
			else {
				cout << setw(2) << ptr->key;
				BFS_Queue.pop();
				if (BFS_Queue.empty()) {
					currentAddr = -1;
				}
				else {
					ptr = BFS_Queue.front();
					currentAddr = ptr->address;
				}
			}
			for (int k = 0; k < numOfDash - 1; k++) {
				cout << "__";
			}

			nodesPrinted++;

		}
		numOfDash /= 2;
		cout << endl;
	}

	cout << endl;
}


void Tree::Insert(TreeNode *z)
{
	TreeNode* y = nullptr;
	TreeNode* x = root;
	
	while (x != nullptr) {
		y = x;
		if (z->key < x->key) { //z is smaller than x
			x = x->leftchild; //go to the left subtree
		}
		else { //z is larger than x
			x = x->rightchild; //go to the right subtree
		}
	} 
	//loop ends when x is nullptr, i.e. the previous x (which is y) will be the parent of z
	z->parent = y;
	if (y == nullptr) { //Tree is empty
		root = z; //z will be the root
		//the root address has already been defaulty set to 1 in the constructor of TreeNode
	}
	else if(z->key < y->key){ //z is smaller than y
		y->leftchild = z; //let z be left child
		z->address = y->address * 2; //address is 2*parent's address
		z->depth = y->depth + 1; //depth is parent's address+1
	}
	else { //z is larger than y
		y->rightchild = z; //let z be right child
		z->address = y->address * 2 + 1; //address is 2*parent's address +1
		z->depth = y->depth + 1; //depth is parent's address+1
	}

	//update the num of nodes and height of the tree
	num_of_nodes++;
	if (z->depth > height) {
		height++;
	}

}

void Tree::Transplant(TreeNode* r1, TreeNode* r2)
{
	//replace the subtree rooted at r1 as a child of its parent with the subtree rooted at r2
	
	if (r1 == root) { //r1 is the root of the whole tree
		root = r2; //r2 becomes the new root
	}
	
	//if r1 is not root
	//let r1's parent has r2 as its new child
	else if (r1 == r1->parent->leftchild) {
		r1->parent->leftchild = r2;
	}
	else {
		r1->parent->rightchild = r2;
	}

	//let r2 has r1's parent as its new parent
	if (r2 != nullptr) { //if r2 is not null
		r2->parent = r1->parent;
	}
	
}

void Tree::Delete(TreeNode* z)
{
	if (z == nullptr) {
		cout << "Key does not exists.\n";
		return;
	}
	//if z is lack of one child, then transplant the other child to z
	//NIL is transplanted if the other child is also missing
	if (z->leftchild == nullptr) { //no left child
		Transplant(z, z->rightchild);
	}
	else if (z->rightchild == nullptr) { //has left child but no right child
		Transplant(z, z->leftchild);
	}
	else { //z has two children
		
		//find the minimum node in the right subtree to take over z
		TreeNode* min = Minimum(z->rightchild);

		if (min != z->rightchild) { //if min is not a child of z
			Transplant(min, min->rightchild); //transplant min's right child to min first
			//let min has z's right child as its new right child
			min->rightchild = z->rightchild;
			//let z's right child has min as its new parent
			z->rightchild->parent = min;
		}
		//transplant min to z
		Transplant(z, min);
		//let min has z's left child as its new left child
		min->leftchild = z->leftchild;
		//let z's leftchild have min as its new parent
		z->leftchild->parent = min;
	}

	z->~TreeNode(); //call destructor to deallocate memory 

	num_of_nodes--;
	Setup(); //setup the address, depth and height in response to deletion
}

TreeNode* Tree::IterativeTreeSearch(TreeNode* x, int k) //start searching from x
{
	while (x != nullptr && x->key != k) { //not end of tree and key not found
		if (k < x->key) { //k is smaller than x, so should be in x's left subtree
			x = x->leftchild;
		}
		else { //k is larger than x, so should be in x's right subtree
			x = x->rightchild;
		}
	}

	if (x == nullptr) {
		cout << "Key does not exists.\n";
	}

	return x;
}

TreeNode* Tree::Minimum(TreeNode* x)
{
	while (x->leftchild != nullptr) {
		x = x->leftchild;
	}
	return x;
}

TreeNode* Tree::Maximum(TreeNode* x)
{
	while (x->rightchild != nullptr) {
		x = x->rightchild;
	}
	return x;
}

TreeNode* Tree::Successor(TreeNode* x)
{
	if (x->rightchild != nullptr) { //all nodes in x's right subtree are larger than x
		return Minimum(x->rightchild); //find the minimum node in right subtree
	}

	//if x has no right subtree
	TreeNode* y = x->parent;
	while (y != nullptr && x == y->rightchild) { //x is the larger than parent 
		x = y;
		y = y->parent;
	}
	//loop ends x is smaller than y
	//so y is x's successor

	return y;
	
}

TreeNode* Tree::Predecessor(TreeNode* x)
{
	if (x->leftchild != nullptr) {//all nodes in x's left subtree are smaller than x
		return Maximum(x->leftchild);//find the maximum node in left subtree
	}

	//if x has no left subtree
	TreeNode* y = x->parent;
	while (y != nullptr && x == y->leftchild) { //parent is larger than x
		x = y;
		y = y->parent;
	}
	//loop ends y is smaller than x
	return y; //parent is the predecessor
	
}
