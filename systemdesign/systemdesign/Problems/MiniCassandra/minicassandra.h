#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class Column {
public:
    int key;
    string value;
    Column(int key, string value) {
        this->key = key;
        this->value = value;
   }
	Column() = default;
};


class MiniCassandra {
private:
	unordered_map<string, map<int, string> > m_mp;
public:
	MiniCassandra() {
		// initialize your data structure here.
	}

	/**
	* @param raw_key a string
	* @param column_start an integer
	* @param column_end an integer
	* @return void
	*/
	void insert(string raw_key, int column_key, string column_value) {
		// Write your code here
		m_mp[raw_key][column_key] = column_value;
	}

	/**
	* @param raw_key a string
	* @param column_start an integer
	* @param column_end an integer
	* @return a list of Columns
	*/
	vector<Column> query(string raw_key, int column_start, int column_end) {
		// Write your code here
		vector<Column> res;
		if (m_mp.find(raw_key) != m_mp.end())
		{
			for (int i = column_start; i <= column_end; ++i)
			{
				if (m_mp[raw_key].find(i) != m_mp[raw_key].end())
					res.push_back(Column(i, m_mp[raw_key][i]));
			}
		}
		return res;
	}
};