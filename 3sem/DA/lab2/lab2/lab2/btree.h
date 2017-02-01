#ifndef _BTREE_H_
#define _BTREE_H_

#include "str.h"
#include "btreenode.h"

class TBTree {
    
    size_t t;
	TBTreeNode *root;

    public:  
        TBTree(size_t t);
        void detour();
        Word* search(TString);

        void Serialization(std::ofstream *);
        void Deserialization(std::ifstream* );

        bool InsertWord(Word*);
        bool DeleteWord(TString line);
};

#endif

