#pragma once
#include "minitweeter.h"

class MiniTweeterTest
{
public:
	void Test0()
	{
		MiniTwitter mt;
		mt.follow(2, 1);
		mt.follow(3, 1);
		mt.postTweet(2, "user 2 tweet 1");
	}
};
