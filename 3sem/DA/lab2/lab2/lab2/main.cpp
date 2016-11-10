#include <iostream>
#include <cstdio>
#include "str.h"
#include "btree.h"

using namespace std;

int main()
{
	TString action;
    TBTree bTree(4);

	while (cin >> action)
	{
		if (action == "+")
		{
			Word *word = new Word;

			cin >> word->line >> word->line;

            bTree.InsertWord(word);

			cout << "Add" << endl;
		}
		else if (action == "-")
		{
			cout << "Delete" << endl;
		}
		else if (action == "!")
		{
			TString type;
			cin >> type;
			if (type == "Save") {
				cout << "Save" << endl;
			}
			else if (type == "Load") {
				cout << "Load" << endl;
			}
		}
		else {
			cout << "Search for key [" << action << ']' << endl;
		}
	}
}