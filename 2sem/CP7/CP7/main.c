#include "vector.h"

int main(int argc, char const *argv[])
{
	/*if (argc != 2) 
	{
		printf("Wrong input\n");
		return;
	}*/

	int rows = 0;
	int columns = 0;

	printf("Insert rows and columns of your matrix: \n");
	scanf("%d%d", &rows, &columns);

	Vector *vector_of_places = vector_create();
	Vector *vector_of_values = vector_create();

	FILE *in = fopen("test.txt", "r");

	for (int i = 0; i < rows * columns; ++i)
	{
		int elem = 0;
		fscanf(in, "%d", &elem);

		if (elem == 0)
			continue;

		vector_push(vector_of_places, i);
		vector_push(vector_of_values, elem);
	}
	
	vector_print(vector_of_places);
	vector_print(vector_of_values);

	return 0;

}