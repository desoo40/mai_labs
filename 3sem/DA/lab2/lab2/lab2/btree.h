#ifndef _BTREE_H_
#define _BTREE_H_

#include "str.h"
#include "btreenode.h"

class TBTree {
    
    size_t t;

    public:  
        TBTree(size_t t);
        void detour();
        Word* search(TString);
        TBTreeNode *root;

        void Serialization(TBTreeNode*, std::ofstream *);
        void Deserialization(TBTreeNode**, std::ifstream* );

        bool InsertWord(Word*);
        bool DeleteWord(TString line);
};

#endif

