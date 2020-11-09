
#include <iostream>
#include <iterator>
#include <string>
#include <map>

using namespace std;

class Solution13 {
public:
	int romanToInt(string s) {
		init();

		int nValue = 0;
		for (size_t i = 0; i < s.length(); i++)
		{
			auto iter = romanValueMap.find(s.substr(i, 2));
			if (iter != romanValueMap.end()) { // ур╣╫ак
				i++;
			}
			else {
				iter = romanValueMap.find(s.substr(i, 1));
			}
			nValue += iter->second;
		}

		return nValue;
	}

	void init() {
		romanValueMap["I"] = 1;
		romanValueMap["IV"] = 4;
		romanValueMap["V"] = 5;
		romanValueMap["IX"] = 9;
		romanValueMap["X"] = 10;
		romanValueMap["XL"] = 40;
		romanValueMap["L"] = 50;
		romanValueMap["XC"] = 90;
		romanValueMap["C"] = 100;
		romanValueMap["CD"] = 400;
		romanValueMap["D"] = 500;
		romanValueMap["CM"] = 900;
		romanValueMap["M"] = 1000;
	}
private:
	std::map<string, int> romanValueMap;
};

//int main()
//{
//	Solution13 s;
//
//	s.romanToInt("MCMXCIV");
//
//	return 0;
//}