
//#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	// �������ᳬʱ
	void rotateBruteForce(vector<int>& nums, int k) {
		int len = nums.size();
		while (k--)
		{
			// ÿ��ȡ���һ����һֱ�����������������
			int nPrev = nums[len - 1];
			for (size_t i = 0; i < len; i++)
			{
				std::swap(nums[i], nPrev);
			}
			// �Ӻ���ǰ��������������K��
			/*for (size_t i = len - 1; i > 0; i--)
			{
				std::swap(nums[i], nums[i - 1]);
			}*/
		}
	}

	// ������
	void rotate(vector<int>& nums, int k) {
		// ��һ���������鷴����
		// �ڶ�������ת����0-k�ķ�Χ
		// ����������ת����k+1-len

		int len = nums.size();
		for (size_t i = 0; i < len / 2; i++)
		{
			std::swap(nums[i], nums[len - i - 1]);
		}

		// ����(0,k-1) �±�(0,(k-1)/2)
		for (size_t i = 0; i < k / 2; i++)
		{
			std::swap(nums[i], nums[k - i - 1]);
		}

		// ����(k,len-1) �±�(k,k+(len-k)/2)=(k,(k+len)/2)
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