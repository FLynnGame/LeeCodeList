
#include <unordered_set>
#include <algorithm>

using namespace std;

// ��������
int lengthOfLongestSubstring(string s) {

	std::unordered_set<char> unorderSet;

	int length = s.length();
	int nMax = 0;
	int nRItor = -1; // ��ָ��,�൱�ڻ�û��ʼ����
					 // �������ڽⷨ
	for (int i = 0; i < length; i++)
	{
		if (i > 0)
		{
			unorderSet.erase(s[i - 1]); // ������һλ
		}
		// ��ָ�벻ͣ��������
		while (nRItor + 1 < length && 0 == unorderSet.count(s[nRItor + 1]))
		{
			unorderSet.insert(s[nRItor + 1]);
			nRItor++;
		}

		nMax = std::max(nMax, nRItor - i + 1);
	}

	return nMax;
}

// ԭ���㷨
// ȥ�����������е��ظ�Ԫ��
// ����ֵ��������ĳ���
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