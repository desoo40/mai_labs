#ifndef _TBINARYTREE_H_
#define _TBINARYTREE_H_
#include <memory>
#include "TBinTreeItem.h"

template <class T> class TBinaryTree {
public:
    TBinaryTree();

    void Add(std::shared_ptr<T> &&item);
    void Delete();

    bool Empty() const;
    template <class A> friend std::ostream& operator<<(std::ostream& os, const TBinaryTree<A>& stack);

    virtual ~TBinaryTree();

private:
    std::shared_ptr<TBinTreeItem<T>> root;
    int ElemQty;
};

#endif
