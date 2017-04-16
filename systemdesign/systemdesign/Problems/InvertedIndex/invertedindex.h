#pragma once

#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

struct Document {
    int id;
    string content;
};

class Solution {
	map<string, vector<int> > m_mp;
public:
	/**
	* @param docs a list of documents
	* @return an inverted index
	*/
	map<string, vector<int>> invertedIndex(vector<Document>& docs) {
		// Write your code here
		for (auto &d : docs)
		{
			istringstream iss(d.content);
			vector<string> tokens{ istream_iterator<string>{iss}, istream_iterator<string>() };//how it works?
			for (auto &t: tokens)
			{
				if (m_mp[t].empty() || m_mp[t].back() != d.id)
				{
					m_mp[t].push_back(d.id);
				}
			}
		}
		return m_mp;
	}
};