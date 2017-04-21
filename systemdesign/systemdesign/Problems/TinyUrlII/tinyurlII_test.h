#pragma once
#include "tinyurlII.h"

class TinyUrlIITTest
{
public:
	void Test0()
	{
		TinyUrl2 test;

		assert(test.shortKeyToId(string("11")) == 63L);

		assert(test.shortKeyToId(string("A1")) == 621L);
		assert(test.shortKeyToId(string("aA1")) == 139005L);

		auto id1 = test.shortKeyToId(string("d1Tt2C"));
		auto s1 = test.idToShortKey(id1);
		assert(s1 == string("d1Tt2C"));
		auto id2 = test.shortKeyToId(s1);
		assert(id1 == id2);
		auto s2 = test.idToShortKey(id2);
		assert(s1 == s2);
	}

	void Test1()
	{
		TinyUrl2 test;
		auto s1 = test.createCustom(string("http://www.lintcode.com/"), string("lccode"));
		assert(test.shortToLong(s1) == string("http://www.lintcode.com/"));

		auto s2 = test.longToShort(string("http://www.lintcode.com/problem/"));

		auto l2 = test.shortToLong(s2);

		assert(l2 == string("http://www.lintcode.com/problem/"));

		test.shortToLong(string("http://tiny.url/lccode"));
		test.createCustom(string("http://www.lintcode.com/"), string("lc"));
		test.createCustom(string("http://www.lintcode.com/en/ladder/"), string("lccode"));
	}
};
