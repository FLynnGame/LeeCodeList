

/*
* 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于  n/3  的元素。
*/
#include <unordered_map>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:

	/*摩尔投票法：
	核心就是对拼消耗。
	玩一个诸侯争霸的游戏，假设你方人口超过总人口一半以上，并且能保证每个人口出去干仗都能一对一同归于尽。最后还有人活下来的国家就是胜利。
	那就大混战呗，最差所有人都联合起来对付你（对应你每次选择作为计数器的数都是众数），或者其他国家也会相互攻击（会选择其他数作为计数器的数），但是只要你们不要内斗，最后肯定你赢。
	最后能剩下的必定是自己人。
	*/
	vector<int> majorityElement(vector<int>& nums) {
		std::vector<int> nResultVec = molVote(nums, 3);
		return nResultVec;
	}

	// 摩尔投票算法
	// nums : 待投票数组
	// n	: 找出超过1/n的投票人员
	std::vector<int> molVote(std::vector<int>& nums, int n) {
		int len = nums.size();
		std::vector<int> candidateVec(n-1, 0); // 候选人数组，初始化为零
		std::vector<int> countVec(n-1, 0); // 候选人计数，初始化为零
		std::vector<int> resultVec;

		if (len == 0) {
			return resultVec;
		}

		// 第一阶段，互相抵消
		for (auto num : nums) {
			bool bSame = false;
			for (int i=0; i<candidateVec.size(); i++) {
				if (candidateVec[i] == num) {
					countVec[i]++;
					bSame = true;
					break;
				}
			}

			if (false == bSame) {
				bool bFindZero = false;
				for (int i = 0; i < candidateVec.size(); i++) {
					if (countVec[i] == 0)
					{
						candidateVec[i] = num;
						countVec[i]++;
						bFindZero = true;
						break;
					}
				}

				if (false == bFindZero) {
					for (int i = 0; i < candidateVec.size(); i++) {
						countVec[i]--;
					}
				}
			}
		}

		// 第二阶段，计数结算，确定票数是否满足大于 len/n
		for (size_t i = 0; i < countVec.size(); i++) {
			countVec[i] = 0;
		}

		// 第三阶段，去除候选人中重复的值，防止出现[0,0,0]这样的元素
		std::set<int> s(candidateVec.begin(), candidateVec.end());
		candidateVec.assign(s.begin(), s.end());

		for (auto num : nums) {
			for (int i = 0; i < candidateVec.size(); i++) {
				if (candidateVec[i] == num) {
					countVec[i]++;
				}
			}
		}

		int nMajority = len / n;
		for (int i = 0; i < countVec.size(); i++) {
			if (countVec[i] > nMajority) {
				resultVec.push_back(candidateVec[i]);
			}
		}

		return resultVec;
	}
};

//int main()
//{
//	Solution s;
//	std::vector<int> ivec = { 0,0,0 };
//	s.majorityElement(ivec);
//	return 0;
//}