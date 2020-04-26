#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <iostream>
#include <fstream>
#include "Tree.h"
#include <windows.h>
#include <limits>

using namespace std;

void clear(); //cleans the screen

int main() {

	Tree T;

	//=====Read Input File=====
	ifstream Read("input.txt", ios::in);
	//check if input file exists
	if (!Read.is_open()) {
		cerr << "Input File Does Not Exist.";
		exit(1);
	}
	//read num of keys
	int n = 0;
	Read >> n;
	//read input keys
	for (int i = 0; i < n; i++) {
		int k = 0;
		Read >> k; //read key from input file
		T.Insert(new TreeNode(k)); //insert node into Tree
	}

	//Perform Operations on user's demand
	int choice = -1;
	
	while (1) {
		T.printTree();
		cout << "(1)Insert\n(2)Delete\n(3)Search\n(4)Minimum\n(5)Maximum\n(6)Successor\n(7)Predecessor\n(0)Exit\n";
		cout << "Please enter your next step(1~7): " << endl;

		cin >> choice;
		while (cin.fail() || choice < 0 || choice > 7) {//check if input is illegal
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please try again...\n";
			cin >> choice;
		}

		switch (choice)
		{
		case 0: //exit
			return 0;
			break;

		case 1: //Insert
		{
			cout << "Enter the key to insert: ";
			int insert_k;
			cin >> insert_k;
			while (cin.fail()) {//check if input is illegal
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter an integer...\n";
				cin >> insert_k;
			}
			T.Insert(new TreeNode(insert_k));
		}
			break;

		case 2: //Delete
		{
			cout << "Enter the key to delete: ";
			int delete_k;
			cin >> delete_k;
			while (cin.fail()) {//check if input is illegal
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter an integer...\n";
				cin >> delete_k;
			}
			T.Delete(T.IterativeTreeSearch(T.root, delete_k));
		}
			break;

		case 3: //Search
		{
			cout << "Enter the key to search: ";
			int search_k;
			cin >> search_k;
			while (cin.fail()) {//check if input is illegal
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter an integer...\n";
				cin >> search_k;
			}

			TreeNode* search = T.IterativeTreeSearch(T.root, search_k);
			if (search != nullptr) {
				cout << "=====================\n";
				cout << "Key found at:\n";
				search->printInfo();
				cout << "=====================\n";
			}
		}
			break;

		case 4: //Minimum
		{
			cout << "\n[Minimum] searches for the minimum element in a subtree.\n";
			cout << "Enter the key of the subtree's root : ";
			int min_k;
			cin >> min_k;
			while (cin.fail()) {//check if input is illegal
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter an integer...\n";
				cin >> min_k;
			}
			
			TreeNode* search = T.IterativeTreeSearch(T.root, min_k);
			if (search != nullptr) {
				TreeNode* min = T.Minimum(search);
				cout << "=====================\n";
				cout << "Minimum Key found at:\n";
				min->printInfo();
				cout << "=====================\n";
			}
		}
			break;
			
		case 5: //Maximum
		{
			cout << "\n[Maximum] searches for the maximum element in a subtree.\n";
			cout << "Enter the key of the subtree's root : ";
			int max_k;
			cin >> max_k;
			while (cin.fail()) {//check if input is illegal
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter an integer...\n";
				cin >> max_k;
			}
			TreeNode* search = T.IterativeTreeSearch(T.root, max_k);
			if (search != nullptr) {
				TreeNode* max = T.Maximum(search);
				cout << "=====================\n";
				cout << "Maximum Key found at:\n";
				max->printInfo();
				cout << "=====================\n";
			}
		}
			break;

		case 6: //Successor
		{
			cout << "Enter the key to search for successor: ";
			int suc_k;
			cin >> suc_k;
			while (cin.fail()) {//check if input is illegal
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter an integer...\n";
				cin >> suc_k;
			}

			TreeNode* search = T.IterativeTreeSearch(T.root, suc_k);
			if (search != nullptr) {
				TreeNode* suc = T.Successor(search);
				cout << "=====================\n";
				cout << "Successor found at:\n";
				suc->printInfo();
				cout << "=====================\n";
			}
		}
			break;

		case 7: //Predecessor
		{
			cout << "Enter the key to search for predecessor: ";
			int pre_k;
			cin >> pre_k;
			while (cin.fail()) {//check if input is illegal
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter an integer...\n";
				cin >> pre_k;
			}
			TreeNode* search = T.IterativeTreeSearch(T.root, pre_k);
			if (search != nullptr) {
				TreeNode* pre = T.Predecessor(search);
				cout << "=====================\n";
				cout << "Predecessor found at:\n";
				pre->printInfo();
				cout << "=====================\n";
			}
			
		}
			break;

		default:
			break;
		}
		cout << "\nEnter any key to continue.";
		cin.ignore();
		cin.get();
		clear();
	}

	return 0;
}


void clear() {
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}