#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

int left(vector<bool> vec) {
    int ans = 0;

    for (size_t i = 0; i < vec.size(); ++i) {
        if (!vec[i])
            ++ans;
    }

    return ans;
}

int main(void) {
    setlocale(LC_ALL, "russian");
    time_t timet;
    srand((unsigned)time(&timet));

    const int cnt = 58;

    string words[cnt][2] = {
        { "amplification", "��������" },
        { "as well", "�����" },
        { "approximately", "�����, ��������������" },
        { "capacity", "��������, ��������, ������������������" },
        { "conduct", "�����, ���������" },
        { "cost", "���������" },
        { "duration", "�����������������" },
        { "enough", "����������, ��������" },
        { "entire", "������, �����" },
        { "fulfilment", "����������, �������������, ����������" },
        { "single", "����, ���������" },
        { "suggest", "����������, ����������" },
        { "tool", "����������, ������, ��������" },
        { "to meet the demands, the requirements", "������������� �����������" },
        { "in order to", "��� ���� �����" },
        { "power plant", "������� ���������, ��������������" },
        { "heat", "���������, �����, �������" },
        { "heating", "������" },
        { "heat-resistant", "������������" },
        { "indeed", "�������������, �� ����� ����" },
        { "installation", "���������, ������" },
        { "involved", "���������, ���������������, ������� �����" },
        { "rapidly", "������" },
        { "represent", "������������, ������������" },
        { "stimulate", "����������, ������������" },
        { "treatment", "���������" },
        { "vary", "������, ��������" },
        { "weapon", "������" },
        { "accurate", "������" },
        { "almost", "�����" },
        { "advanced", "��������, ���������" },
        { "construct", "�������, ���������" },
        { "crew", "������" },
        { "depth", "�������" },
        { "descend", "����������, ����������" },
        { "due to", "���������, ��-��" },
        { "explore", "�����������" },
        { "find out", "��������, ������" },
        { "image", "�����������" },
        { "instead of", "������" },
        { "join", "���������, ����������" },
        { "lift", "���������(��)" },
        { "mankind", "������������" },
        { "operate", "��������, �����������" },
        { "battery-operated", "���������� �� ��������" },
        { "particular", "������, ���������, ���������" },
        { "penetrate", "���������" },
        { "precision", "��������" },
        { "promise", "�������" },
        { "provided", "��� ������� ���; � ��� ������, ����" },
        { "realize", "������������, �������������" },
        { "resist", "��������������, �����������" },
        { "sample", "�������" },
        { "submerge", "�����������, ���������� ������" },
        { "test", "���������, ���������� ���������" },
        { "transparent", "����������" },
        { "try", "��������, ���������" },
        { "collect", "��������" }
    };

    int kek = 0;

    cout << "Chose mode: " << endl << "1 - endless" << endl << "2 - test" << endl;

    cin >> kek;
    string er;
    getline(cin, er);

    if (kek == 1) {
        while(true) {
            int num = rand() % cnt;
            string st = "";
            cout << "-----------------------" << endl;
            cout << words[num][1] << endl;
            
            getline(cin, st);

            if (st != words[num][0]) {
                cout << words[num][0] << endl << endl;
                cout << "Wrong!" << endl;
            } else {
                cout << "Good" << endl;
            }
        }
    }

    if (kek == 2) {

        int right = 0;
        vector<bool> mark(cnt);

        while (left(mark)) {
            vector<bool> tmp(cnt);
            int i = 1;
            while (left(tmp)) {
                int num = rand() % cnt;

                if (mark[num] == true || tmp[num] == true)
                    continue;


                string st = "";

                cout << "-----------------------" << endl;
                cout << i << " of " << cnt << endl << words[num][1]  << endl;

                getline(cin, st);

                if (st != words[num][0]) {
                    cout << words[num][0] << endl << endl;
                    cout << "Wrong!" << endl;
                }
                else {
                    cout << "Good" << endl;
                    mark[num] = true;
                    ++right;
                }
                tmp[num] = true;
                ++i;

            }

            cout << right << " �� " << cnt  << endl;
        }
    }

   
    return 0;
}