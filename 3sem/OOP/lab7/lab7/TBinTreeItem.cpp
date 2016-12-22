#include "TBinTreeItem.h"
#include "figure.h"

template <class T> TBinTreeItem<T>::TBinTreeItem(const std::shared_ptr<T>& item) {
    this->item = item;
    this->left = nullptr;
    this->right = nullptr;
    std::cout << "BinTree item: created" << std::endl;
}

template <class A> std::ostream& operator<<(std::ostream& os, const TBinTreeItem<A>& obj) {
    std::shared_ptr<Figure> f = obj.item;
    f->Print();
    return os;
}

template <class T> std::shared_ptr<TBinTreeItem<T>> TBinTreeItem<T>::GetLeft() {
    return this->left;
}

template <class T> std::shared_ptr<TBinTreeItem<T>> TBinTreeItem<T>::GetRight() {
    return this->right;
}

template <class T> std::shared_ptr<TBinTreeItem<T>> 
    TBinTreeItem<T>::SetLeft(std::shared_ptr<TBinTreeItem<T>> &left) {
        std::shared_ptr<TBinTreeItem<T>> old = this->left;
        this->left = left;
        return old;
    }

template <class T> std::shared_ptr<TBinTreeItem<T>>
    TBinTreeItem<T>::SetRight(std::shared_ptr<TBinTreeItem<T>> &right) {
        std::shared_ptr<TBinTreeItem<T>> old = this->right;
        this->right = right;
        return old;
    }

template <class T> TBinTreeItem<T>::~TBinTreeItem() {
    std::cout << "BinTree item: deleted" << std::endl;
}

template <class T> void * TBinTreeItem<T>::operator new (size_t size) {
    std::cout << "Allocated :" << size << "bytes" << std::endl;
    return bintreeitem.allocate();
}
template <class T> void TBinTreeItem<T>::operator delete(void *p) {
    std::cout << "Deleted" << std::endl;
    bintreeitem.deallocate(p);
}


template class TBinTreeItem<Figure>;
template std::ostream& operator<<(std::ostream& os, const TBinTreeItem<Figure>& obj);