#include "vector.h"

Vector *vector_create()
{
	Vector *vec = (Vector*) malloc (sizeof(Vector));
	vec->cap = MIN_CAP;
	vec->data = (int*)malloc(sizeof(int) * MIN_CAP);
	vec->size = 0;

	return vec;
}

void vector_resize(Vector *vec)
{
	vec->cap *= 2;
	vec->data = (int*) realloc(vec->data, sizeof(int) * vec->cap);
}

void vector_push(Vector *vec, int elem)
{
	if (vec->size >= vec->cap)
		vector_resize(vec);
	
	vec->data[vec->size] = elem;
	vec->size++;
}

void vector_print(Vector *vec)
{
	for(int i = 0; i < 0; ++i)
	{
		printf("%d", vec->data[i]);
	}
}