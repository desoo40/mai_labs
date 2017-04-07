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
#pragma warning( disable : 4996)

#define PORT 4055  

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

vector<string> getRandomText() {
    ifstream file;

    int numOfFiles = numOfFilesInDir();
    int rdm = rand() % numOfFiles;
    char fileName[16];
    vector<string> text;

    sprintf_s(fileName, "Texts/text%i.txt", rdm);

    file.open(fileName);

    string tmp;

    while (getline(file, tmp))
    {
        text.push_back(tmp);
    }

    return text;
}

Result *checkResult(vector<string> text) {
    clock_t time_t;
    
    char c;
    int allSyms = 0;
    int errors = 0;

    time_t = clock();
    for (size_t i = 0; i < text.size(); ++i)
    {
        for (size_t j = 0; j <= text[i].size(); ++j, ++allSyms)
        {
            if (i == text.size() - 1 && j == text[i].size())
                continue;

            c = _getch();

            if (c == ' ' && text[i][j] == '\0') {
                cout << endl;
                continue;
            }

            if (c != text[i][j]) {
                Beep(1000, 200);
                ++errors;
                --allSyms;
                --j;
            }
            else
                cout << c;
        }
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

    if (listen(mysocket, 20))
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
        hst = gethostbyaddr((char *)
            &client_addr.sin_addr.s_addr, 4, AF_INET);
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
            vector<string> text = getRandomText();
            strcpy(buff, text[0].c_str());
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
        nu
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

            while (tmp.empty())

        }
    }

    
    return 0;
}

int main()
{
    srand(time(NULL));
	
    startServer();
	return 0;
}
