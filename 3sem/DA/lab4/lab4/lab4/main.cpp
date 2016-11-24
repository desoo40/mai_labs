#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<unsigned long> FillString() {
    vector<unsigned long> str;
    char c = '!';
    char last_ch = '!';
    unsigned long tmp = 0;

    while(cin.get(c)) {
        //c = getchar();
        
        if (c == '\n') {
            if (last_ch == ' ') {
                return str;
            }

            str.push_back(tmp);
            return str;
        }

        if (c == ' ') {
            if (last_ch == ' ') {
                continue;
            }

            str.push_back(tmp);
            tmp = 0;
            last_ch = c;
            continue;
        }

        tmp *= 10;
        tmp += c - 48;
        last_ch = c;
    }

    str.push_back(tmp);
    return str;
}

vector<vector<unsigned long>> FillText() {
    vector<vector<unsigned long>> text;

    while(!cin.eof()) {
        text.push_back(FillString());
    }
    
    return text;
}

int main()
{
    vector<unsigned long> pattern;
    vector<vector<unsigned long>> text;

    pattern = FillString();
    text = FillText();

    for (size_t i = 0; i < pattern.size(); ++i)
            {
        cout << pattern[i] << ' ';
            }
}
