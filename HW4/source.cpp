//HW4

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>
#include "binarySearchTree.h"

using namespace std;

vector<int> readFile(string);
vector<int> randomData(int);

int main() {
	int choice;

	cout << "Please choose the data from (1.file 2.random): ";
	cin >> choice;

	vector<int> data;

	//Decide the data source
	switch (choice)
	{
	case 1:
		data = readFile("data.txt");
		break;
	case 2:
		int number;

		cout << "Please input a number: ";
		cin >> number;

		data = randomData(number);
		break;
	default:
		break;
	}

	//Print the data
	cout << "data " << endl;
	for (int i = 0; i < data.size(); i++) {
		cout << " " << data[i] << " ";
	}
	cout << endl << endl;

	//Having Binary search tree
	BinarySearchTree BST;
	
	for (int i = 0; i < data.size(); i++) {
		BST.insert(data[i]);	//Build the Binary search tree
	}
	
	cout << "Binary Search Tree" << endl;
	BST.print_tree();
	cout << endl << endl;

	cout << "Preorder" << endl;
	BST.print_preorder();
	cout << endl << endl;

	cout << "Inorder" << endl;
	BST.print_inorder();
	cout << endl << endl;

	cout << "Postorder" << endl;
	BST.print_postorder();
	cout << endl << endl;

	cout << "Breadth First" << endl;
	BST.print_bfs();
	cout << endl;

	system("pause");
	return 0;
}

//Read file from txt
vector<int> readFile(string name) {
	vector<int> result;

	fstream file(name, ios::in);

	string line;
	while (getline(file, line, ' ')) {
		stringstream tempNumber(line);
		int number;

		tempNumber >> number;	//Transfer type
		result.push_back(number);
	}
	line.clear();

	return result;
}

//Create from random numbers
vector<int> randomData(int n) {
	set<int> tmp;
	vector<int> result;

	srand(time(NULL));

	while (tmp.size() < n) {
		tmp.insert(rand() % 99 + 1);	//Having random number between 1~99
	}

	result.assign(tmp.begin(), tmp.end());

	return result;
}
