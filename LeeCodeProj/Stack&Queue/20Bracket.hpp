
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution20 {
public:
	bool isValid(string s) {
		if (s.length() % 2 != 0) { return false; } // 奇数个肯定不匹配
		if (s.empty()) return true;

		stack<char> sk;
		for (size_t i = 0; i < s.length(); i++)
		{
			if (false == sk.empty())
			{
				char sTop = sk.top();
				if ((sTop == '(' && s[i] == ')') 
					|| (sTop == '[' && s[i] == ']')
					|| (sTop == '{' && s[i] == '}'))
				{
					sk.pop();
				}
				else 
				{
					sk.push(s[i]);
				}
			}
			else
			{
				sk.push(s[i]);
			}
		}

		if (sk.empty()) return true;
		else			return false;
	}
};

//int main()
//{
//	Solution20 s;
//	std::vector<std::string> vec;
//	std::string t = "()";
//	vec.push_back(t);
//
//	t = "()[]{}";
//	vec.push_back(t);
//
//	t = "(]";
//	vec.push_back(t);
//
//	t = "([)]";
//	vec.push_back(t);
//
//	t = "{[]}";
//	vec.push_back(t);
//
//	for (size_t i = 0; i < vec.size(); i++)
//	{
//		std::cout << s.isValid(vec[i]) << std::endl;
//	}
//	return 0;
//}
