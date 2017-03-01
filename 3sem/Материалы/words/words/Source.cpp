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
        { "according to", "согласно, соотвественно" },
        { "available", "доступный имеющийся в распоряжении" },
        { "beam", "луч" },
        { "built-in", "встроенный" },
        { "by means of", "посредством, при помощи" },
        { "calculation", "вычисление" },
        { "capable", "способный" },
        { "circuit", "схема, цепь" },
        { "close", "близкий, тесный" },
        { "complete", "завершать" },
        { "control", "управлять, контролировать" },
        { "depend on", "зависеть от" },
        { "fast", "быстрый" },
        { "generation", "поколение" },
        { "go on", "продолжать" },
        { "machine-tool", "станок" },
        { "matter", "дело, вопрос" },
        { "ordinary", "обыкновенный" },
        { "perform", "выполнять, делать, исполнять" },
        { "quality", "качество" },
        { "reliable", "надежный" },
        { "require", "требовать" },
        { "speed", "скорость" },
        { "surround", "окружать" },
        { "task", "задание, задача" },
        { "up to", "вплоть до" },
        { "usage", "использование" },
        { "whereas", "тогда как, в то время как" },
        { "aim", "стремиться, целиться" },
        { "alloy", "сплав" },
        { "approach", "приближаться, подходить" },
        { "certain", "определённый" },
        { "condition", "условие" },
        { "create", "создавать" },
        { "consequently", "следовательно" },
        { "data", "данные" },
        { "density", "плотность" },
        { "differ from", "отличаться от" },
        { "difference", "различие, разница" },
        { "estimate", "оценивать" },
        { "except", "кроме, за исключением" },
        { "i.e. [that is]", "то есть" },
        { "include", "включать" },
        { "launch", "запуск" },
        { "liquid", "жидкость, жидкий" },
        { "manned", "пилотируемый (с человеком на борту)" },
        { "movement", "движение" },
        { "numerous", "многочисленный" },
        { "obtain", "получать" },
        { "possess", "обладать, владеть" },
        { "thus", "так, таким образом" },
        { "valuable", "ценный" },
        { "prove", "доказывать" },
        { "substance", "вещество" },
        { "surface", "поверхность" },
        { "vehicle", "транспортное средство, космический летательный аппарат" },
        { "weight", "вес" }
        
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

            cout << right << " из " << cnt  << endl;

        }
    }

   
    return 0;
}