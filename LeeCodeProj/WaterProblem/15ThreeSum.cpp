
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:

	vector<vector<int>> threeSum(vector<int>& nums) {

		// ����ѭ��
		/*std::vector<std::vector<int>> vvec;
		std::set<std::vector<int>> vSet;

		for (size_t i = 0; i < nums.size(); i++)
		{
			for (size_t j = i + 1; j < nums.size(); j++)
			{
				for (size_t t = j + 1; t < nums.size(); t++)
				{
					if (nums[i] + nums[j] == (-1)*nums[t])
					{
						std::vector<int> ivec = { nums[i], nums[j], nums[t] };
						std::sort(ivec.begin(), ivec.end());

						vSet.insert(ivec);
					}
				}
			}
		}
		vvec.assign(vSet.begin(), vSet.end());*/

		/*std::vector<std::vector<int>> iVvec;
		std::unordered_multimap<int, std::pair<int, int>> unorderMap;
		std::set<std::vector<int>> vSet;

		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				auto it = unorderMap.find(nums[j]);
				if (it != unorderMap.end())
				{
					std::vector<int> temp = { nums[j], it->second.first, it->second.second };
					std::sort(temp.begin(), temp.end());
					vSet.insert(temp);
					unorderMap.erase(it->first);
				}
				else {
					int mark = 0 - nums[i] - nums[j];
					std::pair<int, std::pair<int, int>> temp;
					temp.first = mark;
					temp.second = std::pair<int, int>(nums[i], nums[j]);
					unorderMap.insert(temp);
				}
			}
		}

		iVvec.assign(vSet.begin(), vSet.end());;
		return iVvec;*/

		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		// �ҳ�a + b + c = 0 
		// a = nums[i], b = nums[j], c = -(a + b)
		for (int i = 0; i < nums.size(); i++) {
			// ����֮�������һ��Ԫ���Ѿ������㣬��ô�����ܴճ���Ԫ��
			if (nums[i] > 0) {
				continue;
			}
			if (i > 0 && nums[i] == nums[i - 1]) { //��Ԫ��Ԫ��aȥ��
				continue;
			}
			unordered_set<int> set;
			for (int j = i + 1; j < nums.size(); j++) {
				if (j > i + 2
					&& nums[j] == nums[j - 1]
					&& nums[j - 1] == nums[j - 2]) { // ��Ԫ��Ԫ��bȥ��
					continue;
				}
				int c = 0 - (nums[i] + nums[j]);
				if (set.find(c) != set.end()) {
					result.push_back({ nums[i], nums[j], c });
					set.erase(c);// ��Ԫ��Ԫ��cȥ��
				}
				else {
					set.insert(nums[j]);
				}
			}
		}
		return result;
	}
};

//int main()
//{
//	Solution s;
//	std::vector<int> ivec = { 1,2,-2,-1 };
//	std::vector<vector<int>> result;
//	result = s.threeSum(ivec);
//
//	return 0;
//}