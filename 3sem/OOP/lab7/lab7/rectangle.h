#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <cstdlib>
#include <iostream>
#include "figure.h"

class Rectangle : public Figure {
public:
    Rectangle(std::istream &is);
    double Square() override;
    void Print() override;
    virtual ~Rectangle();
private:
    size_t side_a;
    size_t side_b;
};

#endif
