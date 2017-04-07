#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <fstream>
#include <ctime>
#include <windows.h>

#pragma comment( lib, "ws2_32.lib" )
#pragma warning( disable : 4996)

#define PORT    666
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
    int allSyms = 0;
    int errors = 0;

    cout << text << endl;

    time_t = clock();
    for (size_t i = 0; i < text.size(); ++i)
    {
            if (i == text.size() - 1)
                continue;

            c = _getch();

            if (c == ' ' && text[i] == '\0') {
                cout << endl;
                continue;
            }

            if (c != text[i]) {
                Beep(1000, 200);
                ++errors;
                --allSyms;
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
    res->allSyms = allSyms;

    return res;
}

int startSession() {
    char buff[1024];
    std::printf("TCP DEMO CLIENT\n");

    if (WSAStartup(0x202, (WSADATA *)&buff[0]))
    {
        std::printf("WSAStart error %d\n", WSAGetLastError());
        return -1;
    }

    SOCKET my_sock;
    my_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (my_sock < 0)
    {
        std::printf("Socket() error %d\n", WSAGetLastError());
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
            std::printf("Invalid address %s\n", SERVERADDR);
            closesocket(my_sock);
            WSACleanup();
            return -1;
        }

    if (connect(my_sock, (sockaddr *)&dest_addr,
        sizeof(dest_addr)))
    {
        std::printf("Connect error %d\n", WSAGetLastError());
        return -1;
    }

    std::printf("Connection with %s successfully done\n\
    Type quit for quit\n\n", SERVERADDR);

    buff[512] = 0;
    printf("\n");
    while (1)
    {
        scanf("%s", &buff[0]);

        if (!strcmp(&buff[0], "quit"))
        {
            std::printf("Exit...");
            closesocket(my_sock);
            WSACleanup();
            return 0;
        }

        if (!strcmp(&buff[0], "text")) {
            send(my_sock, &buff[0], 1023, 0);

            int bytes_recv = recv(my_sock, buff, sizeof(buff) - 1, 0);

            if (buff[0] == send_error) {
                cout << "You entered wrong coordinates. Try again." << endl;
            }
            else {
                Result *result = checkResult(string(buff));

                cout << "Time: " << result->time << " s" << endl;
                cout << "Errors: " << result->errors << endl;
                cout << "Speed: " << result->allSyms * 60.0 / result->time << " sym/min" << endl;
            }

        }

    }

    printf("Recv error %d\n", WSAGetLastError());
    closesocket(my_sock);
    WSACleanup();
    return -1;
}

void getText() {
}

void sendResult() {
}

void getResults() {
}

int main () {
    startSession();

    return 0;
}
