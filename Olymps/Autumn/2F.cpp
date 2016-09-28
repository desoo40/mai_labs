#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <map>
#include <cctype>
#include <cwctype>
#include <stdexcept>
#include <cmath>

#define mod_h 24
#define mod_m 60

using namespace std;

typedef struct _time {
	int h;
	int m;
} Time;

Time mod(Time s)
{
	if (s.m >= mod_m)
	{
		s.h += s.m / mod_m;
		s.m %= mod_m;
	}

	if (s.h >= mod_h)
		s.h %= mod_h;

	return s;
}

Time multiply_struct(Time s, int a)
{
	s.h *= a;
	s.m *= a;

	s = mod(s);

	return s;
}

int main(void)
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);

    Time res;
    Time cl;
    Time br;

    int cl_qty;

    cin >> res.h >> res.m >> cl.h >> cl.m >> br.h >> br.m >> cl_qty;


    cl = multiply_struct(cl, cl_qty);
    br = multiply_struct(br, cl_qty - 1);

    res.h += cl.h + br.h;
    res.m += cl.m + br.m;

    res = mod(res);
    
    cout << res.h << " " << res.m << endl;

    return 0;
}