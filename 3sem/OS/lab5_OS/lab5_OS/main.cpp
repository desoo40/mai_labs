#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

using namespace std;

typedef struct _qnode Que_node;
typedef struct _queue Queue;

struct _qnode
{
    Que_node *next;
    int32_t *elem;
};

struct _queue
{
    Que_node *first;
    Que_node *last;
};

typedef Queue*(*DLL_CREATE)(int32_t elem);
typedef bool(*DLL_PUSH)(Queue *, int32_t elem);
typedef void(*DLL_PRINT)(Queue *);
typedef bool(*DLL_POP)(Queue *);
typedef int(*DLL_LENGHT)(Queue *);
typedef void(*DLL_DESTROY)(Queue **);




void hints() {
    cout << "******************************" << endl;
    cout << "1 - push element to queue" << endl;
    cout << "2 - print queue" << endl;
    cout << "3 - pop element from queue" << endl;
    cout << "4 - lenght of queue" << endl;
    cout << "5 - destroy queue" << endl;
    cout << "0 - exit" << endl;
    cout << "******************************" << endl;
}

int main(void) {
    HINSTANCE hLib = LoadLibrary(L"dll.dll");

    if (hLib == NULL)
    {
        cout << "Unable to load library!" << endl;
        _getch();
        return 0;
    }

    cout << "Library is loaded.." << endl;

    Queue *queue = NULL;

    DLL_CREATE queue_create = (DLL_CREATE)GetProcAddress((HMODULE)hLib, "queue_create");
    DLL_PUSH queue_push = (DLL_PUSH)GetProcAddress((HMODULE)hLib, "queue_push");
    DLL_PRINT queue_print = (DLL_PRINT)GetProcAddress((HMODULE)hLib, "queue_print");
    DLL_POP queue_pop = (DLL_POP)GetProcAddress((HMODULE)hLib, "queue_pop");
    DLL_LENGHT queue_lenght = (DLL_LENGHT)GetProcAddress((HMODULE)hLib, "queue_lenght");
    DLL_DESTROY queue_destroy = (DLL_DESTROY)GetProcAddress((HMODULE)hLib, "queue_destroy");


    if (queue_create == NULL || queue_push == NULL || queue_print == NULL || queue_pop == NULL)
    {
        printf("Unable to load function(s).");
        FreeLibrary((HMODULE)hLib);
        return 0;
    }

    hints();
    cout << endl;

    while (1) {
        int command = 0;

        cin >> command;

        if (command == 1) {
            int32_t elem = 0;

            cout << "Enter element" << endl;
            cin >> elem;

            if (queue == nullptr) {
                cout << "Creating queue..." << endl;
                queue = queue_create(elem);

                if (queue)
                    cout << "OK" << endl;
                else
                    cout << "Can't create queue" << endl;
            }
            else {
                cout << "Pushing..." << endl;

                if (queue_push(queue, elem))
                    cout << "OK" << endl;
                else
                    cout << "Can't push..." << endl;
            }
        }

        if (command == 2) {
            cout << "Printing queue..." << endl;
            if (queue == nullptr)
                cout << "Queue is empty" << endl;
            else
                queue_print(queue);
        }

        if (command == 3) {
            cout << "Pop..." << endl;
            if (queue_pop(queue))
                cout << "OK" << endl;
            else
                cout << "Queue is empty" << endl;
        }

        if (command == 4)
            cout << "Lenght is " << queue_lenght(queue) << endl;

        if (command == 5) {
            cout << "Destroying queue..." << endl;
            if (queue == nullptr)
                cout << "Queue is empty" << endl;
            else {
                queue_destroy(&queue);
                cout << "OK" << endl;
            }
        }

        if (command == 0)
            break;

        cout << "----------------------" << endl;
    }

    return 0;
}
