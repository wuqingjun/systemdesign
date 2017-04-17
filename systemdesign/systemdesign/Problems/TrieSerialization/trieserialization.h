#pragma once

#include <string>
#include <map>
#include <istream>
#include <vector>
#include <stack>
#include <iterator>
using namespace std;

struct TrieNode {
	TrieNode() = default;
    map<char, TrieNode*> children;
};

class Solution {
public:
	/**
	* This method will be invoked first, you should design your own algorithm
	* to serialize a trie which denote by a root node to a string which
	* can be easily deserialized by your own "deserialize" method later.
	*/
	string serialize(TrieNode* root) {
		// Write your code here
		string res;
		if (root)
		{
			res += "{";
			for (auto &e : root->children)
			{
				res.append(1, e.first);
				res += serialize(e.second);
			}
			res += "}";
		}
		return res;
	}

	/**
	* This method will be invoked second, the argument data is what exactly
	* you serialized at method "serialize", that means the data is not given by
	* system, it's given by your own serialize method. So the format of data is
	* designed by yourself, and deserialize it here as you serialize it in
	* "serialize" method.
	*/
	TrieNode* deserialize(string data) {
		// Write your code here
		TrieNode *res = new TrieNode(), *current = res;
		stack<TrieNode *> st;
		for (auto c : data)
		{
			if (c == '{') st.push(current);
			else if (c == '}') st.pop();
			else {
				current = new TrieNode();
				st.top()->children[c] = current;
			}
		}

		return res;
	}
};
