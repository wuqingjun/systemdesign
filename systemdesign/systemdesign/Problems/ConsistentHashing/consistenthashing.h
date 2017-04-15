#pragma once
#include <vector>
using namespace std;

class Solution {
public:
	/**
	* @param n a positive integer
	* @return n x 3 matrix
	*/
	vector<vector<int>> consistentHashing(int n) {
		// Write your code here
		vector<vector<int> > res;
		res.push_back({ 0, 359, 1 });

		for (int i = 1; i < n; ++i)
		{
			int index = 0;
			for (int j = 0; j < i; ++j)
			{
				if (res[j][1] - res[j][0] > res[index][1] - res[index][0]) index = j;
			}

			res.push_back({ (res[index][0] + res[index][1]) / 2 + 1, res[index][1], i + 1});
			res[index][1] = (res[index][0] + res[index][1]) / 2;
		}

		return res;
	}
};