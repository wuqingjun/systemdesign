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
	const string codes = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890";
	const string tinyUrlBase = "http://tiny.url/";
private:
	string idToShortKey(long long id)
	{
		string res;
		while (id != 0)
		{
			res += codes[id % 62];
			id /= 62;
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

	}

	/**
	* @param short_url a short url starts with http://tiny.url/
	* @return a long url
	*/
	string shortToLong(string& short_url) {
		// Write your code here
	}
};