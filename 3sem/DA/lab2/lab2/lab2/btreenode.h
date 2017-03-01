#include "str.h"
#include <fstream>


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

        bool insertNonFull(Word*);

		void Serialization(std::ofstream *);
		//void Deserialization(std::ifstream*);

        // A utility function to split the child y of this node. i is index of y in
        // child array C[].  The Child y must be full when this function is called
        void splitChild(int, TBTreeNode*);

		TBTreeNode(size_t, bool);
        void detour();
        Word* search(TString);

        friend class TBtree;
};
