#include "quadro.h"
#include <iostream>

Quadro::Quadro(std::istream &is) {
    is >> side;
}
double Quadro::Square() {
    return side * side;
}
void Quadro::Print() {
    std::cout << "Side = " << side << std::endl;
    std::cout << "Square = ";
}
Quadro::~Quadro() {
    std::cout << "Quadro deleted" << std::endl;
}