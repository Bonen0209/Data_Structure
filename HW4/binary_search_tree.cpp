//BinarySearchTree.cpp

#include "binary_search_tree.h"
#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

//Member functions
void BinarySearchTree::insert(int d) {
	tree_node *t = new tree_node;
	tree_node *parent;

	t->data = d;
	t->left = NULL;
	t->right = NULL;
	parent = NULL;

	//Check the new tree
	if (isEmpty()) { 
		root = t; 
	}
	else {
		//ALL insertions are as leaf nodes
		tree_node *curr;
		curr = root;

		// Find the Node's parent
		while (curr) {
			parent = curr;

			//Check the data
			if (t->data > curr->data) { 
				curr = curr->right; 
			}
			else { 
				curr = curr->left; 
			}
		}

		//Assign the pointer
		if (t->data < parent->data) {
			parent->left = t;
		}
		else {
			parent->right = t;
		}
	}
}


//Print functions
void BinarySearchTree::print_inorder() {
	inorder(root);
}

void BinarySearchTree::inorder(tree_node *p) {
	if (p != NULL) {
		if (p->left) {
			inorder(p->left);
		}

		cout << " " << p->data << " ";
		
		if (p->right) {
			inorder(p->right);
		}
	}
}

void BinarySearchTree::print_preorder() {
	preorder(root);
}

void BinarySearchTree::preorder(tree_node *p) {
	if (p != NULL) {
		cout << " " << p->data << " ";
		
		if (p->left) {
			preorder(p->left);
		}

		if (p->right) {
			preorder(p->right);
		}
	}
}

void BinarySearchTree::print_postorder() {
	postorder(root);
}

void BinarySearchTree::postorder(tree_node *p) {
	if (p != NULL) {
		if (p->left) {
			postorder(p->left);
		}

		if (p->right) {
			postorder(p->right);
		}

		cout << " " << p->data << " ";
	}
}

void BinarySearchTree::print_tree() {
	tree(root, 1);
}

void BinarySearchTree::tree(tree_node *p, int level) {
	if (p != NULL) {
		tree(p->right, level + 1);
		cout << endl;

		if (p == root) {
			cout << "Root->:  ";
		}
		else {
			for (int i = 0; i < level; i++) {
				cout << "       ";
			}
		}

		cout << p->data;
		tree(p->left, level + 1);
	}
}

void BinarySearchTree::print_bfs() {
	queue<tree_node *> q;

	if (!root) {
		return;
	}
	for (q.push(root); !q.empty(); q.pop()) {
		const tree_node * const temp_node = q.front();
		cout << " " << temp_node->data << " ";

		if (temp_node->left) {
			q.push(temp_node->left);
		}
		if (temp_node->right) {
			q.push(temp_node->right);
		}
	}
}
