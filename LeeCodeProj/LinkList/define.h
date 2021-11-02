#pragma once

#include <iostream>
#include <vector>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

static ListNode* constructLinkList(std::vector<int> ivec) {
	ListNode* head = new ListNode(ivec[0]);
	ListNode* itor = head;
	for (size_t i = 1; i < ivec.size(); i++)
	{
		ListNode* temp = new ListNode(0);
		temp->val = ivec[i];
		itor->next = temp;
		itor = itor->next;
	}
	return head;
}

static void printLinkList(ListNode* head) {
	ListNode* pHead = head;
	while (nullptr != pHead)
	{
		std::cout << pHead->val << std::endl;
		pHead = pHead->next;
	}
}
