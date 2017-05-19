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
        { "amplification", "усиление" },
        { "as well", "также" },
        { "approximately", "почти, приблизительно" },
        { "capacity", "мощность, нагрузка, производительность" },
        { "conduct", "вести, проводить" },
        { "cost", "стоимость" },
        { "duration", "продолжительность" },
        { "enough", "достаточно, довольно" },
        { "entire", "полный, целый" },
        { "fulfilment", "выполнение, осуществление, исполнение" },
        { "single", "один, одиночный" },
        { "suggest", "предлагать, советовать" },
        { "tool", "инструмент, орудие, средство" },
        { "to meet the demands, the requirements", "удовлетворять требованиям" },
        { "in order to", "для того чтобы" },
        { "power plant", "силовая установка, электростанция" },
        { "heat", "нагревать, тепло, теплота" },
        { "heating", "нагрев" },
        { "heat-resistant", "теплостойкий" },
        { "indeed", "действительно, на самом деле" },
        { "installation", "установка, сборка" },
        { "involved", "связанный, рассматриваемый, имеющий место" },
        { "rapidly", "быстро" },
        { "represent", "представлять, олицетворять" },
        { "stimulate", "возбуждать, индуцировать" },
        { "treatment", "обработка" },
        { "vary", "менять, изменять" },
        { "weapon", "оружие" },
        { "accurate", "точный" },
        { "almost", "почти" },
        { "advanced", "новейший, передовой" },
        { "construct", "строить, сооружать" },
        { "crew", "экипаж" },
        { "depth", "глубина" },
        { "descend", "спускаться, опускаться" },
        { "due to", "благодаря, из-за" },
        { "explore", "исследовать" },
        { "find out", "выяснить, узнать" },
        { "image", "изображение" },
        { "instead of", "вместо" },
        { "join", "соединить, объединить" },
        { "lift", "поднимать(ся)" },
        { "mankind", "человечество" },
        { "operate", "работать, действовать" },
        { "battery-operated", "работающий на батареях" },
        { "particular", "данный, особенный, отдельный" },
        { "penetrate", "проникать" },
        { "precision", "точность" },
        { "promise", "обещать" },
        { "provided", "при условии что; в том случае, если" },
        { "realize", "осуществлять, реализовывать" },
        { "resist", "сопротивляться, выдерживать" },
        { "sample", "образец" },
        { "submerge", "погружаться, опускаться вглубь" },
        { "test", "проверять, подвергать испытанию" },
        { "transparent", "прозрачный" },
        { "try", "пытаться, пробовать" },
        { "collect", "собирать" }
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

            cout << right << " из " << cnt  << endl;
        }
    }

   
    return 0;
}