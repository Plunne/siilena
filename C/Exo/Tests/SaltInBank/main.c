#include "Bank.h"
#include <stdio.h>

Account listAccount[MAX_ACCOUNT];
int numAccounts = 0;

User listUser[MAX_USER];
int numUsers = 0;

int main() {
    Bank* bank = create_bank(listAccount, &numAccounts, listUser, &numUsers);

    create_user(1, "Alice");
    create_account(1, 1000.0);

    create_user(2, "Bob");
    create_account(2, 500.0);

    transfer_money(bank, "Alice", "Bob", 500.0);

    Account* account1 = get_account(1);
    Account* account2 = get_account(2);

    printf("Alice's balance: %.2f\n", account1->balance);
    printf("Bob's balance: %.2f\n", account2->balance);

    return 0;
}
