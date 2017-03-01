#include "btreenode.h"
#include <iostream>

TBTreeNode::TBTreeNode(size_t _t, bool _leaf) {
    // Copy the given minimum degree and leaf property
    t = _t;
    leaf = _leaf;

    // Allocate memory for maximum number of possible words
    // and child pointers
    words = new Word[2 * t - 1];
    C = new TBTreeNode *[2 * t];

    // Initialize the number of words as 0
    n = 0;
}

void TBTreeNode::detour() {
    int i;
    for (i = 0; i < n; i++)
    {
        // If this is not leaf, then before printing key[i],
        // traverse the subtree rooted with child C[i].
        if (leaf == false)
            C[i]->detour();
        std::cout << " " << words[i].line;
    }

    // Print the subtree rooted with last child
    if (leaf == false)
        C[i]->detour();
}

Word* TBTreeNode::search(TString line) {
    // Find the first key greater than or equal to k
    int i = 0;
    while (i < n && line > words[i].line)
        i++;

    if (i == n)
        --i;
    // If the found key is equal to k, return this node
    if (words[i].line == line)
        return &words[i];

    // If key is not found here and this is a leaf node
    if (leaf == true)
        return nullptr;

    // Go to the appropriate child
    return C[i]->search(line);
}


// A utility function to insert a new key in this node
// The assumption is, the node must be non-full when this
// function is called
bool TBTreeNode::insertNonFull(Word *newWord) {
    // Initialize index as index of rightmost element
    int i = n - 1;
    // If this is a leaf node
    if (leaf == true)
    {
        // The following loop does two things
        // a) Finds the location of new key to be inserted
        // b) Moves all greater words to one place ahead
        
        while (i >= 0 && words[i].line > newWord->line)
        {
            words[i + 1] = words[i];
            i--;
        }

        // Insert the new key at found location
        words[i + 1].key = newWord->key;
        words[i + 1].line = newWord->line;

        n = n + 1;
    }
    else // If this node is not leaf
    {
        // Find the child which is going to have the new key
        while (i >= 0 && words[i].line > newWord->line)
            i--;

        // See if the found child is full
        if (C[i + 1]->n == 2 * t - 1)
        {
            // If the child is full, then split it
            splitChild(i + 1, C[i + 1]);

            // After split, the middle key of C[i] goes up and
            // C[i] is splitted into two.  See which of the two
            // is going to have the new key
            if (words[i + 1].line < newWord->line)
                i++;
        }
        C[i + 1]->insertNonFull(newWord);
    }
    return true;
}

void TBTreeNode::Serialization(std::ofstream *file)
{
	if (this == nullptr) {
		*file << "0 ";
		return;
	}
	*file << n << " ";
	for (int i = 0; i < n; ++i) {
		*file << words[i].line << " ";
		*file << words[i].key << " ";
	}
	for (int i = 0; i <= n; ++i) {
		C[i]->Serialization(file);
	}
}

//void TBTreeNode::Deserialization(std::ifstream *file)
//{
//	int tmp;
//	*file >> tmp;
//	if (tmp == 0) {
//		if ((*node) == nullptr) {
//			return;
//		}
//		else {
//			for (size_t i = 0; i < t; ++i) {
//				(*node)->C[i] = nullptr;
//			}
//			return;
//		}
//	}
//	if ((*node) == nullptr) {
//		(*node) = new TBTreeNode(t, true);
//	}
//	(*node)->n = tmp;
//	for (int i = 0; i < (*node)->n; ++i) {
//		*file >> (*node)->words[i].line;
//		*file >> (*node)->words[i].key;
//	}
//	for (int i = 0; i <= (*node)->n; ++i) {
//		(*node)->C[i] = nullptr;
//		Deserialization(&(*node)->C[i], file);
//	}
//}

// A utility function to split the child y of this node
// Note that y must be full when this function is called
void TBTreeNode::splitChild(int i, TBTreeNode *y) {
    // Create a new node which is going to store (t-1) words
    // of y
    TBTreeNode *z = new TBTreeNode(y->t, y->leaf);
    z->n = t - 1;

    // Copy the last (t-1) words of y to z
    for (size_t j = 0; j < t - 1; j++)
        z->words[j] = y->words[j + t];

    // Copy the last t children of y to z
    if (y->leaf == false)
    {
        for (size_t j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }

    // Reduce the number of words in y
    y->n = t - 1;

    // Since this node is going to have a new child,
    // create space of new child
    for (int j = n; j >= i + 1; j--)
        C[j + 1] = C[j];

    // Link the new child to this node
    C[i + 1] = z;

    // A key of y will move to this node. Find location of
    // new key and move all greater words one space ahead
    for (int j = n - 1; j >= i; j--)
        words[j + 1] = words[j];

    // Copy the middle key of y to this node
    words[i] = y->words[t - 1];

    // Increment count of words in this node
    n = n + 1;
}
