#include <iostream>

#include "define.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
		ListNode* pNext = node->next;
		ListNode* pNNext = pNext->next; // next->next
		node->val = pNext->val;
		node->next = pNNext;
    }
};

//int main() {
//	std::vector<int> ivec = { 4,5,1,9 };
//	ListNode* list = constructLinkList(ivec);
//	Solution s;
//	s.deleteNode(list->next);
//	printLinkList(list);
//
//	return 0;
//}