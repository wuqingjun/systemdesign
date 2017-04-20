#pragma once

#include "webcrawler.h"

class WebCrawlerTest
{
public:
	void Test()
	{
		Crawler c(3, 3);
		c.crawl("https://www.wikipedia.org/");
	}
};
