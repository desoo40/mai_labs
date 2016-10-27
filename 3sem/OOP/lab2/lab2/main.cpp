#include <cstdlib>
#include <iostream>
#include "Triangle.h"
#include "TStackItem.h"
#include "TStack.h"
// Simple stack on pointers

void isEqual (Triangle tr1, Triangle tr2)
{
    if (tr1 == tr2)
    {
        std::cout << "Same" << std::endl;
    }
    else
    {
        std::cout << "Different" << std::endl;
    }
}

int main(int argc, char** argv) {

    TStack stack;

    stack.push(Triangle(1, 1, 1));
    stack.push(Triangle(2, 2, 2));
    stack.push(Triangle(3, 3, 3));

    std::cout << stack;


    Triangle t, tmp1, tmp2;

    t = stack.pop(); std::cout << t;
    t = stack.pop(); std::cout << t;
    t = stack.pop(); std::cout << t;

    t = Triangle(15, 15, 15);
    tmp1 = Triangle(20, 15, 15);

    isEqual(t, tmp1);

    tmp1 = t;

    isEqual(t, tmp1);

    return 0;
}
