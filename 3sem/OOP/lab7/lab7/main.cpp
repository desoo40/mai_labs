#include <cstdlib>
#include <iostream>
#include <memory>
#include "Triangle.h"
#include "TStack.h"
#include "BTree.h"
#include "IRemoveCriteriaByValue.h"
#include "IRemoveCriteriaAll.h"
#include "quadro.h"
#include "rectangle.h"

int main(int argc, char** argv) {
    TStack<BTree<Figure>, Figure> stack;

    stack.InsertSubitem(new Rectangle(1, 1));
    stack.InsertSubitem(new Quadro(2));
    stack.InsertSubitem(new Triangle(3, 1, 1));
    stack.InsertSubitem(new Rectangle(4, 1));
    stack.InsertSubitem(new Quadro(5));
    stack.InsertSubitem(new Triangle(6, 1, 1));
    stack.InsertSubitem(new Triangle(7, 1, 1));
    std::cout << stack << std::endl;

    IRemoveCriteriaByValue<Figure> criteria(Triangle(7, 1, 1));
    IRemoveCriteriaAll<Figure> criteriaAll;
    stack.RemoveSubitem(&criteria);
    stack.RemoveSubitem(&criteriaAll);

    std::cout << stack << std::endl;
    return 0;
}
