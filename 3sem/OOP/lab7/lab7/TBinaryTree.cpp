#include "TBinaryTree.h"
#include "figure.h"

template <class T> TBinaryTree<T>::TBinaryTree() : root(nullptr), ElemQty(0) {
}

template <class T> std::ostream& operator<<(std::ostream& os, const
    TBinaryTree<T>& bintree) {
    std::shared_ptr<TBinTreeItem<T>> item = bintree.root;

    if (item == nullptr) {
        os << "Tree is empty" << std::endl;
        return os;
    } else {
        os << *item;
    }

    if (item->left != nullptr)
        os << item->GetLeft();

    if (item->right != nullptr)
        os << item->GetRight();

    return os;
}

template <class T>
void TBinaryTree<T>::Add(std::shared_ptr<T>&& item) {
    
    if (item == nullptr) {
        return;
    }

    std::shared_ptr<TBinTreeItem<T>> other(new TBinTreeItem<T>(item));

    std::shared_ptr<Figure> f = other->GetItem();
    double val = f->Square();

    if (val >= (root->GetItem())) {
        if (item->right == NULL) {
            item->right = item_create(val);
            return;
        }
        else
            tree_elem_add(item->right, val);

    }
    else {
        if (item->left == NULL) {
            item->left = item_create(val);
            return;
        }
        else
            tree_elem_add(item->left, val);
    }
}

template<class T>
bool TBinaryTree<T>::Empty() const {
    return ElemQty > 0;
}


template <class T> TBinaryTree<T>::~TBinaryTree() {
}

#include "figure.h"
template class TBinaryTree<Figure>;
template std::ostream& operator<<(std::ostream& os, const TBinaryTree<Figure>&
    stack);