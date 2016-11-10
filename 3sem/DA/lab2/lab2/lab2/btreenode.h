#pragma once

typedef struct {
	TString line;
	unsigned long long key;
} Word;

class TBTreeNode
{
	public:
		Word *words;  // An array of keys
		size_t t;      // Minimum degree (defines the range for number of keys)
		TBTreeNode **C; // An array of child pointers
		int n;     // Current number of keys
		bool leaf; // Is true when node is leaf. Otherwise false

		TBTreeNode(size_t t, bool leaf);
};
