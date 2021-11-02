
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#include "define.h"

using namespace std;

class Solution {
public:
	// ������� ��(��) ������
	// �ݹ�ʵ��
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

	// ������� �ǵݹ�
	vector<int> preorderTraversalNoRecursion(TreeNode* root) {
		iVec.clear();
		TreeNode* node = root;

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

		return iVec;
	}

	// ������� ��(��) �����
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

	// ��������ǵݹ�
	vector<int> inorderTraversalNoRecursion(TreeNode* root) {
		iVec.clear();
		TreeNode* node = root;

		while (false == iStack.empty() || nullptr != node)
		{
			// �ҵ�����
			while (nullptr != node)
			{
				iStack.push(node);
				node = node->left;
			}

			if (false == iStack.empty())
			{
				// ���ʸ��ڵ�
				node = iStack.top();
				iVec.push_back(node->val);
				iStack.pop();
			}

			node = node->right;
		}
		return iVec;
	}

	// ������� ��(��) ���Ҹ�
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

	// ��������ǵݹ�
	// ��Ҫ˼·�Ǽ�¼һ���ϴη��ʵĽڵ㣬ȷ��ʲôʱ����ܷ��ʸ��ڵ�
	vector<int> postorderTraversalNoRecursion(TreeNode* root) {
		iVec.clear();
		if (root == nullptr) {
			return iVec;
		}

		TreeNode* node = root;
		TreeNode* pCurNode, *pLastVisit;
		pCurNode = root;

		pLastVisit = nullptr;

		//��curnode�ƶ������������·�
		while (nullptr != pCurNode)
		{
			iStack.push(pCurNode);
			pCurNode = pCurNode->left;
		}

		while (false == iStack.empty())
		{
			//Ŀǰ�������������·�
			pCurNode = iStack.top();
			iStack.pop(); //  ��ջ��׼����������
			
			// һ�����ڵ㱻���ʵ�ǰ���ǣ��������������������������ʹ�
			if (pCurNode->right == nullptr || pCurNode->right == pLastVisit)
			{
				iVec.push_back(pCurNode->val);
				pLastVisit = pCurNode;
			}
			else // ������ڵ㻹���ܷ��ʣ�����Ҫ�ȷ�����������ͬʱ(���ڵ��ٴ���ջ)
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

	// ��������ǵݹ�
	// ʹ������ջʵ��
	// ˼·Ϊ������������(��-��-�� --> ��-��-��) �����Ǻ������������(���Ҹ�)
	/*�����ڵ�ѹ���һ��ջ
	�ӵ�һ��ջ�е���һ��Ԫ�أ�ѹ��ڶ���ջ
	Ȼ��ֱ𽫸ýڵ�����Һ���ѹ���һ��ջ
	�ظ�����2�Ͳ���3ֱ����һ��ջΪ��
	ִ�н������ڶ���ջ�оͱ��������нڵ�ĺ�����������������ν�Ԫ�شӵڶ���ջ�е������ɡ�*/
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

	// ��α���
	vector<vector<int>> levelOrderTraversal(TreeNode* root) {
		std::vector<std::vector<int>> iVvec;
		iVec.clear();

		if (nullptr == root) {
			return iVvec;
		}

		std::queue<TreeNode*> iQueue;
		iQueue.push(root);
		TreeNode* temp = root;

		// һά���鱣��
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

		// ���ղ㼶����
		while (false == iQueue.empty())
		{
			int count = iQueue.size(); // һ�������
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