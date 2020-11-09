
#include <iostream>
#include <vector>




class Solution {
public:
	int removeDuplicates(std::vector<int>& nums) {
		//�ж�����ı߽�����
		if (nums.size() == 0) return 0;
		int slow = 0;
		for (int fast = 1; fast < nums.size(); fast++) {
			if (nums[slow] != nums[fast]) {
				slow++;
				nums[slow] = nums[fast];
			}
		}
		//��ΪindexΪƫ�ƴ�������ô����ĳ��ȼ�Ϊƫ�ƴ���+1
		return slow + 1;
	}
};

//int main()
//{
//	Solution s;
//	std::vector<int> temp = { 1,1,2 };
//
//	int count = s.removeDuplicates(temp);
//	return 0;
//}