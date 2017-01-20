#include <iostream>
#include <cstdio>
#include "str.h"
#include "btree.h"
#include <fstream>

using namespace std;

int main()
{
	TString action;
    TBTree bTree(5);

	while (cin >> action)
	{
		if (action == "+")
		{
			Word *word = new Word;

			cin >> word->line >> word->key;

            word->line.ToLower();

            if (bTree.search(word->line) != nullptr)
                cout << "Exist" << endl;
            else {
                bTree.InsertWord(word);
                cout << "Add" << endl;
            }
            continue;
		}

		if (action == "-")
		{
            TString del_string = "";

            cin >> del_string;
            bTree.DeleteWord(del_string);
			cout << "OK" << endl;
            
            continue;
		}

		if (action == "!")
		{
			TString type, path;
            cin >> type >> path;

			if (type == "Save") {
                ofstream fileWrite;
                fileWrite.open(path.ToCharsArr());

                if (!fileWrite) {
                    cout << "ERROR: can't open file\n";
                }
                else {
                    bTree.Serialization(bTree.root, &fileWrite);
                    fileWrite.close();
                    cout << "OK\n";
                }
			}

            else if (type == "Load") {
                ifstream fileRead;
                fileRead.open(path.ToCharsArr());
                if (!fileRead) {
                    cout << "ERROR: can't open file\n";
                }
                else {
                    bTree.Deserialization(&bTree.root, &fileRead);
                    fileRead.close();
                    cout << "OK\n";
                }
            }
            continue;
		}
		
        Word *find = bTree.search(action);

        if (find != nullptr)
            cout << "OK: " << find->key << endl;
        else
            cout << "NoSuchWord" << endl;

	}
}