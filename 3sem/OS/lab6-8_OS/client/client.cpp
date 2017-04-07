#include "zmq.h"
#include <stdio.h>
#include "../include/message.h"

#include <inttypes.h>
#include <iostream>
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

    printf("**********************************\n");
    printf("1) Put money into the account\n");
    printf("2) Get  money from the account\n");
    printf("3) Send money to another account \n");
    printf("4) Check bank account \n");
    printf("5) Leave the bank\n");
    printf("**********************************\n");


    while (1) {
        int action = 0;
        cout << "Ins command: ";
        cin >> action;

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

    //do {
    //    printf("Select action: ");
    //    scanf("%d", &action);

    //    MessageData md;
    //    md.action = action;
    //    md.clientId = id;

    //    switch (action) {

    //    case 1: {
    //        int sum;
    //        printf("Enter the sum: ");
    //        scanf("%d", &sum);

    //        md.sum = sum;

    //        zmq_msg_t message;
    //        zmq_msg_init_size(&message, sizeof(MessageData));
    //        memcpy(zmq_msg_data(&message), &md, sizeof(MessageData));
    //        zmq_msg_send(&message, senderSocket, 0);
    //        zmq_msg_close(&message);

    //        zmq_msg_init(&message);
    //        zmq_msg_recv(&message, senderSocket, 0);
    //        MessageData *md = (MessageData *)zmq_msg_data(&message);
    //        printf("%s\n", md->message);
    //        zmq_msg_close(&message);
    //        break;

    //    }
    //    case 2: {
    //        int sum;
    //        printf("Enter the sum: ");
    //        scanf("%d", &sum);

    //        md.sum = sum;

    //        zmq_msg_t message;
    //        zmq_msg_init_size(&message, sizeof(MessageData));
    //        memcpy(zmq_msg_data(&message), &md, sizeof(MessageData));
    //        zmq_msg_send(&message, senderSocket, 0);
    //        zmq_msg_close(&message);

    //        zmq_msg_init(&message);
    //        zmq_msg_recv(&message, senderSocket, 0);
    //        MessageData *md = (MessageData *)zmq_msg_data(&message);
    //        printf("%s\n", md->message);
    //        zmq_msg_close(&message);

    //        break;
    //    }

    //    case 3: {
    //        int receiverClientId;
    //        printf("Enter receiver id: ");
    //        scanf("%d", &receiverClientId);

    //        int sum;
    //        printf("Enter the sum: ");
    //        scanf("%d", &sum);

    //        md.sum = sum;
    //        md.receiverClientId = receiverClientId;

    //        zmq_msg_t message;
    //        zmq_msg_init_size(&message, sizeof(MessageData));
    //        memcpy(zmq_msg_data(&message), &md, sizeof(MessageData));
    //        zmq_msg_send(&message, senderSocket, 0);
    //        zmq_msg_close(&message);

    //        zmq_msg_init(&message);
    //        zmq_msg_recv(&message, senderSocket, 0);
    //        MessageData *md = (MessageData *)zmq_msg_data(&message);
    //        printf("%s\n", md->message);
    //        zmq_msg_close(&message);

    //        break;
    //    }

    //    case 4: {
    //        zmq_msg_t message;
    //        zmq_msg_init_size(&message, sizeof(MessageData));
    //        memcpy(zmq_msg_data(&message), &md, sizeof(MessageData));
    //        zmq_msg_send(&message, senderSocket, 0);
    //        zmq_msg_close(&message);

    //        zmq_msg_init(&message);
    //        zmq_msg_recv(&message, senderSocket, 0);
    //        MessageData *md = (MessageData *)zmq_msg_data(&message);
    //        printf("%s\n", md->message);
    //        zmq_msg_close(&message);

    //        break;
    //    }

    //    case 5: {
    //        break;
    //    }
    //    default: {
    //        printf("Incorrect action\n");
    //        break;
    //    }
    //    }


    //} while (action != 5);

    //zmq_close(senderSocket);
    //zmq_ctx_destroy(context);

    return 0;
}