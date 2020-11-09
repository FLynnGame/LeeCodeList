


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

int main()
{
	Solution s;
	TreeNode* root = s.constructTree();
	int a = s.hasPathSum(root, 22);
	return 0;
}