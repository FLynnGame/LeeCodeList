#include "define.h"


//������ 02.02:ʵ��һ���㷨���ҳ����������е����� k ���ڵ㡣���ظýڵ��ֵ��

class KthToLastSolution
{
public:
	KthToLastSolution(){}
	~KthToLastSolution(){}

public:
	int kthToLast(ListNode* head, int k)
	{
		// ��һ�������󳤶�
		int length = 0;
		ListNode* temp = head;
		while (temp->next != nullptr)
		{
			length++;
			temp = temp->next;
		}

		// �ڶ�������������λ�ã�ѭ������λ��
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


