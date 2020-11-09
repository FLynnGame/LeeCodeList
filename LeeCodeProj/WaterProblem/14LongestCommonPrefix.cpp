
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution14 {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() <= 0) {
			return "";
		}

		// 查找最短的字符串长度
		// 挨个比较字符就可以了
		int nShortest = shortestLength(strs);
		for (size_t i = 0; i < nShortest; i++)
		{
			char ch = strs[0][i];
			for (size_t j = 0; j < strs.size(); j++)
			{
				if (ch != strs[j][i])
				{
					return strs[0].substr(0, i);
				}
			}
		}
		return strs[0].substr(0, nShortest);
	}

	int shortestLength(vector<string>& strs) {
		if (strs.size() <= 0) {
			return 0;
		}

		int nShortest = INT_MAX;
		for (size_t i = 0; i < strs.size(); i++) {
			if (strs[i].length() < nShortest) {
				nShortest = strs[i].length();
			}
		}
		return nShortest;
	}
};

//int main()
//{
//	Solution14 s;
//	vector<string> vec = {"aa", "a"};
//	std::cout << s.longestCommonPrefix(vec);
//	return 0;
//}