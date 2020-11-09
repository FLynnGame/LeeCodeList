

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr)
		{
			return true;
		}
		else if (root->left == nullptr && root->right == nullptr)
		{
			return true;
		}
		else if (root->left != nullptr && root->right != nullptr)
		{
			if (root->left->val == root->right->val)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		return isSymmetric(root->left) && isSymmetric(root->right);
	}

	TreeNode* constructTree() {
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
};

//int main()
//{
//	Solution s;
//	TreeNode* root = s.constructTree();
//	int a = s.isSymmetric(root);
//	return 0;
//}