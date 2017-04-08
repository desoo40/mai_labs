#include "bank.h"

Account::Account() {
    debet = 0;
    credit = 0;
}

Account::~Account() {
}

void Account::printAcc() {
    cout << "Debet: " << debet << endl
        << "Credit: " << credit << endl;
}

void Account::putMoneyA(Money sum, Type type) {
    if (type == 'd')
        debet += sum;
    if (type == 'c')
        credit += sum;
}

int Account::getMoneyA(Money sum, Type type) {
    if (type == 'd') {
        if (debet - sum >= 0) {
            debet -= sum;
        }
        else {
            if (debet + credit - sum >= CREDIT_LIMIT) {
                sum -= debet;
                debet = 0;
                credit -= sum;
            }
            else {
                cout << "No enough money" << endl;
                return NO_MONEY;
            }
        }
    }

    if (type == 'c') {
        if (credit - sum >= CREDIT_LIMIT) {
            credit -= sum;
        }
        else {
            if (debet + credit - sum >= CREDIT_LIMIT) {
                sum -= credit - CREDIT_LIMIT;
                credit = CREDIT_LIMIT;
                debet -= sum;
            }
            else {
                cout << "No enough money" << endl;
                return NO_MONEY;
            }
        }
    }
    return OK;
}

Money Account::getDebetSum() {
    return debet;
}

Money Account::getCreditSum() {
    return credit;
}

Client::Client(ID id_) {
    id = id_;
    account = new Account();
    leftClient = nullptr;
    rightClient = nullptr;
}

Client::~Client() {
}

void Client::addNewClient(ID idNew) {
    if (this == nullptr) {
        cerr << "Error with base" << endl;
        return;
    }

    if (idNew >= id) {
        if (rightClient == nullptr)
            rightClient = new Client(idNew);
        else
            rightClient->addNewClient(idNew);
    }
    else {
        if (leftClient == nullptr)
            leftClient = new Client(idNew);
        else
            leftClient->addNewClient(idNew);
    }
}

int Client::putMoney(Money sum, Type type) {
    account->putMoneyA(sum, type);
    return OK;
}

int Client::getMoney(Money sum, Type type) {
    return account->getMoneyA(sum, type);
}

int Client::getDebetSum() {

    return account->getDebetSum();
}

int Client::getCreditSum() {
    return account->getCreditSum();

}

void Client::checkAcc() {
    account->printAcc();
}

void Client::print() {
    if (this == nullptr)
        return;

    cout << id << endl;
    account->printAcc();

    leftClient->print();
    rightClient->print();

}

Client* Client::findClident(ID idNew) {
    if (this == nullptr) {
        cout << "No client with that name" << endl;
        return nullptr;
    }

    if (idNew == id)
        return this;

    if (idNew > id)
        return rightClient->findClident(idNew);

    if (idNew < id)
        return leftClient->findClident(idNew);

    return nullptr;
}

ClientBase::ClientBase() {
    root = nullptr;
}

ClientBase::~ClientBase() {

}

void ClientBase::addNewClientToBase(ID id) {
    if (root == nullptr)
        root = new Client(id);
    else
        root->addNewClient(id);
}

int ClientBase::putMoneyOnAccount(ID idAcc, Money sum, Type type) {
    Client *cl = findClient(idAcc);

    if (cl == nullptr) {
        cout << "No such client" << endl;
        return NO_ACCOUNT;
    }

    return cl->putMoney(sum, type);
}

int ClientBase::getMoneyFromAccount(ID idAcc, Money sum, Type type) {
    Client *cl = findClient(idAcc);

    if (cl == nullptr) {
        cout << "No such client" << endl;
        return NO_ACCOUNT;
    }

    return cl->getMoney(sum, type);
}

int ClientBase::checkAcc(ID idAcc) {
    Client *cl = findClient(idAcc);

    if (cl == nullptr) {
        cout << "No such client" << endl;
        return NO_ACCOUNT;
    }

    cl->checkAcc();
    return OK;
}

Money ClientBase::getDebetSum(ID idAcc) {
    Client *cl = findClient(idAcc);

    return cl->getDebetSum();
}

Money ClientBase::getCreditSum(ID idAcc) {
    Client *cl = findClient(idAcc);

    return cl->getCreditSum();
}

void ClientBase::printClientBase() {
    if (root != nullptr)
        root->print();
    else
        cout << "Base is empty" << endl;
}

Client *ClientBase::findClient(ID id) {

    if (root == nullptr) {
        return nullptr;
    }

    return root->findClident(id);
}

int ClientBase::sendMoney(ID sender, char acc, Money sum, ID reciver) {
    Client *s = findClient(sender);
    Client *r = findClient(reciver);

    if (s == nullptr || r == nullptr)
        return NO_ACCOUNT;

    if (getMoneyFromAccount(sender, sum, acc) == OK)
        putMoneyOnAccount(reciver, sum, 'd');
    else
        return NO_MONEY;
    

    return OK;
}
