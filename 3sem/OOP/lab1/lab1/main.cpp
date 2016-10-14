#include <cstdlib>
#include "triangle.h"
#include "quadro.h"
#include "rectangle.h"

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
        
        Figure *ptr = NULL;

        if (i == 0) {
            break;
        }
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
            std::cout << "Wrong input, try again" << std::endl;
            continue;
        }

        ptr->Print();
        std::cout << "Square = " << ptr->Square() << std::endl;
        delete ptr;
    }
    
    return 0;
}