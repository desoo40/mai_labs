#ifndef TSTACK_H
#define TSTACK_H

#include <memory>
#include "titerator.h"
#include "IRemoveCriteria.h"
#include "TStackItem.h"

template <class T, class TT> class TStack
{
public:
    TStack();

    void InsertSubitem(TT *value);
    void RemoveSubitem(IRemoveCriteria<TT> *criteria);
    void push(std::shared_ptr<T> item);
    bool empty();
    size_t size();
    std::shared_ptr<T> pop();

    TIterator<TStackItem<T>, T> begin();
    TIterator<TStackItem<T>, T> end();

    template <class A, class AA> friend std::ostream& operator<<(std::ostream& os, const TStack<A, AA>& stack);
    virtual ~TStack();
private:

    std::shared_ptr<TStackItem<T>> head;
};
#endif