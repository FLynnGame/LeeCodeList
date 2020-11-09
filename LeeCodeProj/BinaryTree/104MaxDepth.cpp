

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
	int maxDepth(TreeNode* root) {
		return maxDepth(root, 0);
	}

	// 自顶向下
	int maxDepth(TreeNode* root, int nDepth) {
		if (nullptr == root)
		{
			nAnswer = std::max(nAnswer, nDepth);
			return 0;
		}

		maxDepth(root->left, nDepth + 1);
		maxDepth(root->right, nDepth + 1);

		return nAnswer;
	}

	// 自底向上
	/*int maxDepth(TreeNode* root) {
		if (root == nullptr)
		{
			return 0;
		}
		else {
			int left = maxDepth(root->left);
			int right = maxDepth(root->right);
			return std::max(left, right) + 1;
		}
	}*/

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

private:
	int nAnswer = 0;
};

//int main()
//{
//	Solution s;
//	TreeNode* root = s.constructTree();
//	int a = s.maxDepth(root);
//	return 0;
//}