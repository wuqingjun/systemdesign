#pragma once
#include "tinyurlII.h"

class TinyUrlIITTest
{
public:
	void Test0()
	{
		TinyUrl2 test;
		test.longToShort(string("www.google.com/problems"));
	}
};
