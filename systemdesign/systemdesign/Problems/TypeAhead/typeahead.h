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
	unordered_map<string, vector<unordered_set<string>::iterator> > m_mp;
public:
	// @param dict: A dictionary of words dict
	Typeahead(unordered_set<string> &dict) {
		// do initialize if necessary
		for (auto itr = begin(dict); itr != end(dict); ++itr)
		{
			istringstream iss(*itr);
			vector<string> tokens(istream_iterator<string>{iss}, istream_iterator<string>());
			for (auto &t : tokens)
			{
				m_mp[t].push_back(itr);
			}
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
				res.push_back(*i);
			}
		}
		return res;
	}
};