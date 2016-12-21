#include "TStack.h"
template <class T> TStack<T>::TStack() : head(nullptr) {
}
template <class T> std::ostream& operator<<(std::ostream& os, const
    TStack<T>& stack) {
    std::shared_ptr<TStackItem<T>> item = stack.head;

    while (item != nullptr)
    {
        os << *item;
        item = item->GetNext();
    }

    return os;
}
template <class T> void TStack<T>::push(std::shared_ptr<T> &&item) {
    std::shared_ptr<TStackItem<T>> other(new TStackItem<T>(item));
    other->SetNext(head);
    head = other;
}
template <class T> bool TStack<T>::empty() {
    return head == nullptr;
}
template <class T> std::shared_ptr<T> TStack<T>::pop() {
    std::shared_ptr<T> result;
    if (head != nullptr) {
        result = head->GetFigure();
        head = head->GetNext();
    }

    else {
        std::cout << "Stack is Empty" << std::endl;
    }
     
    return result;
}

template <class T> TIterator<TStackItem<T>, T> TStack<T>::begin() {
    return TIterator<TStackItem<T>, T>(head);
}
template <class T> TIterator<TStackItem<T>, T> TStack<T>::end() {
    return TIterator<TStackItem<T>, T>(nullptr);
}


template <class T> TStack<T>::~TStack() {
}
#include "figure.h"
template class TStack<Figure>;
template std::ostream& operator<<(std::ostream& os, const TStack<Figure>&
    stack);
