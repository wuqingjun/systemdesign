#pragma once

#include <vector>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

 class Tweet {
 public:
     int id;
     int user_id;
     string text;
	 
     static Tweet create(int user_id, string tweet_text) {
		 static int autoId = 0;
		 auto t = Tweet();
		 t.id = autoId++;
		 t.user_id = user_id;
		 t.text = tweet_text;

		 return t;
     }
 };


struct greater
{
	bool operator ()(Tweet t1, Tweet t2)
	{
		return t1.id > t2.id;
	}
};

class MiniTwitter {
private:
	unordered_map<int, unordered_set<int> > friends;
	unordered_map<int, vector<Tweet> > tweets;
public:
	MiniTwitter() {
		// initialize your data structure here.
	}

	// @param user_id an integer
	// @param tweet a string
	// return a tweet
	Tweet postTweet(int user_id, string tweet_text) {
		//  Write your code here
		tweets[user_id].push_back(Tweet::create(user_id, tweet_text));
		return tweets[user_id].back();
	}

	// @param user_id an integer
	// return a list of 10 new feeds recently
	// and sort by timeline
	vector<Tweet> getNewsFeed(int user_id) {
		// Write your code here
		vector<Tweet> res;
		priority_queue<Tweet, vector<Tweet>, greater > mh;

		for (auto &f : friends[user_id])
		{
			for (auto &t : tweets[f])
			{
				if (mh.size() < 10 || t.id < mh.top().id)
				{
					mh.push(t);
				}
			}
		}

		while (!mh.empty())
		{
			res.push_back(mh.top());
			mh.pop();
		}

		return res;
	}

	// @param user_id an integer
	// return a list of 10 new posts recently
	// and sort by timeline
	vector<Tweet>  getTimeline(int user_id) {
		// Write your code here
		vector<Tweet> res;
		for (int i = 0; i < 10 && tweets[user_id].size() - 1 - i >= 0; ++i)
		{
			res.push_back(tweets[user_id][tweets[user_id].size() - 1 - i]);
		}
		return res;
	}

	// @param from_user_id an integer
	// @param to_user_id an integer
	// from user_id follows to_user_id
	void follow(int from_user_id, int to_user_id) {
		// Write your code here
		friends[from_user_id].insert(to_user_id);
	}

	// @param from_user_id an integer
	// @param to_user_id an integer
	// from user_id unfollows to_user_id
	void unfollow(int from_user_id, int to_user_id) {
		// Write your code here
		if (friends[from_user_id].find(to_user_id) != friends[from_user_id].end())
		{
			friends[from_user_id].erase(to_user_id);
		}
	}
};