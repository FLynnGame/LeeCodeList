

/*给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。*/


/*
    1. 遍历非递归方式可解
    2. 递归
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