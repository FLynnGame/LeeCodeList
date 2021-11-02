
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#include "define.h"

using namespace std;

class Solution {
public:
	// 先序遍历 先(根) 根左右
	// 递归实现
	vector<int> preorderTraversal(TreeNode* root) {
		if (root != nullptr)
		{
			iVec.push_back(root->val);
			std::cout << root->val << std::endl;

			preorderTraversal(root->left);
			preorderTraversal(root->right);
		}
		return iVec;
	}

	// 先序遍历 非递归
	vector<int> preorderTraversalNoRecursion(TreeNode* root) {
		iVec.clear();
		TreeNode* node = root;

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

		return iVec;
	}

	// 中序遍历 中(根) 左根右
	vector<int> inorderTraversal(TreeNode* root) {
		if (root != nullptr)
		{
			inorderTraversal(root->left);

			iVec.push_back(root->val);
			std::cout << root->val << std::endl;

			inorderTraversal(root->right);
		}
		return iVec;
	}

	// 中序遍历非递归
	vector<int> inorderTraversalNoRecursion(TreeNode* root) {
		iVec.clear();
		TreeNode* node = root;

		while (false == iStack.empty() || nullptr != node)
		{
			// 找到最左
			while (nullptr != node)
			{
				iStack.push(node);
				node = node->left;
			}

			if (false == iStack.empty())
			{
				// 访问根节点
				node = iStack.top();
				iVec.push_back(node->val);
				iStack.pop();
			}

			node = node->right;
		}
		return iVec;
	}

	// 后序遍历 后(根) 左右根
	vector<int> postorderTraversal(TreeNode* root) {
		if (root != nullptr)
		{
			postorderTraversal(root->left);
			postorderTraversal(root->right);

			iVec.push_back(root->val);
			std::cout << root->val << std::endl;
		}
		return iVec;
	}

	// 后序遍历非递归
	// 主要思路是记录一个上次访问的节点，确定什么时候才能访问根节点
	vector<int> postorderTraversalNoRecursion(TreeNode* root) {
		iVec.clear();
		if (root == nullptr) {
			return iVec;
		}

		TreeNode* node = root;
		TreeNode* pCurNode, *pLastVisit;
		pCurNode = root;

		pLastVisit = nullptr;

		//把curnode移动到左子树最下方
		while (nullptr != pCurNode)
		{
			iStack.push(pCurNode);
			pCurNode = pCurNode->left;
		}

		while (false == iStack.empty())
		{
			//目前在左子树的最下方
			pCurNode = iStack.top();
			iStack.pop(); //  退栈，准备看右子树
			
			// 一个根节点被访问的前提是，无右子树，或者右子树被访问过
			if (pCurNode->right == nullptr || pCurNode->right == pLastVisit)
			{
				iVec.push_back(pCurNode->val);
				pLastVisit = pCurNode;
			}
			else // 如果根节点还不能访问，就需要先访问右子树，同时(根节点再次入栈)
			{
				iStack.push(pCurNode);
				pCurNode = pCurNode->right;
				while (nullptr != pCurNode)
				{
					iStack.push(pCurNode);
					pCurNode = pCurNode->left;
				}
			}
		}

		return iVec;
	}

	// 后序遍历非递归
	// 使用两个栈实现
	// 思路为反向的先序遍历(根-左-右 --> 根-右-左) 正好是后序遍历的逆序(左右根)
	/*将根节点压入第一个栈
	从第一个栈中弹出一个元素，压入第二个栈
	然后分别将该节点的左右孩子压入第一个栈
	重复步骤2和步骤3直到第一个栈为空
	执行结束，第二个栈中就保存了所有节点的后序遍历输出结果。依次将元素从第二个栈中弹出即可。*/
	vector<int> postorderTraversalNoRecursion_2Stack(TreeNode* root) {
		iVec.clear();
		if (root == nullptr) {
			return iVec;
		}
		std::stack<TreeNode*> result;
		iStack.push(root);

		while (false == iStack.empty())
		{
			TreeNode* temp = iStack.top();
			iStack.pop();

			result.push(temp);

			if (nullptr != temp->left)
			{
				iStack.push(temp->left);
			}
			if (nullptr != temp->right)
			{
				iStack.push(temp->right);
			}
		}

		while (false == result.empty())
		{
			TreeNode* node = result.top();
			iVec.push_back(node->val);
			result.pop();
		}

		return iVec;
	}

	// 层次遍历
	vector<vector<int>> levelOrderTraversal(TreeNode* root) {
		std::vector<std::vector<int>> iVvec;
		iVec.clear();

		if (nullptr == root) {
			return iVvec;
		}

		std::queue<TreeNode*> iQueue;
		iQueue.push(root);
		TreeNode* temp = root;

		// 一维数组保存
		/*while (false == iQueue.empty())
		{
			temp = iQueue.front();
			iQueue.pop();
			iVec.push_back(temp->val);

			if (nullptr != temp->left) {
				iQueue.push(temp->left);
			}

			if (nullptr != temp->right)
			{
				iQueue.push(temp->right);
			}
		}*/

		// 按照层级保存
		while (false == iQueue.empty())
		{
			int count = iQueue.size(); // 一层的数量
			std::vector<int> tvec;
			while (count > 0)
			{
				temp = iQueue.front();
				iQueue.pop();
				tvec.push_back(temp->val);

				if (nullptr != temp->left) {
					iQueue.push(temp->left);
				}
				if (nullptr != temp->right) {
					iQueue.push(temp->right);
				}

				count--;
			}
			iVvec.push_back(tvec);
		}
		return iVvec;
	}

private:
	std::vector<int> iVec;
	std::stack<TreeNode*> iStack;
};

//int main()
//{
//	Solution s;
//	TreeNode* root = constructTree();
//	/*std::vector<int> ivec = s.preorderTraversal(root);
//	std::vector<int> ivec2 = s.preorderTraversalNoRecursion(root);*/
//
//	/*std::vector<int> ivec = s.inorderTraversal(root);
//	std::vector<int> ivec2 = s.inorderTraversalNoRecursion(root);*/
//
//	/*std::vector<int> ivec = s.postorderTraversal(root);
//	std::vector<int> ivec2 = s.postorderTraversalNoRecursion(root);
//	std::vector<int> ivec3 = s.postorderTraversalNoRecursion_2Stack(root);*/
//
//	std::vector<std::vector<int>> ivec = s.levelOrderTraversal(root);
//	
//
//	return 0;
//}