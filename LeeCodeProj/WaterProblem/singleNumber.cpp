
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int nAns = 0;
		for (auto num : nums) {
			nAns ^= num;
		}
		return nAns;
	}
};

//int main() {
//	Solution s;
//	std::vector<int> ivsc = { 2,2,1 };
//	std::cout << s.singleNumber(ivsc);
//	return 0;
//}