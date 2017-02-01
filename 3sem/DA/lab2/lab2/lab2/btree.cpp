#include "btree.h"
#include <fstream>

using namespace std;

TBTree::TBTree(size_t _t) {
    root = nullptr;
    t = _t;
}

void TBTree::detour() {
    if (root != nullptr)
        root->detour();
}

Word* TBTree::search(TString line) {

    return (root == nullptr) ? nullptr : root->search(line);
}

void TBTree::Serialization(ofstream *file) {
	root->Serialization(file);
}

void TBTree::Deserialization(ifstream *file) {
//	root->Deserialization(file);
}


bool TBTree::InsertWord(Word *newWord) {
    // If tree is empty
    if (root == nullptr)
    {
        // Allocate memory for root
        root = new TBTreeNode(t, true);
        root->words[0].key = newWord->key;  // Insert key
        root->words[0].line = newWord->line;  // Insert line

        root->n = 1;  // Update number of keys in root
    }
    else // If tree is not empty
    {
        // If root is full, then tree grows in height
        if (root->n == 2 * t - 1)
        {
            // Allocate memory for new root
            TBTreeNode *s = new TBTreeNode(t, false);

            // Make old root as child of new root
            s->C[0] = root;

            // Split the old root and move 1 key to the new root
            s->splitChild(0, root);

            // New root has two children now.  Decide which of the
            // two children is going to have new key
            int i = 0;

            if (s->words[0].line < newWord->line)
                i++;
            s->C[i]->insertNonFull(newWord);

            // Change root
            root = s;
        }
        else  // If root is not full, call insertNonFull for root
            root->insertNonFull(newWord);
    }

    return true;
}

bool TBTree::DeleteWord(TString line) {
    return false;
}
