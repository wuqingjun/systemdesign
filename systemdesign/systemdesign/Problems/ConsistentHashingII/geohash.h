#pragma once
#include <vector>
#include <string>
using namespace std;

class GeoHash {
public:
	/**
	* @param latitude, longitude a location coordinate pair
	* @param precision an integer between 1 to 12
	* @return a base32 string
	*/
	vector<int> encode(double l, int p, double min, double max)
	{
		vector<int> res;
		double mid = 0.0;
		for (int i = 0; i < p * 5 / 2; ++i)
		{
			mid = (min + max) / 2;
			if (l > mid)
			{
				res.push_back(1);
				min = mid;
			}
			else
			{
				res.push_back(0);
				max = mid;
			}
		}
		return res;
	}

	string encode(vector<int> &l, int precision)
	{
		string res;
		string codes = "0123456789bcdefghjkmnpqrstuvwxyz";
		for (int i = 0; i < precision; ++i)
		{
			int base = 16, sum = 0;
			for (int j = 0; j < 5; ++j)
			{
				sum += base * l[i * 5 + j];
				base /= 2;
			}
			res += codes[sum];
		}
		return res;
	}

	string encode(double latitude, double longitude, int precision) {
		// Write your code here
		vector<int> lat = encode(latitude, precision, -90.0, 90.0);
		vector<int> longt = encode(longitude, precision, -180, 180);

		vector<int> merged;
		for (int i = 0; i < precision * 5 / 2; ++i)
		{
			merged.push_back(longt[i]);
			merged.push_back(lat[i]);
		}
		return encode(merged, precision);
	}
};