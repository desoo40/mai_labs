#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <climits>
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
            if (last_ch == ' ' || last_ch == '!') {
                return str;
            }

            str.push_back(tmp);
            return str;
        }

        if (c == ' ') {
            if (last_ch == ' ' || last_ch == '!') {
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

    if (!cin.eof()) {
        str.push_back(tmp); //чтобы не навернулось, при возможном конце ввода без конца строки
    }

    return str;
}

vector<vector<unsigned long>> FillText() {
    vector<vector<unsigned long>> text;

    while(!cin.eof()) {
        text.push_back(FillString());
    }
    
    return text;
}

void Test(vector<unsigned long> pattern,
vector<vector<unsigned long>> text) {
    for (size_t i = 0; i < pattern.size(); ++i)
    {
        cout << pattern[i] << ' ';
    }
    cout << endl;
    for (size_t i = 0; i < text.size(); ++i)
    {
        for (size_t j = 0; j < text[i].size(); ++j)
        {
            cout << text[i][j] << ' ';
        }
        cout << endl;
    }
}

map<unsigned long, int> BadCharRule(vector<unsigned long> pat) {
    map<unsigned long, int> BC;
    int patLen = pat.size();

    for (int i = 0; i < pat.size() - 1; ++i) {
        BC[pat[i]] = patLen - i - 1;
    }

    return BC;
}

bool IsPrefix(vector<unsigned long> pat, int p) {
    int j = 0;
    for (int i = p; p < pat.size() - 1; ++i) {
        if (pat[i] != pat[j]) {
            return false;
        }
        ++j;
    }

    return true;
}

int SuffLenght(vector<unsigned long> pat, int p) {
    int len = 0;
    int i = p;
    int j = pat.size() - 1;

    while (i >= 0 && pat[i] == pat[j]) {
        ++len;
        --i;
        --j;
    }

    return len;
}

vector<int> GoodSuffRule(vector<unsigned long> pat) {
    int patLen = pat.size();
    vector<int> GS (patLen);
    int lastPrefixPosition = patLen;

    for (int i = patLen - 1; i >= 0; --i) {
        if (IsPrefix(pat, i + 1)) {
            lastPrefixPosition = i + 1;
        }
        GS[patLen - 1 - i] = lastPrefixPosition - i + patLen - 1;
    }

    for (int i = 0; i < patLen - 2; ++i) {
        int suffLen = SuffLenght(pat, i);
        GS[suffLen] = patLen - 1 - i + suffLen;
    }

    return GS;
}

int main()
{
    vector<unsigned long> pattern;
    vector<vector<unsigned long>> text;
    
    vector<int> answer;

    pattern = FillString();
    text = FillText();

    int patLen = pattern.size();
    int textLen = text[0].size();

    map<unsigned long, int> BadChar;
    vector<int> GoodSuff;

    BadChar = BadCharRule(pattern);
    GoodSuff = GoodSuffRule(pattern);

    for (int i = patLen -1; i <= textLen - 1;) {
        int j = patLen - 1;

        while (pattern[j] == text[0][i]) {
            if (j == 0) {
                answer.push_back(i + 1);
                break;
            }
            --i;
            --j;
        }
        int tmp = max(GoodSuff[patLen - 1 - j],BadChar[text[0][i]]);
        if (tmp == 0) {
            tmp = patLen;
        }
        i += tmp;
    }
    

    for (int i = 0; i < answer.size(); ++i) {
        cout << answer[i] << endl;
    }
    //Test(pattern, text);
    
    return 0;
}
