#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <cstdlib>

class TAllocationBlock {
public:
	 TAllocationBlock(size_t size, size_t count);
	 void *allocate();
	 void deallocate(void *pointer);
	 bool has_free_blocks();

	 virtual ~TAllocationBlock();
	private:
	 size_t _size;
	 size_t _count;

	 char *_used_blocks;
	 void **_free_blocks;

	 size_t _free_count;

};

class Node {
public:
    Node *left;
    Node *right;

    Node();
    ~Node();
};

#endif