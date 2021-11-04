

/*�������ö������ĸ��ڵ� p �� q ����дһ���������������������Ƿ���ͬ��
����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�*/


/*
    1. �����ǵݹ鷽ʽ�ɽ�
    2. �ݹ�
*/


#include <iostream>
#include "define.h"

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        else if (p == nullptr || q == nullptr)
        {
            return false;
        }

        if (p->val != q->val)
        {
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

};

//int main()
//{
//	Solution s;
//    TreeNode* rootp = constructTree();
//    TreeNode* rootq = constructTree();
//    bool bresult = s.isSameTree(rootp, rootq);
//
//    std::cout << bresult << std::endl;
//    
//	return 0;
//}