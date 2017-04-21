#pragma once
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class TinyUrl2 {
private:
	unordered_map<string, string> m_mpCustomUrlKey;
	unordered_map<string, string> m_mpCustomKeyUrl;
	unordered_map<string, long long> m_mpUrlToId;
	unordered_map<long long, string> m_mpIdToUrl;
	const string codes = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	const string tinyUrlBase = "http://tiny.url/";
public:
	string idToShortKey(long long id)
	{
		string res;
		while (id != 0)
		{
			res.append(1, codes[id % 62]);
			id /= 62;
		}
		reverse(res.begin(), res.end());
		return res;
	}

	long long shortKeyToId(string &shorKey)
	{
		long long res = 0;
		for(auto &e: shorKey)
		{
			res = res * 62 + e + (e >= 'a' ? 36 - 'a' : (e >= 'A' ? 10 - 'A' : 0 - '0'));
		}
		return res;
	}

	
public:
	/**
	* @param long_url a long url
	* @param a short key
	* @return a short url starts with http://tiny.url/
	*/
	string createCustom(string& long_url, string& short_key) {
		// Write your code here
		string key = "http://tiny.url/" + short_key;

		auto itrUrlKey = m_mpCustomUrlKey.find(long_url);
		auto itrKeyUrl = m_mpCustomKeyUrl.find(key);
		if ((itrUrlKey == end(m_mpCustomUrlKey) &&
			itrKeyUrl == end(m_mpCustomKeyUrl))
			|| (itrUrlKey != end(m_mpCustomUrlKey) && itrUrlKey->second == key &&
				itrKeyUrl != end(m_mpCustomKeyUrl) && itrKeyUrl->second == long_url)
			)
		{
			m_mpCustomUrlKey[long_url] = key;
			m_mpCustomKeyUrl[key] = long_url;
			return key;
		}
		return "error";
	}

	/**
	* @param long_url a long url
	* @return a short url starts with http://tiny.url/
	*/
	string longToShort(string& long_url) {
		// Write your code here
		if (m_mpCustomUrlKey.find(long_url) != end(m_mpCustomUrlKey))
			return m_mpCustomUrlKey[long_url];
		if (m_mpUrlToId.find(long_url) != end(m_mpUrlToId))
			return tinyUrlBase + idToShortKey(m_mpUrlToId[long_url]);

		long long id = 0;
		for (auto &a : long_url)
		{
			id = (id * 256 + a) % 56800235584L;
		}

		string tmpShort = idToShortKey(id);

		if (tmpShort.length() < 6) tmpShort = string(6 - tmpShort.size(), 'a') + tmpShort;
		id = shortKeyToId(tmpShort);

		while (m_mpIdToUrl.find(id) != end(m_mpIdToUrl)) id = (id + 1) % 56800235584L;

		m_mpIdToUrl[id] = long_url;
		m_mpUrlToId[long_url] = id;

		return tinyUrlBase + idToShortKey(id);
	}

	/**
	* @param short_url a short url starts with http://tiny.url/
	* @return a long url
	*/
	string shortToLong(string& short_url) {
		// Write your code here
		if (m_mpCustomKeyUrl.find(short_url) != end(m_mpCustomKeyUrl))
			return m_mpCustomKeyUrl[short_url];

		if (short_url.length() > tinyUrlBase.size())
		{
			auto shortKey = short_url.substr(tinyUrlBase.size());
			long long id = shortKeyToId(shortKey);
			return m_mpIdToUrl[id];
		}
		return "";
	}
};