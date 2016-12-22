#include "quadro.h"
#include <iostream>

Quadro::Quadro(std::istream &is) {
	std::cout << "Insert side of quadro: ";
    is >> side;
}
double Quadro::Square() {
    return side * side;
}
void Quadro::Print() {
    std::cout << "It's Quadro" << std::endl << "Side = " << side << std::endl;
}
Quadro::~Quadro() {
    std::cout << "Quadro deleted" << std::endl;
}