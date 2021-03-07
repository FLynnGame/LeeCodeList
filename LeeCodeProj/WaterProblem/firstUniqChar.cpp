
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		std::unordered_map<char, int> unorderMap;
		for (char c : s) {
			unorderMap[c]++;
		}
		for (int i = 0; i < s.length(); i++) {
			if (unorderMap[s[i]] == 1) {
				return i;
			}
		}
		return -1;
	}
};

int main() {
	Solution s;
	std::string str = "l";
	std::cout << s.firstUniqChar(str);
	return 0;
}