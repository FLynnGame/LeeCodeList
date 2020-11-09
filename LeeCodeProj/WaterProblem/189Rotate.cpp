
//#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	// 暴力法会超时
	void rotateBruteForce(vector<int>& nums, int k) {
		int len = nums.size();
		while (k--)
		{
			// 每次取最后一个，一直两两交换，换到最后
			int nPrev = nums[len - 1];
			for (size_t i = 0; i < len; i++)
			{
				std::swap(nums[i], nPrev);
			}
			// 从后往前两两交换，交换K次
			/*for (size_t i = len - 1; i > 0; i--)
			{
				std::swap(nums[i], nums[i - 1]);
			}*/
		}
	}

	// 交换法
	void rotate(vector<int>& nums, int k) {
		// 第一步，将数组反过来
		// 第二步，翻转数组0-k的范围
		// 第三步，翻转数组k+1-len

		int len = nums.size();
		for (size_t i = 0; i < len / 2; i++)
		{
			std::swap(nums[i], nums[len - i - 1]);
		}

		// 区间(0,k-1) 下标(0,(k-1)/2)
		for (size_t i = 0; i < k / 2; i++)
		{
			std::swap(nums[i], nums[k - i - 1]);
		}

		// 区间(k,len-1) 下标(k,k+(len-k)/2)=(k,(k+len)/2)
		for (size_t i = k; i < (len+k)/2; i++)
		{
			std::swap(nums[i], nums[len-(i-k+1)]);
		}
	}
};

int main()
{
	std::vector<int> ivec = { -1,-100,3,99 };
	Solution s;
	s.rotate(ivec, 2);
	return 0;
}