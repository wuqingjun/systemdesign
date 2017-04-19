#pragma once
#include <vector>
#include <string>
#include <condition_variable>
#include <thread>
#include <unordered_set>
using namespace std;

class Crawler
{
private:
	mutex m_processed;
	unordered_set<string> m_processedSet;
	vector<string> m_urlQueue;
public:
	Crawler() : m_urlQueue(8) {}
	static void doWork(Crawler * c, string url)
	{
		//lock_guard
	}

	vector<string> crawl(string url)
	{
		
	}
};