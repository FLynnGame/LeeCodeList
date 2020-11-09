#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 1) {
			return nums.size();
		}

		int nSlow = 0;
		int nCount = 0;
		for (size_t fast = 1; fast < nums.size(); fast++) {
			if (nums[nSlow] == nums[fast]) { nCount++; } // 存一个重复元素
			else {
				nCount = 0;
			}
			if (nCount < 2) {
				nSlow++;
				nums[nSlow] = nums[fast];
			}

		}
		return nSlow + 1;
	}
};

//int main()
//{
//	Solution s;
//	std::vector<int> vec = { 0,0,1,1,1,1,2,3,3 };
//	s.removeDuplicates(vec);
//
//	return 0;
//}