#include "TStack.h"
template <class T, class TT > TStack<T, TT>::TStack() : head(nullptr) {
}

template <class T, class TT> void TStack<T,
    TT>::RemoveSubitem(IRemoveCriteria<TT> * criteria) {
    std::cout << "---------------------->" << std::endl;
    for (auto i : *this) {
        T copy;
        while (!i->empty()) {
            std::shared_ptr<TT> value = i->pop();
            if (criteria->isIt(&*value))
                std::cout << "Stack: Delete element " << *value << std::endl;
            else {
                copy.push(new TT(*value));
            }
        }
        while (!copy.empty()) i->push(new TT(*copy.pop()));
    }
    std::cout << "!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
}

template <class T, class TT> void TStack<T, TT>::InsertSubitem(TT* value) {
    bool inserted = false;
    if (head != nullptr) {
        for (auto i : *this) {
            if (i->size() < 5) {
                i->push(value);
                std::cout << "Stack: Add Element in stack:" << i->size() <<
                    std::endl;
                inserted = true;
            }
        }
    }
    if (!inserted) {
        std::cout << "Stack: New stack element created" << std::endl;
        T* t_value = new T();
        t_value->push(value);
        PushBack(t_value);
    }
}

template <class T, class TT> std::ostream& operator<<(std::ostream& os, const
    TStack<T, TT>& stack) {
    std::shared_ptr<TStackItem<T>> item = stack.head;

    while (item != nullptr)
    {
        os << *item;
        item = item->GetNext();
    }

    return os;
}
template <class T, class TT> void TStack<T, TT>::push(std::shared_ptr<T> item) {
    std::shared_ptr<TStackItem<T>> other(new TStackItem<T>(item));
    if (other == nullptr) 
        return;
    
    other->SetNext(head);
    head = other;
}
template <class T, class TT> bool TStack<T, TT>::empty() {
    return head == nullptr;
}

template <class T, class TT> size_t TStack<T, TT>::Size() {
    size_t result = 0;
    for (auto a : *this) result++;
    return result;
}

template <class T, class TT> std::shared_ptr<T> TStack<T, TT>::pop() {
    std::shared_ptr<T> result;
    if (head != nullptr) {
        result = head->GetItem();
        head = head->GetNext();
    }

    else {
        std::cout << "Stack is Empty" << std::endl;
    }
     
    return result;
}

template <class T, class TT> TIterator<TStackItem<T>, T> TStack<T, TT>::begin() {
    return TIterator<TStackItem<T>, T>(head);
}
template <class T, class TT> TIterator<TStackItem<T>, T> TStack<T, TT>::end() {
    return TIterator<TStackItem<T>, T>(nullptr);
}


template <class T, class TT> TStack<T, TT>::~TStack() {
}
#include "figure.h"
#include "BTree.h"
template class TStack<BTree<Figure>, Figure>;
template std::ostream& operator<<(std::ostream& os, const  TStack<BTree<Figure>, Figure>&
    stack);
