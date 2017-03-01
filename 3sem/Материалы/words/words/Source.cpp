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

    const int cnt = 57;

    string words[cnt][2] = {
        { "according to", "��������, �������������" },
        { "available", "��������� ��������� � ������������" },
        { "beam", "���" },
        { "built-in", "����������" },
        { "by means of", "�����������, ��� ������" },
        { "calculation", "����������" },
        { "capable", "���������" },
        { "circuit", "�����, ����" },
        { "close", "�������, ������" },
        { "complete", "���������" },
        { "control", "���������, ��������������" },
        { "depend on", "�������� ��" },
        { "fast", "�������" },
        { "generation", "���������" },
        { "go on", "����������" },
        { "machine-tool", "������" },
        { "matter", "����, ������" },
        { "ordinary", "������������" },
        { "perform", "���������, ������, ���������" },
        { "quality", "��������" },
        { "reliable", "��������" },
        { "require", "���������" },
        { "speed", "��������" },
        { "surround", "��������" },
        { "task", "�������, ������" },
        { "up to", "������ ��" },
        { "usage", "�������������" },
        { "whereas", "����� ���, � �� ����� ���" },
        { "aim", "����������, ��������" },
        { "alloy", "�����" },
        { "approach", "������������, ���������" },
        { "certain", "�����������" },
        { "condition", "�������" },
        { "create", "���������" },
        { "consequently", "�������������" },
        { "data", "������" },
        { "density", "���������" },
        { "differ from", "���������� ��" },
        { "difference", "��������, �������" },
        { "estimate", "���������" },
        { "except", "�����, �� �����������" },
        { "i.e. [that is]", "�� ����" },
        { "include", "��������" },
        { "launch", "������" },
        { "liquid", "��������, ������" },
        { "manned", "������������ (� ��������� �� �����)" },
        { "movement", "��������" },
        { "numerous", "��������������" },
        { "obtain", "��������" },
        { "possess", "��������, �������" },
        { "thus", "���, ����� �������" },
        { "valuable", "������" },
        { "prove", "����������" },
        { "substance", "��������" },
        { "surface", "�����������" },
        { "vehicle", "������������ ��������, ����������� ����������� �������" },
        { "weight", "���" }
        
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

            while (left(tmp)) {
                int num = rand() % cnt;

                if (mark[num] == true || tmp[num] == true)
                    continue;


                string st = "";

                cout << "-----------------------" << endl;
                cout << words[num][1] << endl;

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
            }

            cout << right << " �� " << cnt  << endl;

        }
    }

   
    return 0;
}