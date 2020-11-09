
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class Solution1047 {
public:
	string removeDuplicates(string S) {
		std::stack<char> stack;
		for (size_t i = 0; i < S.length(); i++)
		{
			if (false == stack.empty())
			{
				char cTop = stack.top();
				if (cTop == S[i]) {
					stack.pop();
					continue;
				}
			}
			stack.push(S[i]);
		}
		std::string sResult = "";
		while (false == stack.empty())
		{
			sResult += stack.top();
			stack.pop();
		}
		std::reverse(sResult.begin(), sResult.end());
		return sResult;
	}
};

