#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<size_t> FillTheR(string str)
{
    vector<size_t> ans(10);
    
    for (size_t i = 0; i < str.length(); ++i) {
        ++ans[str[i] - 48] = i;
    }

    return ans;
}

int main()
{
    string pattern = "";
    getline(cin, pattern, '\n');
   
    vector<size_t> R(10);

    R = FillTheR(pattern);

    vector<string> lines;

    for (size_t i = 0; ; ++i)
    {
        string tmp;

        getline(cin, tmp);
        
        if (tmp.length() == 0)
            break;

        tmp.push_back('\n');
        lines.push_back(tmp);
    }

    for(size_t i = 0; i < lines.size(); ++i)
    {
        cout << lines[i];
    }

    return 0;
}
