
#include <iostream>
#include <algorithm>
#include <string>

class Solution7 {
public:
	int reverse(int x) {
		std::string temp;
		bool bNegative = false;
		if (x >= INT_MAX || x <= INT_MIN) return 0;
		if (x < 0)
		{
			bNegative = true;
			x *= -1;
		}

		temp = std::to_string(x);
		std::reverse(temp.begin(), temp.end());
		long long int nResult = std::stoll(temp);
		if (nResult > INT_MAX || nResult < INT_MIN) return 0;

		if (bNegative)
			return nResult * -1;
		return nResult;
	}
};

//int main()
//{
//	Solution7 s;
//	std::cout << s.reverse(INT_MIN) << std::endl;
//
//	return 0;
//}