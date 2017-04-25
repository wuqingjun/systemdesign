#pragma once
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

class RateLimiter {
private:
	unordered_map<string, map<int, int> > m_mpHits;
public:
	/**
	* @param timestamp the current timestamp
	* @param event the string to distinct different event
	* @param rate the format is [integer]/[s/m/h/d]
	* @param increment whether we should increase the counter
	* @return true or false to indicate the event is limited or not
	*/
	bool isRatelimited(int timestamp, string& event, string& rate, bool increment) {
		// Write your code here

		if (m_mpHits.find(event) == end(m_mpHits))
		{
			m_mpHits[event] = map<int, int>();
		}

		int sep = rate.find('/');

		int num = stoi(rate.substr(0, sep));
		int time = 1;

		if ('m' == rate[sep + 1]) time *= 60;
		else if ('h' == rate[sep + 1]) time *= 3600;
		else if ('d' == rate[sep + 1]) time *= 3600 * 24;
		
		time = timestamp - time + 1;

		int count = 0;

		auto lb = m_mpHits[event].lower_bound(time);
		for (; lb != end(m_mpHits[event]); ++lb)
		{
			count += lb->second;
		}
		
		if (count < num && increment) {
			m_mpHits[event][timestamp] += 1;
		}


		return count >= num;
	}
};