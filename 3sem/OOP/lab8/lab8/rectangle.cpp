#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle(std::istream &is) {
	std::cout << "Insert side A: ";
    is >> side_a;
	std::cout << "Insert side B: ";
    is >> side_b;
}
Rectangle::Rectangle(size_t a, size_t b) {
    side_a = a;
    side_b = b;
}
double Rectangle::Square() {
    return side_a * side_b;
}
void Rectangle::Print() {
    std::cout << "It's Rectangle" << std::endl 
              << "a = " << side_a << std::endl
              << "b = " << side_b << std::endl;
}
Rectangle::~Rectangle() {
    std::cout << "Rectangle deleted" << std::endl;
}