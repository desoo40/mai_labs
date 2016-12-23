#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <memory>

template <class T> class BTree {
public:
    BTree();
    BTree(std::shared_ptr<T> item);


    //void add(T *item);
    void add(std::shared_ptr<T> item);

    void del(T *item);
    std::shared_ptr<T> getElem();
    std::shared_ptr<BTree<T>> getLeft();
    std::shared_ptr<BTree<T>> getRight();
    
    ~BTree();

private:
    std::shared_ptr<T> elem;
    std::shared_ptr<BTree<T>> left;
    std::shared_ptr<BTree<T>> right;

};

#endif
