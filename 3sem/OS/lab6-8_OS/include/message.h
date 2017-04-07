#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#define STR_SIZE 100
#include <string>
using namespace std;

typedef string ID;
typedef int Money;
typedef char Type;

typedef struct {
    ID clientId;
    Money sum;
    Type acc;
    int action;
    int receiverClientId;
    char message[STR_SIZE];
} MessageData;

#endif