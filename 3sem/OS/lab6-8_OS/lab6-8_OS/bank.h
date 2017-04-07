#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <string>

#include "../include/message.h"

#define CREDIT_LIMIT -10000
#define OK -1
#define NO_ACCOUNT -1
#define NO_MONEY -2


class Account {
    Money debet;
    Money credit;

public:
    Account();
    ~Account();

    void printAcc();
    void putMoneyA(Money, Type);
    int getMoneyA(Money, Type);

};

class Client {
    ID id;
    Account *account;
    Client *leftClient;
    Client *rightClient;

public:
    Client(ID);
    ~Client();

    void addNewClient(ID);
    int putMoney(Money, Type);
    int getMoney(Money, Type);
    void checkAcc();
    void print();
    Client *findClident(ID);
};

class ClientBase {
    Client *root;

public:
    ClientBase();
    ~ClientBase();

    void addNewClientToBase(ID);
    int putMoneyOnAccount(ID, Money, Type);
    int getMoneyFromAccount(ID, Money, Type);
    int checkAcc(ID);
    void printClientBase();
    Client *findClient(ID);
};
#endif
