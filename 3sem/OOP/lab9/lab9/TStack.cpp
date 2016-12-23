#include "TStack.h"
#include "figure.h"


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

template <class T> std::shared_ptr<T> TStack<T>::operator[](size_t i) {
    if (i > size() - 1) throw std::invalid_argument("index greater then stack size");
        size_t j = 0;
    for (std::shared_ptr<T> a : *this) {
        if (j == i) return a;
        j++;
    }
    return std::shared_ptr<T>(nullptr);
}

template <class T> void TStack<T>::push(T *item) {
    std::shared_ptr<TStackItem < T >> other(new TStackItem<T>(item));
    other->SetNext(head);
    head = other;
}

template <class T> void TStack<T>::push(std::shared_ptr<T> item) {
    std::shared_ptr<TStackItem<T>> other(new TStackItem<T>(item));
    if (other == nullptr) 
        return;
    
    other->SetNext(head);
    head = other;
}
template <class T> bool TStack<T>::empty() {
    return head == nullptr;
}
template <class T> std::shared_ptr<T> TStack<T>::pop() {
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

template <class T> std::shared_ptr<T> TStack<T>::pop_last() {
    std::shared_ptr<T> result;
    if (head != nullptr) {
        std::shared_ptr<TStackItem < T>> element = head;
        std::shared_ptr<TStackItem < T>> prev = nullptr;
        while (element->GetNext() != nullptr) {
            prev = element;
            element = element->GetNext();
        }
        if (prev != nullptr) {
            prev->SetNext(nullptr);
            result = element->GetItem();
        }
        else {
            result = element->GetItem();
            head = nullptr;
        }
    }
    return result;
}
template <class T> size_t TStack<T>::size() {
    int result = 0;
    for (auto i : *this) result++;
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
#include <functional>
template class TStack<std::function<void(void)>>;
template class TStack<Figure>;
template std::ostream& operator<<(std::ostream& os, const TStack<Figure>&
    stack);
