#pragma once
#include "memcache.h"
#include <cassert>
using namespace std;

class MemCacheTest
{
public:; 
	   void Test0()
	   {
		   Memcache cache;
			assert(cache.get(1, 0) == INT_MAX);
			cache.set(2, 1, 1, 2);
			assert(cache.get(3, 1) == 1);
			cache.get(4, 1);
			cache.incr(5, 1, 1);
			cache.set(6, 1, 3, 0);
			cache.incr(7, 1, 1);
			cache.decr(8, 1, 1);
			cache.get(9, 1);
			cache.del(10, 1);
			cache.get(11, 1);
			cache.incr(12, 1, 1);
	   }
};