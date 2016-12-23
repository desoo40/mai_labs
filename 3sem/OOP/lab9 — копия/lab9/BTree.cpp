#include "BTree.h"

template <class T>
BTree<T>::BTree() : elem(nullptr) {
    this->left = nullptr;
    this->right = nullptr;
}

template<class T>
BTree<T>::BTree(std::shared_ptr<T> item) {
    this->elem = item;
    this->left = nullptr;
    this->right = nullptr;
}


template<class T>
void BTree<T>::add(std::shared_ptr<T> item) {
    if (this->elem == nullptr) {
        this->elem = item;
        return;
    }

    if (this->left == nullptr) {
        this->left = std::shared_ptr<BTree>(new BTree(item));
        return;
    } 

    if (this->right == nullptr) {
        this->right = std::shared_ptr<BTree>(new BTree(item));
        return;
    }

    add(this->left);
    
   
  
}

template<class T>
void BTree<T>::del(T *item) {

}

template<class T>
std::shared_ptr<T> BTree<T>::getElem() {
    return this->elem;
}

template<class T>
std::shared_ptr<BTree<T>> BTree<T>::getLeft() {
    return this->left;
}

template<class T>
std::shared_ptr<BTree<T>> BTree<T>::getRight() {
    return this->right;
}

template<class T>
BTree<T>::~BTree() {
}


#include <functional>
template class BTree<std::function<void(void)>>;
