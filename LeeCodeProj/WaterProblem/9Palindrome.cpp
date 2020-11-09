
#include <iostream>
#include <string>

class Solution9 {
public:
	bool isPalindrome(int x) {
		int rev = reverse(x);
		if (x < 0) return false;
		return rev == x;
	}

protected:
	long long int reverse(int x) {
		long long int rev = 0;
		while (x)
		{
			rev = rev * 10 + x % 10;
			x /= 10;
		}
		return rev;
	}
};

//int main()
//{
//	Solution9 s;
//	std::cout << s.isPalindrome(10);
//
//	return 0;
//}