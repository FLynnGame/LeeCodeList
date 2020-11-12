

/*
* ����һ����СΪ n �����飬�ҵ����еĶ���Ԫ�ء�����Ԫ����ָ�������г��ִ�������  n/2  ��Ԫ�ء�
*/
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	// ��ϣ��
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

	// Ħ��ͶƱ
	/*Ħ��ͶƱ����
		���ľ��Ƕ�ƴ���ġ�
		��һ��������Ե���Ϸ�������㷽�˿ڳ������˿�һ�����ϣ������ܱ�֤ÿ���˿ڳ�ȥ���̶���һ��һͬ���ھ���������˻������Ĺ��Ҿ���ʤ����
		�Ǿʹ��ս�£���������˶����������Ը��㣨��Ӧ��ÿ��ѡ����Ϊ����������������������������������Ҳ���໥��������ѡ����������Ϊ������������������ֻҪ���ǲ�Ҫ�ڶ������϶���Ӯ��
		�����ʣ�µıض����Լ��ˡ�
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