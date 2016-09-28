#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <map>
#include <cctype>
#include <cwctype>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int points = 0;
	int jlobs_speed = 50;
	int sign_for_life = 0;
	double summary_line = 0;
	double wasted_time = 0;
	int x1, y1 = 0;

	cin >> points >> sign_for_life;
	cin >> x1 >> y1;

	for (int i = 1; i < points; ++i)
	{
		int x2, y2= 0;

		cin >> x2 >> y2;

		summary_line += sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

		x1 = x2;
		y1 = y2;
	}

	wasted_time = (sign_for_life * summary_line) / jlobs_speed;

	printf("%.6f\n", wasted_time);

	return 0;
}