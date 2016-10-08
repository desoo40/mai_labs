#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

typedef struct {
	string word;
	bool mark;
} Words;

int main(void)
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);

     map<string, int> letter;

     int num_of_str = 0;

     cin >> num_of_str;

     vector<Words> words(num_of_str);

     for (int i = 0; i < num_of_str; ++i)
     {
     	if (of_two_chars())
     }
}