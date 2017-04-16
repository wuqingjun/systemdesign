// systemdesign.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Problems\MiniTweeter\minitweetertest.h"
#include "Problems\MemCache\memcache_test.h"

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

int main()
{
	Test0();
	Test1();

    return 0;
}

