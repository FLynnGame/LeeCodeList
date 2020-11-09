
#include <iostream>
#include <vector>




class Solution {
public:
	int removeDuplicates(std::vector<int>& nums) {
		//判断数组的边界条件
		if (nums.size() == 0) return 0;
		int slow = 0;
		for (int fast = 1; fast < nums.size(); fast++) {
			if (nums[slow] != nums[fast]) {
				slow++;
				nums[slow] = nums[fast];
			}
		}
		//因为index为偏移次数，那么数组的长度即为偏移次数+1
		return slow + 1;
	}
};

//int main()
//{
//	Solution s;
//	std::vector<int> temp = { 1,1,2 };
//
//	int count = s.removeDuplicates(temp);
//	return 0;
//}