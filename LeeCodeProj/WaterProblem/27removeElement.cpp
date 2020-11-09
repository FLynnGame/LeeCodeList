
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int nSlow = 0;

		for (size_t fast = 0; fast < nums.size(); fast++) {
			if (nums[fast] != val) {
				nums[nSlow] = nums[fast];
				nSlow++;
			}
		}

		return nSlow;
	}
};

//int main()
//{
//	Solution s;
//	std::vector<int> vec = { 0,1,2,2,3,0,4,2 };
//	s.removeElement(vec, 2);
//
//	return 0;
//}