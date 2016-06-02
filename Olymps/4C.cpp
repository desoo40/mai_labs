#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <limits.h>

using namespace std;

typedef struct {
	string poster;
	strings reposter;
} Prepost;

typedef struct {
	string post;
	strings repost;
} Post;

int main()
{
	int strings = 0;
	int limit = 1;
	int max_qty = 0;

	cin >> strings;

	vector<Post> post(strings);
	vectot<bool> mark(strings, false);

	for (int i = 0; i < strings; ++i)
	{
		cin >> post[i].reposter >> post[i].poster >> post[i].poster;
	}

	Prepost.reposter = post[0].reposter;
	Prepost.poster = post[0].poster,

	while (limit < strings)
	{
		for (int i = 1; i < strings; ++i)
		{
			if (!mark[i]) {
				if (post[i].post == Prepost.poster) {

				}
			}
		}
	}

	
	return 0;
}