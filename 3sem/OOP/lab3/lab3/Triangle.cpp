#include "triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle(std::istream &is) {
	std::cout << "Insert side A: ";
	is >> side_a;
	std::cout << "Insert side B: ";
	is >> side_b;
	std::cout << "Insert side C: ";
	is >> side_c;
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
