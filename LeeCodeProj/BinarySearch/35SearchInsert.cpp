
#include <iostream>
#include <vector>

using namespace std;

// ���������в������֣������±�

class Solution {
public:
	// ����
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

	// ����
	int searchInsert(vector<int>& nums, int target) {
		int result = BinarySearchOther(nums, target);
		return result;
	}

	int BinarySearch(vector<int>& nums, int target)
	{
		int length = nums.size();
		int low = 0;
		int high = length - 1; // ����ұ�[low,high]����
		int mid = low + (high - low) / 2;
		//std::cout << "search start" << nums[mid] << std::endl;

		// ѭ����� low > high [low, high]�޽���
		// �����Ҫ��ѭ������ȷ��Ҫ���ҵ�����
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
				return mid; // ���еľ�ֱ�ӷ���
			}
			mid = low + (high - low) / 2;
			//std::cout << nums[mid] << std::endl;
		}
		//std::cout << nums[high] << "search end" << std::endl;
		return high + 1; // ������Ŀ�������ҵ���һ�����ڵ��ڵģ����high+1���ǽ�
	}

	int BinarySearchOther(vector<int>& nums, int target)
	{
		int length = nums.size();
		int low = 0;
		int high = length;
		int mid = low + (high - low) / 2;
		//std::cout << nums[mid] << std::endl;

		// ѭ����� low >= high 
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