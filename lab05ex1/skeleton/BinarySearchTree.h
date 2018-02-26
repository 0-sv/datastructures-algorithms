//=====================================================================
// FILE: BinarySearchTree.h
//=====================================================================

//=====================================================================
// STUDENT NAME: <Sebastiaan Verbeek>
// MATRIC NO.  : <A0174730H>
// NUS EMAIL   : <e0215432@u.nus.edu>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include "TreeNode.h"


class BinarySearchTree {
private:
    TreeNode* _root;  // Pointer to the root node of the BST.
	void traversal(TreeNode*& ptr, TreeNode* newNode);
	int _depth;
public:
    BinarySearchTree();
	~BinarySearchTree(); 
    bool isEmpty();
    void insert(int elem);
    int findMin();
    int findMax();
    int findDepth(int elem);

    // Add more if necessary.
	
};

#endif
