#pragma once
#include <deque>
using namespace std;

class WebLogger {
	deque<pair<int, int> > m_log;
public:
	WebLogger() {
		// initialize your data structure here.
	}

	/**
	* @param timestamp an integer
	* @return void
	*/
	void hit(int timestamp) {
		if (m_log.empty() || m_log.back().first < timestamp) {
			m_log.push_back({ timestamp, 1 });
		}
		else {
			m_log.back().second += 1;
		}

	}

	/**
	* @param timestamp an integer
	* @return an integer
	*/
	int get_hit_count_in_last_5_minutes(int timestamp) {
		// Write your code here
		int l = 0, h = m_log.size() - 1;
		while (l < h)
		{
			int mid = l + (h - l) / 2;
			if (m_log[mid].first <= timestamp - 300) l = mid + 1;
			else h = mid;
		}
		int res = 0;
		for (int i = l; i < m_log.size(); ++i)
		{
			res += m_log[i].second;
		}
		for (int i = 0; i < l; ++i)
		{
			m_log.pop_front();
		}
		return res;
	}
};