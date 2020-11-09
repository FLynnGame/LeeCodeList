
#include <algorithm>
#include <iostream>
#include <stack>

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
		nMinValue = INT_MAX;
	}

	void push(int x) {
		st1.push(x);
		nMinValue = std::min(nMinValue, x);
	}

	void pop() {
		int top = st1.top();
		if (top == nMinValue)
		{
			// 需要更新最小值
			nMinValue = INT_MAX;
			tempSt.empty();
			tempSt.push(top);
			st1.pop();

			while (false == st1.empty()) {
				top = st1.top();
				tempSt.push(top);
				st1.pop();
				nMinValue = std::min(nMinValue, top);
			}

			while (false == tempSt.empty())
			{
				st1.push(tempSt.top());
				tempSt.pop();
			}
			
		}

		st1.pop();
	}

	int top() {
		return st1.top();
	}

	int getMin() {
		return nMinValue;
	}

private:
	std::stack<int> st1;
	std::stack<int> tempSt;
	int nMinValue;
};


// 不用辅助栈，实现最小栈
// 栈里存储差值，实时更新最小值
// 通过最小值与差值，计算出栈的元素
class MinStackLight {
public:
	/** initialize your data structure here. */
	MinStackLight() {
		nMinValue = INT_MAX;
	}

	void push(int x) {
		if (st1.empty())
		{
			st1.push(0);
			this->nMinValue = x;
		}
		else {
			long long diff = (long long int)x - this->nMinValue;
			st1.push(diff);
			if (diff < 0) // 表示插入的元素比较小
			{
				this->nMinValue = x;
			}
		}
	}

	void pop() {
		long long diff = st1.top();
		if (diff < 0) { // 表示最小值被pop出了，需要更新最小值
			int top = this->nMinValue - diff;
			this->nMinValue = top;
		}
		st1.pop();
	}

	int top() {
		long long diff = st1.top();
		if (diff < 0)
		{
			return this->nMinValue;
		}
		else {
			return this->nMinValue + diff;
		}
	}

	int getMin() {
		return nMinValue;
	}

private:
	std::stack<long long int> st1;
	int nMinValue;
};


//int main()
//{
//	MinStackLight s;
//	s.push(2147483646);
//	s.push(2147483646);
//	s.push(2147483647);
//	//std::cout << s.getMin() << std::endl;
//	std::cout << s.top() << std::endl;
//	s.pop();
//	std::cout << s.getMin() << std::endl;
//	s.pop();
//	std::cout << s.getMin() << std::endl;
//	s.pop();
//	s.push(2147483647);
//	std::cout << s.top() << std::endl;
//	std::cout << s.getMin() << std::endl;
//	s.push(INT_MIN);
//	std::cout << s.top() << std::endl;
//	std::cout << s.getMin() << std::endl;
//	s.pop();
//	std::cout << s.getMin() << std::endl;
//
//	//std::cout << s.top() << std::endl;
//	//std::cout << s.getMin() << std::endl;
//
//
//	return 0;
//}