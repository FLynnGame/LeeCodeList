
#include "LinkListDefine.h"

class Solution {
public:

	// ��ת����
	// ��ת��ԭ�����ƻ������ط�ת�������
	ListNode* reverseLinkList(ListNode* head) {
		ListNode* prev = nullptr;
		
		while (head)
		{
			ListNode* temp = head->next;
			head->next = prev;
			prev = head;
			head = temp;
		}

		return prev;
	}

	// ����ָ����������е�
	ListNode* findMidNode(ListNode* head) {
		ListNode* fast = head, *slow = head;

		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		return slow;
	}

};

//int main() {
//	std::vector<int> ivec = { 1,2,3,4,5 };
//	ListNode* list = constructLinkList(ivec);
//
//	Solution s;
//	ListNode* mid = s.findMidNode(list);
//	ListNode* reverseList = s.reverseLinkList(list);
//
//	return 0;
//}