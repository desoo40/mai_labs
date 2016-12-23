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
  
    std::shared_ptr<BTree<T>> other(new BTree<T>(item));
    if (other == nullptr)
        return;

    other->setLeft(left);
    left = other;
}

template<class T>
void BTree<T>::del(T *item) {

}

template<class T>
std::shared_ptr<T> BTree<T>::getElem() {
    return this->elem;
}

template<class T>
std::shared_ptr<BTree<T>> BTree<T>::setLeft(std::shared_ptr<BTree> left1) {
    std::shared_ptr<BTree<T>> old = this->left;
    this->left = left1;
    return old;
}

template<class T>
std::shared_ptr<BTree<T>> BTree<T>::setRight(std::shared_ptr<BTree> right1) {
    std::shared_ptr<BTree<T>> old = this->right;
    this->right = right1;
    return old;
}

template<class T>
size_t BTree<T>::size() {
    return detour(this, 0);
}

template<class T>
int BTree<T>::detour(BTree<T> b, int a) {

    if (getElem() == nullptr)
        return a;

    int f = 0;
    int g = 0;

    if (getLeft())
        f = detour(getLeft(), a + 1);

    if (getRight())
        g = detour(getRight(), a + 1);

    return f + g;
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
