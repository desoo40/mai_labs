#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <fstream>
#include <ctime>
#include <windows.h>

using namespace std;

#pragma comment( lib, "ws2_32.lib" )
#pragma warning( disable : 4996)

#define MY_PORT    666

#define PRINTNUSERS if (nclients)\
  std::printf("%d user on-line\n",nclients);\
  else std::printf("No User on line\n");

int nclients = 0;

const char send_empty = 0;
const char send_error = -1;
const char send_end = -3;

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
    std::printf("TCP SERVER DEMO\n");

    if (WSAStartup(0x0202, (WSADATA *)&buff[0]))
    {
        std::printf("Error WSAStartup %d\n",
            WSAGetLastError());
        return -1;
    }


    SOCKET mysocket;
    if ((mysocket = socket(AF_INET, SOCK_STREAM, 0))<0)
    {
        std::printf("Error socket %d\n", WSAGetLastError());
        WSACleanup();
        return -1;
    }

    sockaddr_in local_addr;
    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(MY_PORT);
    local_addr.sin_addr.s_addr = 0;
    
    if (bind(mysocket, (sockaddr *)&local_addr,
        sizeof(local_addr)))
    {
        std::printf("Error bind %d\n", WSAGetLastError());
        closesocket(mysocket);
        WSACleanup();
        return -1;
    }

    if (listen(mysocket, 20))
    {
        std::printf("Error listen %d\n", WSAGetLastError());
        closesocket(mysocket);
        WSACleanup();
        return -1;
    }

    std::printf("Waiting for connection\n");

    SOCKET client_socket;
    sockaddr_in client_addr;

    int client_addr_size = sizeof(client_addr);

    while ((client_socket = accept(mysocket, (sockaddr *)
        &client_addr, &client_addr_size)))
    {
        nclients++;      

        HOSTENT *hst;
        hst = gethostbyaddr((char *)
            &client_addr.sin_addr.s_addr, 4, AF_INET);

        std::printf("+%s [%s] new connect!\n",
            (hst) ? hst->h_name : "",
            inet_ntoa(client_addr.sin_addr));
        PRINTNUSERS

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
        int bytes_recv = recv(my_sock, buff, sizeof(buff) - 1, 0);

        if (!strcmp(&buff[0], "text"))
        {
            vector<string> text = getRandomText();
            strcpy(buff, text[0].c_str());
            send(my_sock, buff, sizeof(buff) - 1, 0);
        }

        //char x = atoi(&buff[0]) - 1, y = atoi(&buff[512]) - 1;
    }

    nclients--;
    printf("-disconnect\n"); PRINTNUSERS

        closesocket(my_sock);
    return 0;
}

int main()
{
    srand(time(NULL));
	
    startServer();
    //Result *result = checkResult(text);
   /*
	cout << "Time: "<<  result->time << " s"<< endl;
	cout << "Errors: " << result->errors << endl;
	cout << "Speed: " << result->allSyms * 60.0 / result->time << " sym/min" << endl;*/
	return 0;
}
