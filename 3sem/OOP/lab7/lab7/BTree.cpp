#include "BTree.h"
#include "figure.h"

class Figure;

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
   
    std::shared_ptr<Figure> oth = this->getElem();
    std::shared_ptr<Figure> it = item;



    if (oth->Square() < it->Square()) {
        if (this->left == nullptr) {
            this->left = std::shared_ptr<BTree>(new BTree(item));
            return;
        }

        std::shared_ptr<BTree<T>> other(new BTree<T>(item));
        if (other == nullptr)
            return;

        other->setLeft(left);
        left = other;
    } 

    if (oth->Square() > it->Square()) {
        if (this->right == nullptr) {
            this->right = std::shared_ptr<BTree>(new BTree(item));
            return;
        }

        std::shared_ptr<BTree<T>> other(new BTree<T>(item));
        if (other == nullptr)
            return;

        other->setRight(right);
        left = other;
    }
  
   
}

template<class T>
void BTree<T>::del(T *item) {
    std::shared_ptr<BTree> par = elem;
    if (item->left == NULL && item->right == NULL) {
        if (par != NULL) {
            if (par->left == item)
                par->left = NULL;

            if (par->right == item)
                par->right = NULL;

            delete item;
            item = NULL;
        }
        else {
            delete item;
           item = NULL;
        }
        return;
    }

    if (item->left != NULL && item->right == NULL) {
        if (par != NULL) {
            if (par->left == item)
                par->left = item->left;
            if (par->right == item)
                par->right = item->left;
        }
        else
            elem = item->left;

    }

    if (item->left == NULL && item->right != NULL) {
        if (par != NULL) {
            if (par->left == item)
                par->left = item->right;
            if (par->right == item)
                par->right = item->right;
        }
        else
            elem = item->right;

        delete item;
        item = NULL;
        return;
    }

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
bool BTree<T>::empty() {
    return (elem == nullptr);
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
