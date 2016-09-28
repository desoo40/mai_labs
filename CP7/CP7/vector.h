#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>

const int MIN_CAP = 8;

class TVector {
public:
    size_t data;
    size_t size = 0;
    size_t cap = 0;
};

TVector *vector_create();
void vector_resize(TVector *vec);
void vector_push(TVector *vec, size_t elem);
void vector_print(TVector *vec);

#endif 
