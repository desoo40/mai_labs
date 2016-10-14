#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <map>
#include <cctype>
#include <cwctype>
#include <stdexcept>
#include <queue>

using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;

    cin >> n;

    queue<string> que;

    que.push("Sheldon");
    que.push("Leonard");
    que.push("Penny");
    que.push("Rajesh");
    que.push("Howard");

    for (int i = 1; i < n; ++i)
    {
        string tmp = que.front();

        que.push(tmp);
        que.push(tmp);

        que.pop();
    }

    cout << que.front() << endl;

    return 0;
}