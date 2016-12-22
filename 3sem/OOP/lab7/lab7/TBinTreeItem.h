#ifndef _TBINTREEITEM_H_
#define _TBINTREEITEM_H_

#include <memory>
#include <iostream>

#include "allocator.h"

template <class T> class TBinTreeItem {
public:
    TBinTreeItem(const std::shared_ptr<T>&);
    ~TBinTreeItem();

    template<class A> friend std::ostream& operator<<(std::ostream& os, const
        TBinTreeItem<A>& obj);

    std::shared_ptr<TBinTreeItem<T>> GetLeft();
    std::shared_ptr<TBinTreeItem<T>> GetRight();
    std::shared_ptr<TBinTreeItem<T>> SetLeft(std::shared_ptr<TBinTreeItem> &left);
    std::shared_ptr<TBinTreeItem<T>> SetRight(std::shared_ptr<TBinTreeItem> &right);

    std::shared_ptr<T> GetItem() const;

    void * operator new (size_t size);
    void operator delete(void *p);

private:
    std::shared_ptr<TBinTreeItem<T>> left;
    std::shared_ptr<TBinTreeItem<T>> right;

    std::shared_ptr<T> item;

    static TAllocationBlock bintreeitem_allocator;
};

#endif
