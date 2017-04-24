#pragma once
#include "weblogger.h"

class WebLoggerTest
{
public:
	void Test0()
	{
		WebLogger logger;
		logger.hit(1);
		logger.hit(2);
		logger.get_hit_count_in_last_5_minutes(3);
		logger.hit(300);
		logger.get_hit_count_in_last_5_minutes(300);
		logger.get_hit_count_in_last_5_minutes(301);
	}

	void Test1()
	{
		WebLogger logger;
		logger.hit(1);
		logger.hit(1);
		logger.hit(1);
		logger.hit(2);
	//	logger.get_hit_count_in_last_5_minutes(3);
		logger.hit(300);
	//	logger.get_hit_count_in_last_5_minutes(300);
	//	logger.get_hit_count_in_last_5_minutes(301);
	//	logger.get_hit_count_in_last_5_minutes(302);
		logger.get_hit_count_in_last_5_minutes(900);
		logger.get_hit_count_in_last_5_minutes(900);
	}
};