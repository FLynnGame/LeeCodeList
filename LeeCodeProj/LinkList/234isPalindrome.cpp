
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

		// 方法1：取出来，放数组里
	    // 占用了额外的存储 n的空间复杂度，n的时间复杂度

		// 方法2：直接取链表的第几个数据 n^2的时间复杂度

		// 方法3：使用快慢指针，找到中点。反转后半部分链表。从头，中点开始比较是否相同
		ListNode* fast = head, *slow = head, *midHead = nullptr;
		// 快慢指针找中点
		// 奇数 slow=中点+1 12345 slow=4
		// 偶数 slow=中后点 1234  slow=3
		while (fast) {
			slow = slow->next;
			fast = fast->next == nullptr ? fast->next : fast->next->next;
		}

		// 反转slow开头的链表
		while (slow) {
			ListNode* temp = slow->next;
			slow->next = midHead;
			midHead = slow;
			slow = temp;
		}

		// 循环比较是否相同
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