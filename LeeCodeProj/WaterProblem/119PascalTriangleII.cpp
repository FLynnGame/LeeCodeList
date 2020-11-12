
//给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。

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
			iVvec.push_back(vector<int>(i, 0)); // 生成一个变长数组
		}

		// 初始化为1
		iVvec[0][0] = 1;
		for (int i = 1; i < numRows; i++)
		{
			iVvec[i][0] = 1;
			iVvec[i][i] = 1;
		}

		// 开始相加操作
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