#include "triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle(size_t a, size_t b, size_t c) {
    side_a = a;
    side_b = b;
    side_c = c;
}

Triangle::Triangle(std::istream &is) {
    std::cout << "Insert side A: ";
    is >> side_a;
    std::cout << "Insert side B: ";
    is >> side_b;
    std::cout << "Insert side C: ";
    is >> side_c;
}
double Triangle::Square() {
    double p = double(side_a + side_b + side_c) / 2.0;
    return sqrt(p * (p - double(side_a)) * (p - double(side_b)) * (p -
        double(side_c)));
}
void Triangle::Print() {
    std::cout << "It's Triangle" << std::endl
        << "a = " << side_a << std::endl
        << "b = " << side_b << std::endl
        << "c = " << side_c << std::endl;
}
Triangle::~Triangle() {
    std::cout << "Triangle deleted" << std::endl;
}