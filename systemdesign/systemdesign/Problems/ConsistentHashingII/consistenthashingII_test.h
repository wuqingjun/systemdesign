#pragma once
#include "consistenthashingII.h"



class ConsistentHashingIITest
{
public:
	void Test0()
	{
		auto sln = Solution::create(10, 3);
		sln.create(100, 3);
		sln.addMachine(1);
		sln.getMachineIdByHashCode(4);
		sln.addMachine(2);
		sln.getMachineIdByHashCode(61);
		sln.getMachineIdByHashCode(91);
	}
	
};