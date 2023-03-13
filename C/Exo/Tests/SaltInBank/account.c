#include "account.h"

bool create_account(int id, double balance) {

    /* Check id too high */
    if ((id < 0) || (id >= MAX_USER)) {
        errno = EINVAL;
        return false;
    }

    if ((balance < 0) || (balance >= DBL_MAX)) {
        errno = EDOM;
        return false;
    }

    /* Check if already exists */
    if (get_account(id) != NULL) return false;
    
    if ((numAccounts >= 0) && (numAccounts < MAX_ACCOUNT)) {

		Account account = { id, balance };
		listAccount[id] = account;
		numAccounts++;
		return true;
    }
    else {
        return false;
    }
}

Account* get_account(int id) {
    for (int i = 0; i < numAccounts; i++) {
        if (listAccount[i].id == id) {
            return &listAccount[i];
        }
    }
    return NULL;
}

bool withdraw(Account* account, double amount) {

    if ((account->balance - amount) < 0) {
        errno = EDOM;
        return false;
    }
    else {
        account->balance -= amount;
        return true;
    }
}

bool deposit(Account* account, double amount) {
    
    if ((account->balance + amount) >= DBL_MAX) {
        errno = EDOM;
        return false;
    }
    else {
        account->balance += amount;
        return true;
    }
}
