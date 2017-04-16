#pragma once
#include <unordered_map>
using namespace std;


struct Resource
{
	int value;
	int expiry;
	Resource(int v, int e) : value(v), expiry(e) {}
	Resource() = default;
};

class Memcache {
private:
	unordered_map<int, Resource> m_mp;
public:
	Memcache() {
		// initialize your data structure here.
	}

	int get(int curtTime, int key) {
		// Write your code here
		auto itr = m_mp.find(key);
		if (itr != m_mp.end())
		{
			if (itr->second.expiry >= 0 && itr->second.expiry < curtTime) m_mp.erase(itr);
			else return itr->second.value;
		}
		return INT_MAX;
	}

	void set(int curtTime, int key, int value, int ttl) {
		auto resource = Resource(value, curtTime + ttl - 1);
		if (ttl == 0) resource.expiry = -1;
		m_mp[key] = resource;
	}

	void del(int curtTime, int key) {
		// Write your code here
		auto itr = m_mp.find(key);
		m_mp.erase(itr);
	}

	int incr(int curtTime, int key, int delta) {
		// Write your code here
		auto itr = m_mp.find(key);
		if (itr != m_mp.end()) {
			itr->second.value += delta;
			return itr->second.value;
		}
		return INT_MAX;
	}

	int decr(int curtTime, int key, int delta) {
		// Write your code here
		return incr(curtTime, key, -delta);
	}
};