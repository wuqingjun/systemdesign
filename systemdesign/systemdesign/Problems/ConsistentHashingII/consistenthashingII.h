#pragma once
#include <vector>
#include <random>
#include <unordered_map>
using namespace std;


class Solution {
private:
	int m_nMachines;
	int m_kShards;
	unordered_map<int, int> m_mpShardToMachine;
public:
	// @param n a positive integer
	// @param k a positive integer
	// @return a Solution object
	Solution(int n, int k): m_nMachines(n), m_kShards(k) {}

	static Solution create(int n, int k) {
		// Write your code here
		return Solution(n, k);
	}

	// @param machine_id an integer
	// @return a list of shard ids
	vector<int> addMachine(int machine_id) {
		// Write your code here
		vector<int> res;
		for (int i = 0; i < m_kShards; ++i)
		{
			int t = 0;
			for (t = rand() % m_nMachines; m_mpShardToMachine.find(t) != end(m_mpShardToMachine);
				t = rand() % m_nMachines
				) 
			{
			}
			res.push_back(t);
			m_mpShardToMachine[t] = machine_id;
		}
		return res;
	}

	// @param hashcode an integer
	// @return a machine id
	int getMachineIdByHashCode(int hashcode) {
		// Write your code here		
		int t = hashcode % m_nMachines;
		for (; m_mpShardToMachine.find(t) == end(m_mpShardToMachine); t = (t + 1) % m_nMachines) {}
		return m_mpShardToMachine[t];
	}
};
