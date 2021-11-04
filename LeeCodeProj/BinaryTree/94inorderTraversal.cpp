
#include <iostream>
#include "define.h"

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (nullptr == root)
        {
            return ivec;
        }
        
        inorderTraversal(root->left);
        ivec.push_back(root->val);
        inorderTraversal(root->right);

        return ivec;
    }
private:
    vector<int> ivec;
};

//int main()
//{
//	Solution s;
//	TreeNode* root = constructTree();
//    vector<int> ivec = s.inorderTraversal(root);
//    for (size_t i = 0; i < ivec.size(); i++)
//    {
//        std::cout << ivec[i] << std::endl;
//    }
//	return 0;
//}