
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

/* ����ջʵ�ֶ���
*/

// ��ָ Offer 09
class CQueue {
public:
	CQueue() {

	}

	void appendTail(int value) {
		st1.push(value);
	}

	int deleteHead() {
		if (st1.empty())
		{
			return -1;
		}

		while (false == st1.empty())
		{
			st2.push(st1.top());
			st1.pop();
		}

		int nHead = st2.top();
		st2.pop();
		while (false == st2.empty())
		{
			st1.push(st2.top());
			st2.pop();
		}
		return nHead;
	}

private:
	std::stack<int> st1;
	std::stack<int> st2;

};

/**
* �򵥽ⷨ��st1���洢��st2������
* appendTail��ֱ�ӽ�st1����ҪdeleteHead���ȵ��뵽��һ��ջst2���ٵ�����
*/

/**
* Your CQueue object will be instantiated and called as such:
* CQueue* obj = new CQueue();
* obj->appendTail(value);
* int param_2 = obj->deleteHead();
*/

// 232
class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		st1.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (st2.empty())
		{
			while (false == st1.empty())
			{
				st2.push(st1.top());
				st1.pop();
			}
		}

		if (st2.empty())
		{
			return -1;
		}

		int front = st2.top();
		st2.pop();
		return front;
	}

	/** Get the front element. */
	int peek() {
		if (st2.empty())
		{
			while (false == st1.empty())
			{
				st2.push(st1.top());
				st1.pop();
			}
		}

		if (st2.empty())
		{
			return -1;
		}
		return st2.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return (st1.size() + st2.size()) == 0;
	}

private:
	std::stack<int> st1;
	std::stack<int> st2;
};

/**
* ���ֽⷨ�Ǹ����ף�st1���洢��st2������ж�
* ��st2Ϊ�յ�ʱ�򣬾Ͱ�st1�����ݵ���ȥ�������ֲ����µĶ��ж�
*/

/**
* Your MyQueue object will be instantiated and called as such:
* MyQueue* obj = new MyQueue();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->peek();
* bool param_4 = obj->empty();
*/
