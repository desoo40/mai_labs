#include "triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle(std::istream &is) {
    is >> side_a;
    is >> side_b;
    is >> side_c;
}
double Triangle::Square() {
    double p = double(side_a + side_b + side_c) / 2.0;
    return sqrt(p * (p - double(side_a)) * (p - double(side_b)) * (p -
        double(side_c)));
}
void Triangle::Print() {
    std::cout << "a = " << side_a << std::endl
              << "b = " << side_b << std::endl
              << "c = " << side_c << std::endl;
    std::cout << "Square = ";
}
Triangle::~Triangle() {
    std::cout << "Triangle deleted" << std::endl;
}
