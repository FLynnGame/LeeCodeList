
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	bool containsDuplicate(std::vector<int>& nums) {
		std::map<int, int> nCountMap;
		for (size_t num : nums) {
			nCountMap[num]++;
			if (nCountMap[num] > 1) {
				return true;
			}
		}
		return false;
	}
};


//int main() {
//	Solution s;
//	std::vector<int> ivec = { 1,1,1,3,3,4,3,2,4,2 };
//	std::cout << s.containsDuplicate(ivec);
//	return 0;
//}