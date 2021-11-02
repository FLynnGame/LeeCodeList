
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int nSize = candyType.size();
        for (size_t i = 0; i < nSize; i++)
        {
            m_map[candyType[i]]++;
        }

        if (m_map.size() >= (nSize / 2))
        {
            return nSize / 2;
        }
        else {
            return m_map.size();
        }
    }
private:
    std::unordered_map<int, int> m_map;
};

//int main() {
//    Solution s;
//    std::vector<int> ivec = {1,1,2,2,3,4};
//    std::cout << s.distributeCandies(ivec);
//    return 0;
//}