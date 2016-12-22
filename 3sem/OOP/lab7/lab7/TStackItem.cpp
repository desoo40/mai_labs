#include "TStackItem.h"
#include "figure.h"

template <class T> TStackItem<T>::TStackItem(const std::shared_ptr<T>& item) {
    this->item = item;
    this->next = nullptr;
    std::cout << "Stack item: created" << std::endl;
}

template <class T> TAllocationBlock
TStackItem<T>::stackitem_allocator(sizeof(TStackItem<T>), 100);

template <class T> std::shared_ptr<TStackItem<T>>
    TStackItem<T>::SetNext(std::shared_ptr<TStackItem<T>> &next) {
        std::shared_ptr<TStackItem<T>> old = this->next;
        this->next = next;
        return old;
    }
    template <class T> std::shared_ptr<T> TStackItem<T>::GetItem() const {
        return this->item;
    }
    template <class T> std::shared_ptr<TStackItem<T>> TStackItem<T>::GetNext() {
        return this->next;
    }
    template <class T> TStackItem<T>::~TStackItem() {
        std::cout << "Stack item: deleted" << std::endl;
    }

    template <class T> void * TStackItem<T>::operator new (size_t size) {
        std::cout << "Allocated :" << size << "bytes" << std::endl;
        return stackitem_allocator.allocate();
    }
    template <class T> void TStackItem<T>::operator delete(void *p) {
        std::cout << "Deleted" << std::endl;
        stackitem_allocator.deallocate(p);
    }

    template <class A> std::ostream& operator<<(std::ostream& os, const TStackItem<A>& obj) {
        std::shared_ptr<Figure> f = obj.item;
        f->Print();
        return os;
    }

    template class TStackItem<Figure>;
    template std::ostream& operator<<(std::ostream& os, const TStackItem<Figure>& obj);
