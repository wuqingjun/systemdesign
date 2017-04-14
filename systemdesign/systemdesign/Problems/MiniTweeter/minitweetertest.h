#pragma once
#include "minitweeter.h"

class MiniTweeterTest
{
public:

	void Test0()
	{
		MiniTwitter mt;
		mt.postTweet(1, "LintCode is Good!!!");
		mt.getNewsFeed(1);
		mt.getTimeline(1);
		mt.follow(2, 1);
		mt.getNewsFeed(2);
		mt.unfollow(2, 1);
		mt.getNewsFeed(2);
	}

	void Test1()
	{
		MiniTwitter mt;
		mt.postTweet(1, "LintCode is Good!!!");
		mt.getNewsFeed(1);
		mt.getTimeline(1);
		mt.follow(2, 1);
		mt.postTweet(1, "LintCode is best!!!");
		mt.getNewsFeed(2);
		mt.unfollow(2, 1);
		mt.getNewsFeed(2);
	}

	void Test2()
	{
		MiniTwitter mt;
		mt.postTweet(1, "LintCode is Good!!!");
		mt.getNewsFeed(1);
		mt.getTimeline(1);
		mt.follow(2, 1);
		mt.follow(2, 3);
		mt.postTweet(3, "LintCode is Cool!!!");
		mt.postTweet(3, "How to do A + B problem?");
		mt.postTweet(3, "I have accepted A + B problem.");
		mt.postTweet(3, "I favorite A + B problem.");
		mt.postTweet(1, "I favorite A + B problem too.");
		mt.postTweet(2, "Nani?");
		mt.postTweet(2, "I want to solve this problem now.");
		mt.postTweet(3, "I want to solve this problem now.");
		mt.postTweet(3, "The problem is so easy.");
		mt.postTweet(1, "hehe."); //11
		mt.postTweet(2, "Let's to do it together.");
		mt.postTweet(2, "haha");
		mt.getNewsFeed(2);
		mt.getTimeline(2);
		mt.getNewsFeed(1);
		mt.follow(1, 2);
		mt.getNewsFeed(1);
		mt.follow(1, 3);
		mt.getNewsFeed(1);
		mt.unfollow(2, 1);
		mt.getNewsFeed(2);
	}

	void Testn()
	{
		MiniTwitter mt;
		mt.follow(2, 1);
		mt.follow(3, 1);
		mt.postTweet(2, "user 2 tweet 1");
	}
};
