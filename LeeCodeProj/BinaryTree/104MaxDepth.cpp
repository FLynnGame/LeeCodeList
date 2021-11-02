

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#include "define.h"

using namespace std;

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

private:
	int nAnswer = 0;
};

//int main()
//{
//	Solution s;
//	TreeNode* root = constructTree();
//	int a = s.maxDepth(root);
//	return 0;
//}