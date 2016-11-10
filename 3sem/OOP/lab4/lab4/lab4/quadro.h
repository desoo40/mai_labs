#ifndef QUADRO_H
#define QUADRO_H
#include <cstdlib>
#include <iostream>
#include "figure.h"

class Quadro : public Figure {
public:
    Quadro(std::istream &is);
    void Print() override;
    virtual ~Quadro();
private:
    size_t side;
};

#endif
