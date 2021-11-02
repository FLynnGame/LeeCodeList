#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static TreeNode* constructTree() {
	TreeNode* root = new TreeNode(1);
	TreeNode* temp = root;

	temp->left = new TreeNode(2);
	temp->right = new TreeNode(3);

	TreeNode* right = temp->right;
	temp = temp->left;
	temp->left = new TreeNode(4);
	temp->right = new TreeNode(5);

	right->left = new TreeNode(6);
	right->right = new TreeNode(7);
	/*temp->left = new TreeNode(4);
	temp->right = new TreeNode(3);
	temp->right->right = new TreeNode(2);*/

	return root;
}

