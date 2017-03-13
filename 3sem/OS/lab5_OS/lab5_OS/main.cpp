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

typedef Queue*(* LPFNDLLFUNCCREATE)(int32_t *T);
typedef void(* LPFNDLLFUNCPUSH)(Queue *, int32_t elem);
typedef void(* LPFNDLLFUNCPRINT)(Queue *, int32_t elem);
typedef bool(* LPFNDLLFUNCPOP)(Queue *, int32_t elem);


int main(void)
{
	HINSTANCE hLib = LoadLibrary(L"dll.dll");
	if (hLib == NULL)
	{
		cout << "Unable to load library!" << endl;
		_getch();
		return 1;
	}
	cout << "Library is loaded.." << endl;
	
	Queue *queue = NULL;
	LPFNDLLFUNCCREATE queue_create = (LPFNDLLFUNCCREATE)GetProcAddress((HMODULE)hLib, "queue_create");
	LPFNDLLFUNCPUSH queue_push = (LPFNDLLFUNCPUSH)GetProcAddress((HMODULE)hLib, "queue_push");
	LPFNDLLFUNCPRINT queue_print = (LPFNDLLFUNCPRINT)GetProcAddress((HMODULE)hLib, "queue_print");
	LPFNDLLFUNCPOP queue_pop = (LPFNDLLFUNCPOP)GetProcAddress((HMODULE)hLib, "queue_pop");
	if (queue_create == NULL || queue_push == NULL || queue_print == NULL || queue_pop == NULL)
	{
		printf("Unable to load function(s).");
		FreeLibrary((HMODULE)hLib);
		return 1;
	}
	
	printf("-------------------------------------------\n");
	printf("Commands:\n");
	printf("a <elem> - push to queue\n");
	printf("d <elem>- pop from queue\n");
	printf("p - print queue\n");
	printf("q - exit\n");
	printf("-------------------------------------------\n");

	while (true) {
		//printf("%d\n", cnt);
		//cnt++;
		char cmd;
		int32_t elem = 0;
		bool is_finished = false;
        cin >> cmd;
		switch (cmd) {
		case 'q':
			is_finished = true;
			break;
		case 'a':
            cin >> elem;
			if (queue == NULL) {
				queue = queue_create(&elem);
			}
				
			else {
				queue_push(queue, elem);
			}
				
			break;
		case 'd':
			if (queue == NULL) {
				printf("queue is empty");
				break;
			}
            cin >> elem;
			queue_pop(queue, elem);
			break;
		case 'p':
			queue_print(queue, 0);
			break;
		case '\n':
			break;
		default:
			printf("Invalid command `%c`\n", cmd);
			break;
		}
		if (is_finished) break;
	}
	printf("Goodbye!\n");

	return 0;
}
