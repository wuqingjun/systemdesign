// systemdesign.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Problems\MiniTweeter\minitweetertest.h"
#include "Problems\MemCache\memcache_test.h"
#include "Problems\\TinyUrlII\tinyurlII_test.h"
#include "Problems\ConsistentHashingII\consistenthashingII_test.h"

void Test0()
{
	MiniTweeterTest test;
	test.Test2();
}

void Test1()
{
	MemCacheTest test;
	test.Test0();
}

void Test2()
{
	TinyUrlIITTest test;
	test.Test0();
	test.Test1();
}

void Test3()
{
	ConsistentHashingIITest test;
	test.Test0();
}

int main()
{
	//Test0();
	//Test1();
	//Test2();
	Test3();

    return 0;
}

