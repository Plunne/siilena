#include "bank.h"
#include <stdlib.h>
#include <stdio.h>

Bank* create_bank(User* userList, int* nbrUser, Account* accountList, int* nbrAccount) {
    Bank* bank = malloc(sizeof(Bank));
    bank->users = userList;
    bank->num_users = nbrUser;
    bank->accounts = accountList;
    bank->num_accounts = nbrAccount;
    return bank;
}

void transfer_money(Bank* bank, char* sender, char* receiver, double amount) {
    User* senderUser = get_user(sender);
    if (senderUser == NULL) {
        printf("Error: sender not found\n");
        return;
    }
    User* receiverUser = get_user(receiver);
    if (receiverUser == NULL) {
        printf("Error: receiver not found\n");
        return;
    }
    Account* senderAccount = get_account(senderUser->id);
    if (senderAccount == NULL) {
        printf("Error: sender account not found\n");
        return;
    }
    Account* receiverAccount = get_account(receiverUser->id);
    if (receiverAccount == NULL) {
        printf("Error: receiver account not found\n");
        return;
    }
    if (senderAccount->balance < amount) {
        printf("Error: insufficient funds\n");
        return;
    }
    withdraw(senderAccount, amount);
    deposit(receiverAccount, amount);
}

void destroy_bank(Bank* bank) {
    free(bank);
}

void add_user(Bank* bank, char* name) {
    create_user(*bank->num_users, name);
}

void add_account(Bank* bank, char* name, int balance) {
    User* user = get_user(name);
    create_account(user->id, balance);
}