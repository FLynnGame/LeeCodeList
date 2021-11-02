


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
			// �ƶ�����ǰ�ڵ�������
			while (nullptr != node)
			{
				iStack.push(node);
				iVec.push_back(node->val);
				node = node->left;
			}

			if (false == iStack.empty())
			{
				// �Ȼ�ȡջ�����ٽ���ɾ��
				// �����սڵ�Ͳ�����ջ������������ջ
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