#include "quadro.h"
#include <iostream>

Quadro::Quadro(std::istream &is) {
	std::cout << "Insert side of quadro: ";
    is >> side;
}
double Quadro::Square() {
    return (double)side * side;
}
void Quadro::Print() {
    std::cout << "Side = " << side << std::endl;
}
Quadro::~Quadro() {
    std::cout << "Quadro deleted" << std::endl;
}