#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		while (false == qu1.empty())
		{
			qu2.push(qu1.front());
			qu1.pop();
		}

		qu1.push(x);

		while (false == qu2.empty())
		{
			qu1.push(qu2.front());
			qu2.pop();
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		if (qu1.empty()) { return -1; }
		int front = qu1.front();
		qu1.pop();
		return front;
	}

	/** Get the top element. */
	int top() {
		if (qu1.empty()) { return -1; }
		return qu1.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return qu1.empty(); 
	}

private:
	std::queue<int> qu1;
	std::queue<int> qu2;

};

// 基本思路 入队的时候，利用另一个，将元素入队到队首
// qu1基础存储，qu2辅助缓存

/**
* Your MyStack object will be instantiated and called as such:
* MyStack* obj = new MyStack();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->top();
* bool param_4 = obj->empty();
*/