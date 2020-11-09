
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class RecentCounter {
public:
	RecentCounter() {

	}

	// 数组实现
	int ping(int t) {
		localArray.push_back(t);
		for (size_t i = 0; i < localArray.size();)
		{
			if (localArray[i] < t-3000)
			{
				localArray.erase(localArray.begin() + i);
			}
			else
			{
				i++;
			}
		}
		return localArray.size();
	}

private:
	std::vector<int> localArray;

	/*int ping(int t) {
		qu.push(t);
		while (false == qu.empty())
		{
			if (qu.front() < t - 3000)
			{
				qu.pop();
			}
			else {
				break;
			}
		}
		return qu.size();
	}

private:
	std::queue<int> qu;*/
};

/**
* Your RecentCounter object will be instantiated and called as such:
* RecentCounter* obj = new RecentCounter();
* int param_1 = obj->ping(t);
*/
