
#include <vector>

using namespace std;


class Solution1 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		for (size_t i = 0; i < nums.size(); i++)
		{
			for (size_t j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] + nums[j] == target)
				{
					result.push_back(i);
					result.push_back(j);
					return result;
				}
			}
		}
		return result;
	}
};

// 还可以使用unorderedmap来简化


//int main()
//{
//	vector<int> nums = { 2,7,11,15 };
//	int target = 13;
//	vector<int> result;
//	Solution1 so;
//	result = so.twoSum(nums, target);
//
//    return 0;
//}

