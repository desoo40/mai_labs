#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <queue>

using namespace std;

#pragma comment( lib, "ws2_32.lib" )
//#pragma warning( disable : 4996)

#define PORT 4055  
#define MAXCONN 50

int clientsQty = 0;
priority_queue<int> top;

    typedef struct _result{
        double time;
        int errors;
        int allSyms;
    } Result;

    DWORD WINAPI WorkWithClient(LPVOID client_socket);

int numOfFilesInDir()
{
    bool x = true;
    int i = 0;
    WIN32_FIND_DATA FindFileData;

    HANDLE hFind;
    wchar_t* fold = L"Texts/*.txt";
    hFind = FindFirstFile(fold, &FindFileData);

    if (hFind != INVALID_HANDLE_VALUE) {

        i++;

        while ((x = FindNextFile(hFind, &FindFileData)) == TRUE) {
            
            i++;
        }
    }

    return i;
}

void printCurrState() {
    if(clientsQty)
        cout << clientsQty << " users online" << endl; \
    else 
        cout << "Nobody is here..." << endl;
}

string getRandomText() {
    ifstream file;

    int numOfFiles = numOfFilesInDir();

    int rdm;

    srand(time(NULL));
    rdm = rand() % numOfFiles;

    char fileName[16];

    sprintf_s(fileName, "Texts/text%i.txt", rdm);

    file.open(fileName);

    string text = "";
    string tmp;
    bool t = false;
    while (getline(file, tmp))
    {
        if (t == false) {
            text += tmp;
            t = true;
        }
        else
            text += '\n' + tmp;
    }

    return text;
}

int startServer() {
    char buff[1024];    
    cout << "Server start" << endl;

    if (WSAStartup(0x0202, (WSADATA *)&buff[0]))
    {
        cout << "WSAStart error " << WSAGetLastError() << endl;

        return -1;
    }


    SOCKET mysocket;
    if ((mysocket = socket(AF_INET, SOCK_STREAM, 0))<0)
    {
        cout << "Socket() error " << WSAGetLastError() << endl;
        WSACleanup();
        return -1;
    }

    sockaddr_in local_addr;
    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(PORT);
    local_addr.sin_addr.s_addr = 0;
    
    if (bind(mysocket, (sockaddr *)&local_addr,
        sizeof(local_addr)))
    {
        cout << "Bind error " << WSAGetLastError() << endl;
        closesocket(mysocket);
        WSACleanup();
        return -1;
    }

    if (listen(mysocket, MAXCONN))
    {
        cout << "Listen error " << WSAGetLastError() << endl;
        closesocket(mysocket);
        WSACleanup();
        return -1;
    }

    cout << "Waiting for connection" << endl;
    cout << "++++++++++++++++++++++++++++++++" << endl;


    SOCKET client_socket;
    sockaddr_in client_addr;

    int client_addr_size = sizeof(client_addr);

    while ((client_socket = accept(mysocket, (sockaddr *)
        &client_addr, &client_addr_size)))
    {
        clientsQty++;

        HOSTENT *hst;
        hst = gethostbyaddr((char *) &client_addr.sin_addr.s_addr, 4, AF_INET);
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

        cout << "+ " << inet_ntoa(client_addr.sin_addr) << "new player!" << endl;

        printCurrState();
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

            DWORD thID;
        CreateThread(NULL, NULL, WorkWithClient, &client_socket, NULL, &thID);

    }

    return 0;
}

DWORD WINAPI WorkWithClient(LPVOID client_socket) {
    SOCKET my_sock;
    my_sock = ((SOCKET *)client_socket)[0];
    char buff[1024] = "";

    while (1)
    {
        if (!clientsQty)
            break;

        int bytes_recv = recv(my_sock, buff, sizeof(buff) - 1, 0);

        if (!strcmp(&buff[0], "text"))
        {
            string text = getRandomText();
            strcpy_s(buff, text.c_str());
            send(my_sock, buff, sizeof(buff) - 1, 0);
        }

        if (!strcmp(&buff[0], "quit")) {
            clientsQty--;
            cout << "- disconnect" << endl;
            printCurrState();
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

            closesocket(my_sock);
            break;
        }

        if (buff[0] == '$') {
            int i = 1;
            int speed = 0;
            while (buff[i] != '$') {
                speed *= 10;
                speed += buff[i] - 48;
                ++i;
            }

            top.push(speed);
        }

        if (!strcmp(&buff[0], "top")) {
            string topchik = "";

            priority_queue<int> tmp = top;

            for (int i = 1; !tmp.empty() || i >= 10; ++i) {
                int sp = tmp.top();
                tmp.pop();
                topchik += to_string(i) + " place - " + to_string(sp) + " sym/min\n";
            }
            strcpy_s(buff, topchik.c_str());
            send(my_sock, buff, sizeof(buff) - 1, 0);
        }
    }

    
    return 0;
}

int main()
{
    startServer();
	return 0;
}
