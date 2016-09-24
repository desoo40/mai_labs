#include "vector.h"

TVector *VectorCreate() {
    TVector *vec = new TVector;
    vec->cap = MIN_CAP;
    vec->size = 0;

    return 0;
}

void VectorResize(TVector *vec) {
    vec->cap *= 2;
    ve
}
void VectorPush(TVector *vec, size_t elem);
void VectorPrint(TVector *vec);