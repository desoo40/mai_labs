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

    cout << "Waiting for connection" << endl;

    zmq_bind(respondSocket, adress);
    while (1) {
    zmq_msg_t message;

    zmq_msg_init(&message);
    zmq_msg_recv(&message, respondSocket, 0);
    MessageData *md = (MessageData *)zmq_msg_data(&message);
    zmq_msg_close(&message);

    char info[STR_SIZE];

    cout << "--------------------------------------" << endl;

    if (md->action == -1) 
    {
        cout << "Creacting new account \"" << md->clientId << "\"..." << endl;
        base->addNewClientToBase(md->clientId);
        cout << "OK" << endl;
        strcpy(info, "You are client of this bank!\0");
        memcpy(md->message, info, strlen(info) + 1);

        zmq_msg_init_size(&message, sizeof(MessageData));
        memcpy(zmq_msg_data(&message), md, sizeof(MessageData));
        zmq_msg_send(&message, respondSocket, 0);
        zmq_msg_close(&message);
    }


    if (md->action == 1) {

       cout << "Command: Put money on account \"" << md->clientId << "\"" << endl;
        if (base->findClient(md->clientId) == nullptr)
            base->addNewClientToBase(md->clientId);

        int status = base->putMoneyOnAccount(md->clientId, md->sum, md->acc);

        if (status == OK) {
            cout << "OK" << endl;
            strcpy(info, "Operation was completed successfully\0");
        }
        if (status == NO_ACCOUNT) {
            strcpy(info, "No such account\0");
        }
        memcpy(md->message, info, strlen(info) + 1);

        zmq_msg_init_size(&message, sizeof(MessageData));
        memcpy(zmq_msg_data(&message), md, sizeof(MessageData));
        zmq_msg_send(&message, respondSocket, 0);
        zmq_msg_close(&message);
    }

    if (md->action == 2) {
        cout << "Command: Get money from account \"" << md->clientId << "\"" << endl;

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
    }

    if (md->action ==3) {
        cout << "Command: send money from \"" << md->clientId << "\" to \"" << md->receiverClientId << "\"";

        int code = base->sendMoney(md->clientId, md->acc, md->sum, md->receiverClientId);

        if (code == OK) {
            cout << "OK" << endl;
            strcpy(info, "Operation was completed successfully\0");
        }
        else if (code == NO_MONEY) {
            cout << "Not enough money" << endl;
            strcpy(info, "You have not enough money\0");

        }
        else if (code == NO_ACCOUNT) {
            cout << "Reciever not bank client" << endl;
            strcpy(info, "Reciever not bank client\0");

        }
        memcpy(md->message, info, strlen(info) + 1);

        zmq_msg_init_size(&message, sizeof(MessageData));
        memcpy(zmq_msg_data(&message), md, sizeof(MessageData));
        zmq_msg_send(&message, respondSocket, 0);
        zmq_msg_close(&message);

    }

    if (md->action == 4) {
        cout << "Command: Check account " << md->clientId << endl;

        int code = base->checkAcc(md->clientId);
        if (code == NO_ACCOUNT) {
            printf("Not bank client\n");
            char info[] = "You are not a client of our bank\0";

        }
        else {
            sprintf(info, "%s%d\n%s%d%c", "Debet: ", base->getDebetSum(md->clientId),
                                          "Credit: ", base->getCreditSum(md->clientId), '\0');

        }

        memcpy(md->message, info, strlen(info) + 1);

        zmq_msg_init_size(&message, sizeof(MessageData));
        memcpy(zmq_msg_data(&message), md, sizeof(MessageData));
        zmq_msg_send(&message, respondSocket, 0);
        zmq_msg_close(&message);
    }
    if (md->action == 0) {
        break;
    }
    cout << "--------------------------------------" << endl;

    zmq_msg_close(&message);
    cout << endl;
    cout << "---------CURRENT CLIENT BASE------------" << endl;

    base->printClientBase();

    cout << "--------------------------------------" << endl;

    }


    zmq_close(respondSocket);
    zmq_ctx_destroy(context);

    return 0;
}