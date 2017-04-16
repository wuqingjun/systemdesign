#pragma once
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct TrieNode {
	TrieNode() = default;
    map<char, TrieNode*> children;
    vector<int> top10;
};

class TrieService {
private:
	TrieNode* root;

public:
	TrieService() {
		root = new TrieNode();
	}

	TrieNode* getRoot() {
		// Return root of trie root, and 
		// lintcode will print the tree struct.
		return root;
	}

	void insert(string& word, int frequency) {
		// Write your code here
		auto curr = root;
		for (auto &c : word)
		{
			if (curr->children.find(c) == curr->children.end())
			{
				curr->children[c] = new TrieNode();
			}
			if (curr->children[c]->top10.size() == 10)
			{
				curr->children[c]->top10.pop_back();
			}
			curr->children[c]->top10.push_back(frequency);

			sort(curr->children[c]->top10.begin(), curr->children[c]->top10.end(), [](int n1, int n2) {return n1 > n2; });
			
			curr = curr->children[c];
		}
	}
};