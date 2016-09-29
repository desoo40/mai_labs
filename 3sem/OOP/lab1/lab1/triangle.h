#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"
class Triangle : public Figure {
public:
    Triangle();
    Triangle(std::istream &is);
    double Square() override;
    void Print() override;
    virtual ~Triangle();
private:
    size_t side_a;
    size_t side_b;
    size_t side_c;
};
#endif