#include "TBinaryTree.h"

template <class T> TBinaryTree<T>::TBinaryTree() : root(nullptr), ElemQty(0) {
}

template <class T> std::ostream& operator<<(std::ostream& os, const
    TBinaryTree<T>& bintree) {
    std::shared_ptr<TBinTreeItem<T>> item = bintree.root;

    while (item != nullptr)
    {
        os << *item;
        item = item->GetLeft();
    }

    if (item->left != nullptr)
        os << item->left;

    if (item->right != nullptr)
        os << item->right;

    return os;
}

template <class T>
void TBinaryTree<T>::Add(std::shared_ptr<T>&& item) {

    if (item == nullptr) {
        return;
    }

    if (val >= item->data) {
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