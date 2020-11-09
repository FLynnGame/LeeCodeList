#include "Anagram.h"

#include <unordered_map>

Anagram::Anagram()
{
}


Anagram::~Anagram()
{
}

bool Anagram::isAnagram(std::string s, std::string t)
{
	std::unordered_map<char, int> sMap;
	std::unordered_map<char, int> tMap;
	for (size_t i = 0; i < s.length(); i++)
	{
		sMap[s[i]]++;
	}

	for (size_t i = 0; i < t.length(); i++)
	{
		tMap[t[i]]++;
	}

	for (char c = 'a'; c < 'z'; c++)
	{
		if (sMap[c] != tMap[c])
		{
			return false;
		}
	}
	return true;
}
