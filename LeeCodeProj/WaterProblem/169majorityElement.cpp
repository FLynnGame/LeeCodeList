

/*
* 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于  n/2  的元素。
*/
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	// 哈希法
	int majorityElementHash(vector<int>& nums) {
		std::unordered_map<int, int> unorderMap;
		for (size_t i = 0; i < nums.size(); i++)
		{
			unorderMap[nums[i]]++;
		}

		int nHalfLen = nums.size() / 2;
		for (auto it : unorderMap)
		{
			if (it.second > nHalfLen)
			{
				return it.first;
			}
		}
		return 0;
	}

	// 摩尔投票
	/*摩尔投票法：
		核心就是对拼消耗。
		玩一个诸侯争霸的游戏，假设你方人口超过总人口一半以上，并且能保证每个人口出去干仗都能一对一同归于尽。最后还有人活下来的国家就是胜利。
		那就大混战呗，最差所有人都联合起来对付你（对应你每次选择作为计数器的数都是众数），或者其他国家也会相互攻击（会选择其他数作为计数器的数），但是只要你们不要内斗，最后肯定你赢。
		最后能剩下的必定是自己人。
	*/
	int majorityElement(vector<int>& nums) {
		int nCount = 0, candidate = nums[0];
		for (size_t i = 0; i < nums.size(); i++)
		{
			if (candidate == nums[i])
			{
				nCount++;
			}
			else
			{
				nCount--;
			}

			if (nCount == 0)
			{
				candidate = nums[i+1];
			}
		}

		return candidate;
	}
};

//int main()
//{
//	Solution s;
//	std::vector<int> ivec = { 2,2,1,1,1,2,2 };
//	s.majorityElement(ivec);
//	return 0;
//}