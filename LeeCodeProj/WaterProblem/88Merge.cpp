
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		std::multiset<int> iSet;
		for (size_t i = 0; i < m; i++)
		{
			iSet.insert(nums1[i]);
		}

		for (size_t i = 0; i < n; i++)
		{
			iSet.insert(nums2[i]);
		}

		nums1.assign(iSet.begin(), iSet.end());
	}
};

//int main()
//{
//	std::vector<int> nums1 = { 1,2,3,0,0,0 };
//	std::vector<int> nums2 = { 2,5,6 };
//
//	Solution s;
//	s.merge(nums1, 3, nums2, 3);
//
//	return 0;
//}