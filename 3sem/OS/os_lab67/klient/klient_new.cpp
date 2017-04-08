#include "zmq.h"
#include <stdio.h>

#include <inttypes.h>
#include <iostream>
#include <string>

using namespace std;
#define STR_SIZE 100
#define CREDIT_LIMIT -10000
#define OK 1
#define NO_ACCOUNT -1
#define NO_MONEY -2

typedef string ID;
typedef int Money;
typedef char Type;

typedef struct _MD {
    ID clientId;
    Money sum;
    Type acc;
    int action;
    ID receiverClientId;
    char message[STR_SIZE];
} MessageData;

using namespace std;
int main() {
    void *context = zmq_ctx_new();

    ID id;
    cout << "Enter login of client: ";
    cin >> id;
    cout << endl;

    char adress[25];
    cout << "Enter thee bank adress: ";

    int bankAdress;
    cin >> bankAdress;
    cout << endl;


    sprintf_s(adress, "%s%d", "tcp://localhost:", bankAdress);

    void *senderSocket = zmq_socket(context, ZMQ_REQ);
    zmq_connect(senderSocket, adress);

    MessageData tmp;
    tmp.action = -1;
    tmp.clientId = id;

    zmq_msg_t message;
    zmq_msg_init_size(&message, sizeof(MessageData));
    memcpy(zmq_msg_data(&message), &tmp, sizeof(MessageData));
    zmq_msg_send(&message, senderSocket, 0);
    zmq_msg_close(&message);

    zmq_msg_init(&message);
    zmq_msg_recv(&message, senderSocket, 0);
    MessageData *tmp1 = (MessageData *)zmq_msg_data(&message);
    cout << tmp1->message << endl;
    zmq_msg_close(&message);

    printf("**********************************\n");
    printf("1) Put money into the account\n");
    printf("2) Get  money from the account\n");
    printf("3) Send money to another account \n");
    printf("4) Check bank account \n");
    printf("0) Leave the bank\n");
    printf("**********************************\n");


    while (1) {
        int action = 0;
        cout << "--------------------------------------" << endl;
        cout << "Ins command: ";
        cin >> action;
        cout << "--------------------------------------" << endl;

       

        MessageData md;
        md.action = action;
        md.clientId = id;

        if (action == 1) {
            Money sum = 0;
            Type ch = 0;

            cout << "Enter sum: ";
            cin >> sum;
            cout << "On which acc credit ('c') or debet ('d'): ";
            cin >> ch;

            md.sum = sum;

            bool r = false;

            while (!r) {
                if (ch == 'c' || ch == 'd')
                    r = true;
                else {
                    cout << "'c' or 'd'!" << endl;
                    cin >> ch;
                }
            }

            md.acc = ch;

            zmq_msg_t message;
            zmq_msg_init_size(&message, sizeof(MessageData));
            memcpy(zmq_msg_data(&message), &md, sizeof(MessageData));
            zmq_msg_send(&message, senderSocket, 0);
            zmq_msg_close(&message);

            zmq_msg_init(&message);
            zmq_msg_recv(&message, senderSocket, 0);
            MessageData *md = (MessageData *)zmq_msg_data(&message);
            cout << md->message << endl;
            zmq_msg_close(&message);
        }

        if (action == 2) {
            Money sum = 0;
            Type ch = 0;

            cout << "Enter sum: ";
            cin >> sum;
            cout << "From which acc credit ('c') or debet ('d'): ";
            cin >> ch;

            md.sum = sum;

            bool r = false;

            while (!r) {
                if (ch == 'c' || ch == 'd')
                    r = true;
                else {
                    cout << "'c' or 'd'!" << endl;
                    cin >> ch;
                }
            }

            md.acc = ch;

            zmq_msg_t message;
            zmq_msg_init_size(&message, sizeof(MessageData));
            memcpy(zmq_msg_data(&message), &md, sizeof(MessageData));
            zmq_msg_send(&message, senderSocket, 0);
            zmq_msg_close(&message);

            zmq_msg_init(&message);
            zmq_msg_recv(&message, senderSocket, 0);
            MessageData *md = (MessageData *)zmq_msg_data(&message);
            cout << md->message << endl;
            zmq_msg_close(&message);
        }

        if(action == 3) {
            Money sum = 0;
            Type ch = 0;
            ID rec = "";

            cout << "ID of recivier: ";
            cin >> rec;
            cout << "Enter sum to send: ";
            cin >> sum;
            cout << "From which acc credit ('c') or debet ('d'): ";
            cin >> ch;

            md.sum = sum;
            md.receiverClientId = rec;

            bool r = false;

            while (!r) {
                if (ch == 'c' || ch == 'd')
                    r = true;
                else {
                    cout << "'c' or 'd'!" << endl;
                    cin >> ch;
                }
            }

            md.acc = ch;

            zmq_msg_t message;
            zmq_msg_init_size(&message, sizeof(MessageData));
            memcpy(zmq_msg_data(&message), &md, sizeof(MessageData));
            zmq_msg_send(&message, senderSocket, 0);
            zmq_msg_close(&message);

            zmq_msg_init(&message);
            zmq_msg_recv(&message, senderSocket, 0);
            MessageData *md = (MessageData *)zmq_msg_data(&message);
            cout << md->message << endl;
            zmq_msg_close(&message);
        }

        if (action == 4) {
            zmq_msg_t message;
            zmq_msg_init_size(&message, sizeof(MessageData));
            memcpy(zmq_msg_data(&message), &md, sizeof(MessageData));
            zmq_msg_send(&message, senderSocket, 0);
            zmq_msg_close(&message);

            zmq_msg_init(&message);
            zmq_msg_recv(&message, senderSocket, 0);
            MessageData *md = (MessageData *)zmq_msg_data(&message);
            cout << md->message << endl;
            zmq_msg_close(&message);
        }

        if (action == 0)
            break;
    }

    zmq_close(senderSocket);
    zmq_ctx_destroy(context);

    return 0;
}