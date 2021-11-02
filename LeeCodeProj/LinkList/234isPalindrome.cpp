
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
	bool isPalindrome(ListNode* head) {

		// ����1��ȡ��������������
	    // ռ���˶���Ĵ洢 n�Ŀռ临�Ӷȣ�n��ʱ�临�Ӷ�

		// ����2��ֱ��ȡ����ĵڼ������� n^2��ʱ�临�Ӷ�

		// ����3��ʹ�ÿ���ָ�룬�ҵ��е㡣��ת��벿��������ͷ���е㿪ʼ�Ƚ��Ƿ���ͬ
		ListNode* fast = head, *slow = head, *midHead = nullptr;
		// ����ָ�����е�
		// ���� slow=�е�+1 12345 slow=4
		// ż�� slow=�к�� 1234  slow=3
		while (fast) {
			slow = slow->next;
			fast = fast->next == nullptr ? fast->next : fast->next->next;
		}

		// ��תslow��ͷ������
		while (slow) {
			ListNode* temp = slow->next;
			slow->next = midHead;
			midHead = slow;
			slow = temp;
		}

		// ѭ���Ƚ��Ƿ���ͬ
		while (head && midHead) {
			if (head->val != midHead->val) {
				return false;
			}

			head = head->next;
			midHead = midHead->next;
		}

		return true;
	}
};

//int main() {
//	std::vector<int> ivec = { 1,2,3 };
//	ListNode* list = constructLinkList(ivec);
//	Solution s;
//	bool bResult = s.isPalindrome(list);
//
//	return 0;
//}