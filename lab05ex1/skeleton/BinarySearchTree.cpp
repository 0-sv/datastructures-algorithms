//=====================================================================
// FILE: BinarySearchTree.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: <Sebastiaan Verbeek>
// MATRIC NO.  : <A0174730H>
// NUS EMAIL   : <e0215432@u.nus.edu>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#include <cstdlib>
#include "BinarySearchTree.h"
#include <iostream>
using namespace std;


BinarySearchTree::BinarySearchTree()
	: _root(NULL) {
}

BinarySearchTree::~BinarySearchTree() = default;

bool BinarySearchTree::isEmpty() {
	return _root == NULL;
}

void BinarySearchTree::insert(int elem) {
	TreeNode* newNode = new TreeNode(elem);

	if (isEmpty()) {
		_root = newNode;
	}
	else {
		TreeNode* nodePtr = _root;

		// Traverse to the correct node. 
		traversal(nodePtr, newNode);

		// Insertion. 
		if (newNode->getElement() > nodePtr->getElement()) {
			nodePtr->setRightChild(newNode);
		}
		else {
			nodePtr->setLeftChild(newNode);
		}
		nodePtr = NULL;
		delete nodePtr; 
	}
}

int BinarySearchTree::findMin() {
	// Simply keep opening nodes on the left until the maximal element is found.
	TreeNode* nodePtr = _root;
	if (isEmpty())
		return 0;
	else {
		while (nodePtr->getLeftChild() != NULL) {
			nodePtr = nodePtr->getLeftChild();
		}
	}
	return nodePtr->getElement();

	nodePtr = NULL;
	delete nodePtr;
}

int BinarySearchTree::findMax() {
	// Simply keep opening nodes on the right until the maximal element is found.
	TreeNode* nodePtr = _root;
	if (isEmpty()) {
		return 0;
	}
	else {
		while (nodePtr->getRightChild() != NULL) {
			nodePtr = nodePtr->getRightChild();
		}
	}
	return nodePtr->getElement();

	nodePtr = NULL;
	delete nodePtr;
}

int BinarySearchTree::findDepth(int elem) {
	// Handle empty and root case. 
	if (isEmpty())
		return 0; 
	if (elem == _root->getElement())
		return 1;
	
	// Traverse to the correct node. 
	TreeNode* nodePtr = _root;
	TreeNode* newNode = new TreeNode(elem);

	traversal(nodePtr, newNode); 
	if (elem == nodePtr->getElement())
		return _depth;
	else
		return 0; 
	
	nodePtr = NULL;
	delete nodePtr;
}


// This method is called by insert() and findDepth()
// Insert uses this method to update the ptr until it points to the node where insertion may take place.
// findDepth uses this method to keep track of the private variable "depth". 
void BinarySearchTree::traversal(TreeNode*& ptr, TreeNode* nodeCheck) {
	_depth = 1;
	while (1) {
		// Check if the ptr is already at the correct node.
		if (ptr->getElement() == nodeCheck->getElement())
			return; 
		else if (nodeCheck->getElement() > ptr->getElement()) {
			if (ptr->getRightChild() != NULL) {
				ptr = ptr->getRightChild();
				++_depth;
			}
			else 
				return;
		}
		else {
			if (ptr->getLeftChild() != NULL) {
				ptr = ptr->getLeftChild();
				++_depth;
			}
			else 
				return;
		}
	}
}
