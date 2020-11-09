
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	// �������
	/*int lengthOfLongestSubstring(string s) {
		int nMax = 0;
		std::unordered_map<char,int> unorderMap;
		for (size_t i = 0; i < s.length(); i++)
		{
			unorderMap.clear();
			unorderMap[s[i]]++;
			for (size_t j = i + 1; j < s.length(); j++)
			{
				auto it = unorderMap.find(s[j]);
				if (it != unorderMap.end())
				{
					break;
				}
				else
				{
					unorderMap[s[j]]++;
				}
			}
			nMax = std::max(nMax, (int)unorderMap.size());
		}
		return nMax;
	}*/

	int lengthOfLongestSubstring(string s) {

		std::unordered_set<char> unorderSet;
		
		int length = s.length();
		int nMax = 0;
		int nRItor = -1; // ��ָ��,�൱�ڻ�û��ʼ����
		// �������ڽⷨ
		for (int i = 0; i < length; i++)
		{
			if (i > 0)
			{
				unorderSet.erase(s[i - 1]); // ������һλ
			}
			// ��ָ�벻ͣ��������
			while (nRItor + 1 < length && 0 == unorderSet.count(s[nRItor + 1]))
			{
				unorderSet.insert(s[nRItor + 1]);
				nRItor++;
			}
			
			nMax = std::max(nMax, nRItor - i + 1);
		}

		return nMax;
	}
};

//int main()
//{
//	Solution s;
//	std::string str = "abcabcbb";
//	int length = s.lengthOfLongestSubstring(str);
//	return 0;
//}