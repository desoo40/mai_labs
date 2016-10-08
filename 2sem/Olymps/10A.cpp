#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <map>
#include <ctime>


#define MAX 1000000001
#define MIN 0

using namespace std;

int main()
{
	srand( time( 0 ) );
	int dig = rand() % MAX;
	int left = MIN;
	int right = MAX;
	char c;

	cout << dig << endl;
	cout.flush();

	cin >> c;

	if (c == '=') 
		return 0;
	if (c == '>')
		right = dig;
	if (c == '<')
		left = dig;

	int mid = (left + right) / 2;
	dig = mid;

	while (1)
	{
		cout << dig << endl;
		cout.flush();

		cin >> c;

		if (c == '=') 
				return 0;

		if (c == '>') {
			right = dig;
			mid = (right + left) / 2;
			dig -= dig - mid;
		} else if (c == '<') {
			left = mid;
			mid = (right + left) / 2;
			dig += mid - dig;
		}	
	}
}