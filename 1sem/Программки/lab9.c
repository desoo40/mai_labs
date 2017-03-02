#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int i0 = 10;
int jo = 20;
int l0 = -1;

const int SqrL = 10;
const int SqrCentX = 10;
const int SqrCentY = -10;

_Bool IsPointInSquare(int x, int y);
int Max(int a, int b);
int Min(int a, int b);
int Minh(int a, int b, int c);
int Sign(int Val);

int main(void)
{

   	int i = i0;
   	int j = jo;
    	int l = l0;

	_Bool popali;

	for (int k = 0; k < 50; k++)
	{
	popali = IsPointInSquare(i, j);

	if (popali)

	{
	printf("On %d step hit the square. Coordinates (%d;%d). Response parametr = %d", k, i, j, l);
	break;
	}

	i = (abs(Max(i*(k+5), j*(k+6))) - abs(Min(j*(k+7), l*(k+8)))) % 20;
	j = ((3 - Sign(i - j))* abs(Minh((i*l + 5), (j*l - 3), (i*j + 6)))) % 25 - 7;
	l = i % 10 + j % 10 + l % 10;

	printf("Step %d.Coordinates (%d;%d). Response parametr = %d \r\n", k+1, i, j, l);

	}

if (!popali)
printf("Miss square. Coordinates last step (%d;%d). Response parametr - %d", i, j, l);

getchar();
return 0;
}

_Bool IsPointInSquare(int x, int y)
{
int SqrLeft = SqrCentX - SqrL / 2;
int SqrRigth = SqrCentX + SqrL / 2;
int SqrTop = SqrCentY - SqrL / 2;
int SqrBottom = SqrCentY + SqrL / 2;

if (x < SqrLeft) return false;
if (x > SqrRigth) return false;
if (y < SqrTop) return false;
if (y > SqrBottom) return false;

return true;
}

int Max(int a, int b)
{
if (a > b) return a;
else return b;
}

int Min(int a, int b)
{
if (a < b) return a;
else return b;
}

int Minh(int a, int b, int c)
{
if (a<b)
{
if (a < c) return a;
else return c;
}
else
{
if (b < c) return b;
else return c;
}
}

int Sign(int Val) {
if (Val == 0) return 0;
if (Val > 0) return 1;
else return -1;
}

/*
desoo@ubuntustan:~$ gcc -std=c99 -Wall -pedantic lab9.c
desoo@ubuntustan:~$ ./a.out
Step 1.Coordinates (12;10). Response parametr = 1 
Step 2.Coordinates (3;-4). Response parametr = 0 
Step 3.Coordinates (-15;5). Response parametr = 0 
Step 4.Coordinates (5;2). Response parametr = 7 
Step 5.Coordinates (3;15). Response parametr = 15 
Step 6.Coordinates (-15;-2). Response parametr = -2 
Step 7.Coordinates (-4;-3). Response parametr = -9 
Step 8.Coordinates (-16;14). Response parametr = -11 
Step 9.Coordinates (0;-4). Response parametr = -5 
Step 10.Coordinates (-5;11). Response parametr = -9 
Step 11.Coordinates (14;10). Response parametr = -5 
Step 12.Coordinates (9;5). Response parametr = 9 
Step 13.Coordinates (18;2). Response parametr = 19 
Step 14.Coordinates (4;-4). Response parametr = 9 
Step 15.Coordinates (-8;11). Response parametr = 2 
Step 16.Coordinates (5;3). Response parametr = 10 
Step 17.Coordinates (16;-3). Response parametr = 3 
Step 18.Coordinates (0;17). Response parametr = 10 
Step 19.Coordinates (8;8). Response parametr = 16 
Step 20.Coordinates (-8;10). Response parametr = -2 
Step 21.Coordinates (4;10). Response parametr = 2 
Step 22.Coordinates (12;2). Response parametr = 6 
Step 23.Coordinates (6;11). Response parametr = 13 
Step 24.Coordinates (-11;-5). Response parametr = -3 
Step 25.Coordinates (-5;4). Response parametr = -4 
Step 26.Coordinates (-8;-3). Response parametr = -15 
Step 27.Coordinates (-14;11). Response parametr = -8 
Step 28.Coordinates (3;7). Response parametr = 2 
Step 29.Coordinates (6;12). Response parametr = 10 
Step 30.Coordinates (10;13). Response parametr = 3 
Step 31.Coordinates (14;15). Response parametr = 12 
Step 32.Coordinates (7;-1). Response parametr = 8 
Step 33.Coordinates (0;15). Response parametr = 13 
Step 34.Coordinates (12;12). Response parametr = 7 
Step 35.Coordinates (6;6). Response parametr = 19 
Step 36.Coordinates (-6;4). Response parametr = 7 
Step 37.Coordinates (-4;10). Response parametr = 3 
Step 38.Coordinates (15;-3). Response parametr = 5 
Step 39.Coordinates (10;16). Response parametr = 11 
Step 40.Coordinates (3;-5). Response parametr = -1 
Step 41.Coordinates (0;-3). Response parametr = -4 
Step 42.Coordinates (-16;4). Response parametr = -6 
Step 43.Coordinates (-8;1). Response parametr = -13 
Step 44.Coordinates (-14;7). Response parametr = 0 
Step 45.Coordinates (10;-1). Response parametr = -1 
Step 46.Coordinates (7;-3). Response parametr = 3 
Step 47.Coordinates (18;14). Response parametr = 15 
Step 48.Coordinates (0;13). Response parametr = 8 
Step 49.Coordinates (14;-5). Response parametr = 7 
On 49 step hit the square. Coordinates (14;-5). Response parametr = 7

*/



