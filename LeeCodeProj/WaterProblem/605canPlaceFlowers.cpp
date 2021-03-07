
#include <iostream>
#include <vector>

using namespace std;

/*
假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。
给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。能否在不打破种植规则的情况下种入 n 朵花？能则返回True，不能则返回False。
输入: flowerbed = [1,0,0,0,1], n = 1
输出: True

输入: flowerbed = [1,0,0,0,1], n = 2
输出: False

解读：本质上，这道题考察的是，n个相邻的零能种多少课花，再数数组中的零个数就好了。
边界比较难判，数组两边添加0来简单处理
 */



class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		vector<int> tmp = { 0 };
		const int nArrayCount = flowerbed.size();
		for (size_t i = 0; i < nArrayCount; i++) {
			tmp.push_back(flowerbed[i]);
		}
		tmp.push_back(0);

		int nCanPlaceCount = 0; // 可以种植的数量
		int nAdjacentZeroCount = 0; // 相邻的零的个数

		for (size_t i = 0; i < nArrayCount + 2; i++) {
			if (0 == tmp[i]) {
				nAdjacentZeroCount++;
			}
			else {
				nCanPlaceCount += calcMidAdjacentZeroCanPlant(tmp, nAdjacentZeroCount);
				nAdjacentZeroCount = 0;
			}
		}
		nCanPlaceCount += calcMidAdjacentZeroCanPlant(tmp, nAdjacentZeroCount); // 防止最后一个是零，漏掉
		
		return nCanPlaceCount >= n;
	}

	// 计算夹在中间相邻count个零，能种植多少棵花
	int calcMidAdjacentZeroCanPlant(vector<int>& flowerbed, int count) {
		int nCount = (count - 1) / 2;

		return nCount; // 直接舍弃小数部分，向下取整
	}
};

//int main() {
//	Solution s;
//	vector<int> ivec1 = { 0 };
//	std::cout << s.canPlaceFlowers(ivec1, 1) << std::endl;
//
//	vector<int> ivec2 = { 0,0 };
//	std::cout << s.canPlaceFlowers(ivec2, 1) << std::endl;
//
//	vector<int> ivec3 = { 0,0,1,0 };
//	std::cout << s.canPlaceFlowers(ivec3, 2) << std::endl;
//
//	vector<int> ivec4 = { 0,0,1,0,1 };
//	std::cout << s.canPlaceFlowers(ivec4, 1) << std::endl;
//
//	vector<int> ivec5 = { 0,0,0,0,0 };
//	std::cout << s.canPlaceFlowers(ivec5, 3) << std::endl;
//
//	return 0;
//}