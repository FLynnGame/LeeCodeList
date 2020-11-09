
#include <unordered_set>
#include <algorithm>

using namespace std;

// 滑动窗口
int lengthOfLongestSubstring(string s) {

	std::unordered_set<char> unorderSet;

	int length = s.length();
	int nMax = 0;
	int nRItor = -1; // 右指针,相当于还没开始滑动
					 // 滑动窗口解法
	for (int i = 0; i < length; i++)
	{
		if (i > 0)
		{
			unorderSet.erase(s[i - 1]); // 向右走一位
		}
		// 右指针不停的往后走
		while (nRItor + 1 < length && 0 == unorderSet.count(s[nRItor + 1]))
		{
			unorderSet.insert(s[nRItor + 1]);
			nRItor++;
		}

		nMax = std::max(nMax, nRItor - i + 1);
	}

	return nMax;
}

// 原地算法
// 去除有序数组中的重复元素
// 返回值：新数组的长度
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