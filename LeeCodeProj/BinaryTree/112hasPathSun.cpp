


#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#include "define.h"

using namespace std;

class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		//iVec.clear();
		TreeNode* node = root;
		std::stack<TreeNode*> iStack;
		std::vector<int> iVec;

		while (false == iStack.empty() || nullptr != node)
		{
			// 移动到当前节点的最左端
			while (nullptr != node)
			{
				iStack.push(node);
				iVec.push_back(node->val);
				node = node->left;
			}

			if (false == iStack.empty())
			{
				// 先获取栈顶，再进行删除
				// 这样空节点就不会入栈，就能连续退栈
				node = iStack.top();
				iStack.pop();
				node = node->right;
			}
		}

		return false;
	}
};

//int main()
//{
//	Solution s;
//	TreeNode* root = constructTree();
//	int a = s.hasPathSum(root, 22);
//	return 0;
//}