

/*
* ����һ����СΪ n �����飬�ҵ����еĶ���Ԫ�ء�����Ԫ����ָ�������г��ִ�������  n/3  ��Ԫ�ء�
*/
#include <unordered_map>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:

	/*Ħ��ͶƱ����
	���ľ��Ƕ�ƴ���ġ�
	��һ��������Ե���Ϸ�������㷽�˿ڳ������˿�һ�����ϣ������ܱ�֤ÿ���˿ڳ�ȥ���̶���һ��һͬ���ھ���������˻������Ĺ��Ҿ���ʤ����
	�Ǿʹ��ս�£���������˶����������Ը��㣨��Ӧ��ÿ��ѡ����Ϊ����������������������������������Ҳ���໥��������ѡ����������Ϊ������������������ֻҪ���ǲ�Ҫ�ڶ������϶���Ӯ��
	�����ʣ�µıض����Լ��ˡ�
	*/
	vector<int> majorityElement(vector<int>& nums) {
		std::vector<int> nResultVec = molVote(nums, 3);
		return nResultVec;
	}

	// Ħ��ͶƱ�㷨
	// nums : ��ͶƱ����
	// n	: �ҳ�����1/n��ͶƱ��Ա
	std::vector<int> molVote(std::vector<int>& nums, int n) {
		int len = nums.size();
		std::vector<int> candidateVec(n-1, 0); // ��ѡ�����飬��ʼ��Ϊ��
		std::vector<int> countVec(n-1, 0); // ��ѡ�˼�������ʼ��Ϊ��
		std::vector<int> resultVec;

		if (len == 0) {
			return resultVec;
		}

		// ��һ�׶Σ��������
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

		// �ڶ��׶Σ��������㣬ȷ��Ʊ���Ƿ�������� len/n
		for (size_t i = 0; i < countVec.size(); i++) {
			countVec[i] = 0;
		}

		// �����׶Σ�ȥ����ѡ�����ظ���ֵ����ֹ����[0,0,0]������Ԫ��
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