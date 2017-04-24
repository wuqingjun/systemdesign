#pragma once
#include <string>
#include <vector>
#include <bitset>
using namespace std;

struct Hash
{
	int seed, cap;
	Hash(int s, int c) : seed(s), cap(c) {}
	int operator()(string &value) const
	{
		int res = 0;
		for (auto c : value)
		{
			res = (res * seed + c) % cap;
		}
		return res;
	}
};

class StandardBloomFilter {
private:
	int m_k;
	vector<Hash> hashes;
	bitset<200000> bits;
public:
	StandardBloomFilter(int k) : m_k(k) {
		for (; k > 0; --k)
		{
			hashes.push_back(Hash(100000 + k, 2 * k + 7));
		}
	}

	void add(string& word) {
		for (int i = 0; i <m_k; ++i)
		{
			int pos = hashes[i](word);
			bits.set(pos);
		}
	}

	bool contains(string& word) {
		int i = 0;
		for (; i < m_k && bits[hashes[i](word)]; ++i) {}
		return i == m_k;
	}
};