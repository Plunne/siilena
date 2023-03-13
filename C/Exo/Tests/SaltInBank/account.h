#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "user.h"
#include <stdbool.h>
#include <stdlib.h>
#include <float.h>

#define MAX_ACCOUNT 100

typedef struct {
    int id;
    double balance;
} Account;

extern Account listAccount[MAX_ACCOUNT];
extern int numAccounts;

bool create_account(int id, double balance);

Account* get_account(int id);

bool withdraw(Account* account, double amount);

bool deposit(Account* account, double amount);

#endif /* ACCOUNT_H */
