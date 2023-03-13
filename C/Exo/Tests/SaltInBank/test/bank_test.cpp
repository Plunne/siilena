#include <stdlib.h>

#include "gtest/gtest.h"

extern "C" {
	#include "../bank.h"
}

User listUser[MAX_USER];
int numUsers;
Account listAccount[MAX_ACCOUNT];
int numAccounts;


TEST(BankTest, Create_Bank_Valid) {
    Bank* bank = create_bank(listUser, &numUsers, listAccount, &numAccounts);
    EXPECT_TRUE(bank != nullptr);
    EXPECT_EQ(bank->users, listUser);
    EXPECT_EQ(bank->num_users, &numUsers);
    EXPECT_EQ(bank->accounts, listAccount);
    EXPECT_EQ(bank->num_accounts, &numAccounts);
}


/*
*/
