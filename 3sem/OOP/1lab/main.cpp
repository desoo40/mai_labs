#include <cstdlib>
#include "triangle.h"
#include "rectangle.h"
#include "quadro.h"

void Tips() {
    std::cout << "1 - Triangle"  << std::endl
              << "2 - Quadro"    << std::endl
              << "3 - Rectangle" << std::endl
              << "0 - end"       << std::endl;
}

int main(int argc, char** argv) {
    
    Tips();

    while (1) {
        short i = 0;
        std::cin >> i;

        if (i == 0) {
            break;
        }

        if (i < 0 || i > 3) {
            std::cout << "Wrong input, try again" << std::endl;
            Tips();
            continue;
        }

        Figure *ptr = NULL;

        if (i == 1) {
            ptr = new Triangle(std::cin);
        }
        if (i == 2) {
            ptr = new Quadro(std::cin);
        }
        if (i == 3) {
            ptr = new Rectangle(std::cin);
        }

        if (ptr == NULL) {
            std::cout << "Miss..." << std::endl;
            break;
        }

        ptr->Print();
        std::cout << ptr->Square() << std::endl;
        delete ptr;
    }

    return 0;
}