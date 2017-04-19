#pragma once
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
using namespace std;

class Typeahead {
private:
	unordered_map<string, vector<int> > m_mp;
	vector<string> m_strings;
public:
	// @param dict: A dictionary of words dict
	Typeahead(unordered_set<string> &dict) {
		// do initialize if necessary
		for (auto itr = begin(dict); itr != end(dict); ++itr)
		{
			m_strings.push_back(*itr);
			for (int i = 0; i < itr->size(); ++i)
			{
				for (int j = i + 1; j <= itr->size(); ++j)
				{
					auto tmp = itr->substr(i, j - i);
					if(m_mp[tmp].empty() || m_mp[tmp].back() != m_strings.size() - 1)
						m_mp[tmp].push_back(m_strings.size() - 1);
				}
			}
			m_mp[""].push_back(m_strings.size() - 1);
		}
	}

	// @param str: a string
	// @return a set of words
	vector<string> search(string &str) {
		// Write your code here
		vector<string> res;
		if (m_mp.find(str) != end(m_mp))
		{
			for (auto i : m_mp[str])
			{
				res.push_back(m_strings[i]);
			}
		}
		return res;
	}
};