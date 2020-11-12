
//����һ���Ǹ����� numRows������������ǵ�ǰ numRows �С�

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	/*vector<int> getRow(int rowIndex) {

	}*/

	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> iVvec;
		if (numRows <= 0) {
			return iVvec;
		}

		for (int i = 1; i <= numRows; i++) {
			iVvec.push_back(vector<int>(i, 0)); // ����һ���䳤����
		}

		// ��ʼ��Ϊ1
		iVvec[0][0] = 1;
		for (int i = 1; i < numRows; i++)
		{
			iVvec[i][0] = 1;
			iVvec[i][i] = 1;
		}

		// ��ʼ��Ӳ���
		for (int i = 2; i < numRows; i++)
		{
			for (int j = 1; j < i; j++)
			{
				iVvec[i][j] = iVvec[i - 1][j - 1] + iVvec[i - 1][j];
			}
		}
		return iVvec;
	}
};


//int main()
//{
//	Solution s;
//	//s.getRow(5);
//	return 0;
//}