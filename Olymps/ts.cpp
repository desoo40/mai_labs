#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv)
{
	FILE *out = fopen(argv[1], "w");

	fprintf(out, "%d %d\n", 23278, 94524);

	for (int i = 0; i < 23278; ++i)
	{	if(i < 12000)
			fprintf(out, "%d ", -1);
		else
			fprintf(out, "%d ", 1);
	}

	fclose(out);
	return 0;
}