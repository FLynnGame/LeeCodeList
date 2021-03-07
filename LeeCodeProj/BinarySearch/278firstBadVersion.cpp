
#include <iostream>

using namespace std;

// The API isBadVersion is defined for you.
bool isBadVersion(int version) {
	if (version == 5) {
		return true;
	}
}

class Solution {
public:
	int firstBadVersion(int n) {
		int low = 0, high = n;
		while (low < high) {
			int mid = low + (high - low) / 2;
			if (true == isBadVersion(mid)) {
				high = mid;
			}
			else {
				low = mid + 1;
			}
		}
		return low;
	}
};

int main() {
	Solution s;
	std::cout << s.firstBadVersion(10) << std::endl;
	return 0;
}