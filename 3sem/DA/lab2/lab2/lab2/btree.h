#ifndef _BTREE_H_
#define _BTREE_H_

#include "str.h"
#include "btreenode.h"

class TBTree {
	
    public:  
        TBTree(size_t t);

        bool InsertWord(Word *word);
        bool DeleteWord(TString line);

    private:
        TBTreeNode *root;
        size_t t;
};

#endif

