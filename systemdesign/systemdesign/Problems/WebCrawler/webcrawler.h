#pragma once
#include <vector>
#include <string>
#include <condition_variable>
#include <thread>
#include <unordered_set>
#include <queue>
using namespace std;

class Crawler
{
private:
	mutex m_mtxProcessed;
	unordered_set<string> m_processedSet;
	
	mutex m_mtxUrlQueue;
	condition_variable m_cvUrlQueue;
	queue<string> m_vctUrlQueue;
public:
	Crawler() = default;

	static void doWork(Crawler * c)
	{
		unique_lock<mutex> lock(c->m_mtxUrlQueue);
		c->m_cvUrlQueue.wait(lock, c->m_vctUrlQueue.size() > 0);
		string url = c->m_vctUrlQueue.front();
		c->m_cvUrlQueue.notify_one();

		bool needProccess = false;

		{
			lock_guard<mutex> lockProccessed(c->m_mtxProcessed);
			if (c->m_processedSet.find(url) == c->m_processedSet.end())
			{
				needProccess = true;
				c->m_processedSet.insert(url);
			}
		}
		
		if (needProccess)
		{

		}


	}

	vector<string> crawl(string url)
	{
		
	}
};