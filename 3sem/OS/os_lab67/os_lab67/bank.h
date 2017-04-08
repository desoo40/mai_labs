#ifndef BANK_H
#define BANK_H

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

typedef struct _MD{
    ID clientId;
    Money sum;
    Type acc;
    int action;
    ID receiverClientId;
    char message[STR_SIZE];
} MessageData;

class Account {
    Money debet;
    Money credit;

public:
    Account();
    ~Account();

    void printAcc();
    void putMoneyA(Money, Type);
    Money getMoneyA(Money, Type);
    Money getDebetSum();
    Money getCreditSum();

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
    Money getDebetSum();
    Money getCreditSum();
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
    Money getDebetSum(ID);
    Money getCreditSum(ID);
    void printClientBase();
    Client *findClient(ID);
    int sendMoney(ID, char, Money, ID);
};
#endif
