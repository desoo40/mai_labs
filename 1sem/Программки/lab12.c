#include <stdio.h>


int main(void)
{
	char buffer[100]; //not initialized!
	
	printf("Type value (3 < length < 100): ");
	scanf("%99s", buffer);

	int eol_position = 0;
	for (int i = 0; i < sizeof(buffer); ++i)
	{
		if (buffer[i] == '\0')
		{
			if (i < 4) // 0123 and 4 as '/0'
			{
				printf("Too small value, bye.\n");
				return 0;
			}
			eol_position = i;
			break;
		}		
	}
	
	printf("Original %s \n", buffer);
	
	char temp = buffer[1];
	buffer[1] = buffer[eol_position - 2];
	buffer[eol_position - 2] = temp;
	printf("Modified %s \n", buffer);
	
	getchar ();
	return 0;
}