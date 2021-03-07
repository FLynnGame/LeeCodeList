
#include <iostream>
#include <vector>

using namespace std;

// 有序数组中插入数字，返回下标

class Solution {
public:
	// 暴力
	/*int searchInsert(vector<int>& nums, int target) {
		if (nums[0] > target)
		{
			return 0;
		}
		int length = nums.size();
		for (size_t i = 0; i < length; i++)
		{
			if (i < length - 1 && nums[i] < target && nums[i+1] > target)
			{
				return i + 1;
			}
			else if (nums[i] == target)
			{
				return i;
			}
		}

		return nums.size();
	}*/

	// 二分
	int searchInsert(vector<int>& nums, int target) {
		int result = BinarySearchOther(nums, target);
		return result;
	}

	int BinarySearch(vector<int>& nums, int target)
	{
		int length = nums.size();
		int low = 0;
		int high = length - 1; // 左闭右闭[low,high]区间
		int mid = low + (high - low) / 2;
		//std::cout << "search start" << nums[mid] << std::endl;

		// 循环结果 low > high [low, high]无交集
		// 因此需要在循环体内确定要查找的数字
		while (low <= high)
		{
			if (nums[mid] > target)
			{
				high = mid - 1;
			}
			else if (nums[mid] < target)
			{
				low = mid + 1;
			}
			else {
				return mid; // 命中的就直接返回
			}
			mid = low + (high - low) / 2;
			//std::cout << nums[mid] << std::endl;
		}
		//std::cout << nums[high] << "search end" << std::endl;
		return high + 1; // 由于题目让我们找到第一个大于等于的，因此high+1就是解
	}

	int BinarySearchOther(vector<int>& nums, int target)
	{
		int length = nums.size();
		int low = 0;
		int high = length;
		int mid = low + (high - low) / 2;
		//std::cout << nums[mid] << std::endl;

		// 循环结果 low >= high 
		while (low < high)
		{
			if (nums[mid] >= target)
			{
				high = mid;
			}
			else if (nums[mid] < target)
			{
				low = mid + 1;
			}
			mid = low + (high - low) / 2;
		}
		return mid;
	}
};

//int main()
//{
//	Solution s;
//	std::vector<int> ivec = { 1,3,5,6,7,10,12,15 };
//
//	std::vector<int> target = { 5,2,7,0,6,16 };
//	for (size_t i = 0; i < target.size(); i++)
//	{
//		std::cout << s.searchInsert(ivec, target[i]) << std::endl;
//	}
//
//	return 0;
//}