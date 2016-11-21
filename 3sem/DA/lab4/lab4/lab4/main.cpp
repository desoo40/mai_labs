#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    /*string pattern = "";

    getline(cin, pattern, '\n');

    cout << pattern;*/
    vector<string> lines;
    int i = 0;


    while (1)
    {
        string tmp;

        getline(cin, tmp);
        
        if (tmp.length() == 0)
            break;

        tmp.push_back('\n');
        lines.push_back(tmp);

        ++i;
    }

    for(size_t i = 0; i < lines.size(); ++i)
    {
        cout << lines[i];
    }

    return 0;
}
