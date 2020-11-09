#include "define.h"


//面试题 02.02:实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。

class KthToLastSolution
{
public:
	KthToLastSolution(){}
	~KthToLastSolution(){}

public:
	int kthToLast(ListNode* head, int k)
	{
		// 第一步，先求长度
		int length = 0;
		ListNode* temp = head;
		while (temp->next != nullptr)
		{
			length++;
			temp = temp->next;
		}

		// 第二布，算出正向的位置，循环到此位置
		int nIndex = length - k + 1;
		temp = head;
		int nListLength = 0;
		while (temp != nullptr)
		{
			if (nListLength >= nIndex)
			{
				return temp->val;
			}
			nListLength++;
			temp = temp->next;
		}
		return 0;
	}

	ListNode* constructList()
	{
		ListNode* head = new ListNode(0);
		ListNode* itor = head;
		int length = 1;
		while (length > 0)
		{
			ListNode* temp = new ListNode(0);
			temp->val = 2 - length;
			itor->next = temp;
			itor = itor->next;
			length--;
		}
		return head;
	}
};


