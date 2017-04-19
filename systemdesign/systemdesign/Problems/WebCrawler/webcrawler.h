#pragma once
#include <vector>
#include <string>
#include <condition_variable>
#include <thread>
#include <unordered_set>
#include <queue>
using namespace std;


vector<string> helper(string url)
{
	return {};
}

class Crawler
{
private:
	mutex m_mtxProcessed;
	unordered_set<string> m_processedSet;
	
	mutex m_mtxUrlQueue;
	condition_variable m_cvUrlQueue;
	queue<string> m_vctUrlQueue;

	int m_queueSize;
	int m_threadNumber;
public:
	Crawler(int qn, int tn) : m_queueSize(qn), m_threadNumber(tn) {}

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
			auto res = helper(url);
			for (auto &e : res)
			{
				unique_lock<mutex> lockQueue(c->m_mtxUrlQueue);
				c->m_cvUrlQueue.wait(lockQueue, c->m_vctUrlQueue.size() < c->m_queueSize);
				c->m_vctUrlQueue.push(e);
				c->m_cvUrlQueue.notify_one();
			}
		}

	}

	vector<string> crawl(string url)
	{
		for (int i = 0; i < m_threadNumber; ++i)
		{
			auto t = thread(doWork, this);
			t.join();
		}
	}
};