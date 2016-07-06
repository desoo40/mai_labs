#ifndef _VECTOR_H_
#define _VECTOR_H_


#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>

#define MIN_CAP 8
typedef struct _vector Vector;

struct _vector
{
	int *data;
	int size;
	int cap;
};

Vector *vector_create();
void vector_resize(Vector *vec);
void vector_push(Vector *vec, int elem);
void vector_print(Vector *vec);

#endif 
