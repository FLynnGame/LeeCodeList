

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#include "define.h"

using namespace std;


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

};

//int main()
//{
//	Solution s;
//	TreeNode* root = constructTree();
//	int a = s.isSymmetric(root);
//	return 0;
//}