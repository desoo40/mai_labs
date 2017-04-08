#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <fstream>
#include <ctime>
#include <windows.h>

#pragma comment( lib, "ws2_32.lib" )
#pragma warning( disable : 4996)

#define PORT 4055
#define SERVERADDR "127.0.0.1"

const char send_empty = 0;
const char send_error = -1;
const char send_end = -3;

using namespace std;

typedef struct _result {
    double time;
    int errors;
    int allSyms;
} Result;

Result *checkResult(string text) {
    clock_t time_t;

    char c;
    int errors = 0;

    cout << "---------------------------T-------E-------X-------T-----------------------------" << endl;
    cout << text << endl;
    cout << "---------------------------------------------------------------------------------" << endl;


    for (size_t i = 0; i < text.size(); ++i)
    {
            c = _getch();
            if (i == 0)
                time_t = clock();

            if (c == ' ' && text[i] == '\n'
                || c == '\r' && text[i] == '\n'
                || c == '\n' && text[i] == '\n') {
                cout << c;
                continue;
            }
                

            if (c != text[i]) {
                Beep(1000, 200);
                ++errors;
                --i;
            }
            else
                cout << c;
        
    }
    time_t = clock() - time_t;
    cout << endl;

    double tme = (double)time_t / CLOCKS_PER_SEC;

    Result *res = new Result;

    res->time = tme;
    res->errors = errors;
    res->allSyms = text.length();

    return res;
}

void hints() {
    cout << "*****************************" << endl;
    cout << "'text' to get text" << endl;
    cout << "'top' to see fasters" << endl;
    cout << "'quit' to end" << endl;
    cout << "*****************************" << endl;
}

int startSession() {
    char buff[1024];
    cout << "Start client" << endl;

    if (WSAStartup(0x202, (WSADATA *)&buff[0]))
    {
        cout << "WSAStart error " << WSAGetLastError() << endl;

        return -1;
    }

    SOCKET my_sock;
    my_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (my_sock < 0)
    {
        cout << "Socket() error " << WSAGetLastError() << endl;
        return -1;
    }

    sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(PORT);
    HOSTENT *hst;

    if (inet_addr(SERVERADDR) != INADDR_NONE)
        dest_addr.sin_addr.s_addr = inet_addr(SERVERADDR);
    else
        if (hst = gethostbyname(SERVERADDR))
            ((unsigned long *)&dest_addr.sin_addr)[0] =
            ((unsigned long **)hst->h_addr_list)[0][0];
        else
        {
            cout << "Invalid address " << SERVERADDR << endl;
            closesocket(my_sock);
            WSACleanup();
            return -1;
        }

    if (connect(my_sock, (sockaddr *)&dest_addr,
        sizeof(dest_addr)))
    {
        cout << "Connect error " << WSAGetLastError() << endl;
        return -1;
    }

    cout << "Connection with " << SERVERADDR << " successfully done" << endl;
    hints();

    while (1)
    {
        scanf("%s", &buff[0]);

        if (!strcmp(&buff[0], "quit"))
        {
            send(my_sock, buff, sizeof(buff) - 1, 0);

            cout << "Good bye!" << endl;
            closesocket(my_sock);
            WSACleanup();
            return 0;
        }

        if (!strcmp(&buff[0], "text")) {
            send(my_sock, buff, sizeof(buff) - 1, 0);

            int bytes_recv = recv(my_sock, buff, sizeof(buff) - 1, 0);

            
                Result *result = checkResult(string(buff));
                cout << "++++++++++++++++++++++++++++++++" << endl;
                cout << "Time: " << result->time << " s" << endl;
                cout << "Errors: " << result->errors << endl;
                cout << "Speed: " << result->allSyms * 60.0 / result->time << " sym/min" << endl;
                cout << "++++++++++++++++++++++++++++++++" << endl;
                int speed = (int) result->allSyms * 60.0 / result->time;
                string rapid = "$" + to_string(speed) + '$';
                strcpy(buff, rapid.c_str());


                send(my_sock, buff, sizeof(buff) - 1, 0);
                delete result;
        }


        if (!strcmp(&buff[0], "top")) {
            send(my_sock, buff, sizeof(buff) - 1, 0);

            int bytes_recv = recv(my_sock, buff, sizeof(buff) - 1, 0);

            cout << string(buff);
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        }
    }
}

int main () {
    startSession();

    return 0;
}
