#include "bank.h"
#include "zmq.h"

#pragma warning(disable : 4996) 
int main() {
    ClientBase *base = new ClientBase();

    void *context = zmq_ctx_new();
    void *respondSocket = zmq_socket(context, ZMQ_REP);

    char adress[25];
    cout << "Enter the bank ardess" << endl;
    int bankAdress;

    cin >> bankAdress;

    sprintf_s(adress, "%s%d", "tcp://*:", bankAdress);

    zmq_bind(respondSocket, adress);

    zmq_msg_t message;

    zmq_msg_init(&message);
    zmq_msg_recv(&message, respondSocket, 0);
    MessageData *md = (MessageData *)zmq_msg_data(&message);
    zmq_msg_close(&message);

    char info[STR_SIZE];

    switch (md->action) {
    case 1: {

        cout << "Put money on account \"" << md->clientId << "\"";
        int status = base->putMoneyOnAccount(md->clientId, md->sum, md->acc);

        if (status == OK) {
            cout << "OK" << endl;
            strcpy(info, "Operation was completed successfully\0");
        }
        if (status == NO_ACCOUNT) {
            cout << "No such account" << endl;
            strcpy(info, "No such account\0");
        }
        memcpy(md->message, info, strlen(info) + 1);

        zmq_msg_init_size(&message, sizeof(MessageData));
        memcpy(zmq_msg_data(&message), md, sizeof(MessageData));
        zmq_msg_send(&message, respondSocket, 0);
        zmq_msg_close(&message);


        break;
    }
    case 2: {
        cout << "Get money from account \"" << md->clientId << "\"";

        int code = base->getMoneyFromAccount(md->clientId, md->sum, md->acc);
        if (code == OK) {
            cout << "OK" << endl;
            strcpy(info, "Operation was completed successfully\0");
        }
        else if (code == NO_MONEY) {
            cout << "Not enough money" << endl;
            strcpy(info, "You not enough money\0");

        }
        else if (code == NO_ACCOUNT) {
            cout << "Not bank client" << endl;
            strcpy(info, "You are not a client of our bank\0");

        }
        memcpy(md->message, info, strlen(info) + 1);

        zmq_msg_init_size(&message, sizeof(MessageData));
        memcpy(zmq_msg_data(&message), md, sizeof(MessageData));
        zmq_msg_send(&message, respondSocket, 0);
        zmq_msg_close(&message);

        break;
    }
    /*case 3: {
        printf("Send money from account id: %d to account id: %d\n", md->clientId, md->receiverClientId);
        int code = SendMoney(md->clientId, md->receiverClientId, md->sum, &clientBase);
        if (code == SUCCESS) {
            printf("Success\n");
            strcpy(info, "Operation was completed successfully\0");

        }
        else if (code == NOT_ENOUGH_MONEY) {
            printf("Not enough money\n");
            strcpy(info, "You not enough money\0");

        }
        else if (code == RECEIVER_NOT_CLIENT) {
            printf("Receiver not bank client\n");
            strcpy(info, "Receiver is not a client of our bank\0");


        }
        else {
            printf("Not bank client\n");
            strcpy(info, "You are not a client of our bank\0");

        }

        memcpy(md->message, info, strlen(info) + 1);

        zmq_msg_init_size(&message, sizeof(MessageData));
        memcpy(zmq_msg_data(&message), md, sizeof(MessageData));
        zmq_msg_send(&message, respondSocket, 0);
        zmq_msg_close(&message);
        break;
    }*/

    case 4: {
        printf("Check account id: %d\n", md->clientId);

        int code = base->checkAcc(md->clientId);
        if (code == NO_ACCOUNT) {
            printf("Not bank client\n");
            char info[] = "You are not a client of our bank\0";

        }
        else {
            printf("Client sum is %d\n", code);
            sprintf(info, "%s%d%c", "Your account is ", code, '\0');

        }

        memcpy(md->message, info, strlen(info) + 1);

        zmq_msg_init_size(&message, sizeof(MessageData));
        memcpy(zmq_msg_data(&message), md, sizeof(MessageData));
        zmq_msg_send(&message, respondSocket, 0);
        zmq_msg_close(&message);

        break;
    }

    }
    zmq_msg_close(&message);
    base->printClientBase();

zmq_close(respondSocket);
zmq_ctx_destroy(context);


    /*base->addNewClientToBase("kekar");
    base->addNewClientToBase("malish");
    base->addNewClientToBase("suchka");
    base->addNewClientToBase("petya");
    base->addNewClientToBase("aragorn");
    base->addNewClientToBase("frodo");

    base->putMoneyOnAccount("suchka", 733, 'd');
    base->putMoneyOnAccount("frodo", 6555, 'c');
    base->putMoneyOnAccount("frodo", 300, 'd');

    base->getMoneyFromAccount("frodo", 685654, 'd');
    base->printClientBase();*/
}