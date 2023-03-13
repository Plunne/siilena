#ifndef BANK_H
#define BANK_H

#include "user.h"
#include "account.h"

typedef struct {
    User* users;    // a pointer to an array of users
    int* num_users;  // the number of users in the array
    Account* accounts; // a pointer to an array of accounts
    int* num_accounts; // the number of accounts in the array
} Bank;

Bank* create_bank(User*, int*, Account*, int*);

void add_user(Bank* bank, char* name);

void add_account(Bank* bank, char* name, int balance);

void transfer_money(Bank* bank, char* sender, char* receiver, double amount);

void destroy_bank(Bank* bank);

#endif /* BANK_H */
