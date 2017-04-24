#pragma once
#include "bloomfilter.h"

class BloomFilterTest
{
public:
	void Test0()
	{
		StandardBloomFilter filter(2);
		filter.add(string("lint"));
		filter.add(string("code"));
		filter.contains(string("lint"));
		filter.contains(string("world"));
		filter.contains(string("code"));
		filter.contains(string("lintcode"));
		filter.add(string("hello"));
		filter.contains(string("hello"));
		
	}
};
