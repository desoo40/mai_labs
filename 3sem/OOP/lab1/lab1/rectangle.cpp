#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle(std::istream &is) {
    is >> side_a;
    is >> side_b;
}
double Rectangle::Square() {
    return side_a * side_b;
}
void Rectangle::Print() {
    std::cout << "a = " << side_a << std::endl
              << "b = " << side_b << std::endl;
}
Rectangle::~Rectangle() {
    std::cout << "Rectangle deleted" << std::endl;
}