#include <cstdlib>
#include <iostream>
#include <memory>
#include "Triangle.h"
#include "TStackItem.h"
#include "TStack.h"
#include "figure.h"
#include "quadro.h"
#include "rectangle.h"

using namespace std;

enum General
{
    start,
    add,
    del,
    print,
    fin
};

void PrintLine()
{
    cout << "----------------------------------" << endl;
}
void PrintStars()
{
    cout << "**********************************" << endl;
}

void TipsForFirgurs() {
    
    PrintLine();
    cout << "1 - Triangle" << endl
        << "2 - Quadro" << endl
        << "3 - Rectangle" << endl
    << "0 - stop" << endl;
    PrintLine();
}

void Tips() {
    PrintLine();

    cout << "1 - add elem to stack" << endl
        << "2 - delete elem from stack" << endl
        << "3 - print stack" << endl
        << "0 - end" << endl;
   PrintLine();
}

int main(int argc, char** argv) {

    TStack stack;
    int state = start;
    while (1)
    {
        switch (state)
        {
        case start:
        {
            Tips();
            cin >> state;
            break;
        }
        case add:
        {

            PrintLine();
            cout << "Which figure you want to add?" << endl;

            TipsForFirgurs();

            int fig = 0;
            cin >> fig;
            PrintStars();

            if (fig == 1)
            {
                stack.push(shared_ptr<Figure>(new Triangle(cin)));
                PrintStars();
                break;
            }
            if (fig == 2)
            {
                stack.push(shared_ptr<Figure>(new Quadro(cin)));
                PrintStars();
                break;
            }
            if (fig == 3)
            {
                stack.push(shared_ptr<Figure>(new Rectangle(cin)));
                PrintStars();
                break;
            }

            if (fig == 0)
            {
                state = start;
                PrintStars();
                break;
            }

            cout << "Wrong number" << endl;
            PrintStars();
            break;
        }

        case del:
        {
            PrintStars();
            stack.pop();
            PrintStars();
            state = start;
            break;
        }

        case print:
        {
            PrintStars();
            cout << stack << endl;
            PrintStars();
            state = start;
            break;
        }

        case fin:
            return 0;
        }
    }
}