//BinarySearchTree.h

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <cstdlib>

using namespace std;

class BinarySearchTree {
private:
	struct tree_node {
		tree_node *left;
		tree_node *right;
		int data;
	};
	tree_node *root;

public:
	//Constructor
	BinarySearchTree() {
		root = NULL;
	}

	//Member functions
	bool isEmpty() const { 
		return root == NULL; 
	}
	void insert(int);

	//Print functions
	void print_inorder();
	void inorder(tree_node *);
	void print_preorder();
	void preorder(tree_node *);
	void print_postorder();
	void postorder(tree_node *);
	void print_tree();
	void tree(tree_node *, int);
	void print_bfs();
};

#endif