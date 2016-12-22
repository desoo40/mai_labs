#ifndef TSTACKITEM_H
#define TSTACKITEM_H
#include <memory>
#include <iostream>

#include "allocator.h"
template<class T> class TStackItem {
public:
    TStackItem(T *item);
    TStackItem(std::shared_ptr<T> item);
    static TAllocationBlock stackitem_allocator;
    template<class A> friend std::ostream& operator<<(std::ostream& os, const
        TStackItem<A>& obj);

    std::shared_ptr<TStackItem<T>> SetNext(std::shared_ptr<TStackItem> next);
    std::shared_ptr<TStackItem<T>> GetNext();
    std::shared_ptr<T> GetItem() const;

    void * operator new (size_t size);
    void operator delete(void *p);

    virtual ~TStackItem();
private:
    std::shared_ptr<T> item;
    std::shared_ptr<TStackItem<T>> next;
};
#endif