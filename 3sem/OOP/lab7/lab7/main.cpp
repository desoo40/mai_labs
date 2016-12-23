#include <cstdlib>
#include <iostream>
#include <memory>
#include "Triangle.h"
#include "TStack.h"
#include "BTree.h"
#include "IRemoveCriteriaByValue.h"
#include "IRemoveCriteriaAll.h"
int main(int argc, char** argv) {
    TStack<BTree<Figure>, Figure> list;

    list.InsertSubitem(new Triangle(1, 1, 1));
    list.InsertSubitem(new Triangle(2, 1, 1));
    list.InsertSubitem(new Triangle(3, 1, 1));
    list.InsertSubitem(new Triangle(4, 1, 1));
    list.InsertSubitem(new Triangle(5, 1, 1));
    list.InsertSubitem(new Triangle(6, 1, 1));
    list.InsertSubitem(new Triangle(7, 1, 1));
    std::cout << list << std::endl;

    IRemoveCriteriaByValue<Figure> criteria(Triangle(4, 1, 1));
    IRemoveCriteriaAll<Figure> criteriaAll;
    list.RemoveSubitem(&criteria);



    std::cout << list << std::endl;
    return 0;
}