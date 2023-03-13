#include <stdlib.h>

#include "gtest/gtest.h"

extern "C" {
    #include "../account.h"
}
Account listAccount[MAX_ACCOUNT];
int numAccounts = 0;
/*
*/
TEST(AccountTest, CreateAccount_id_negative) {
    bool result = create_account(-1, 1353.00);
    EXPECT_FALSE(result);
    EXPECT_EQ(numAccounts, 0);
    EXPECT_EQ(errno, EINVAL);
}

TEST(AccountTest, CreateAccount_id_too_large) {
    bool result = create_account(MAX_ACCOUNT, 1353.00);
    EXPECT_FALSE(result);
    EXPECT_EQ(numAccounts, 0);
    EXPECT_EQ(errno, EINVAL);
}

TEST(AccountTest, CreateAccount_balance_too_small) {
    bool result = create_account(0, -1);
    EXPECT_FALSE(result);
    EXPECT_EQ(numAccounts, 0);
    EXPECT_EQ(errno, EDOM);
}

TEST(AccountTest, CreateAccount_balance_too_large) {
    bool result = create_account(0, DBL_MAX);
    EXPECT_FALSE(result);
    EXPECT_EQ(numAccounts, 0);
    EXPECT_EQ(errno, EDOM);
}

TEST(AccountTest, Create_Account_Valid) {
    bool result = create_account(0, 1353.00);
    EXPECT_TRUE(result);
    
    EXPECT_EQ(listAccount[0].balance, 1353.00);
    EXPECT_EQ(listAccount[0].id, 0);

    EXPECT_EQ(numAccounts, 1); 
}

TEST(AccountTest, Get_Account_Valid) {
    Account* result = get_account(0);
    ASSERT_TRUE(result != nullptr);
    EXPECT_EQ(result->id, 0);
    EXPECT_EQ(result->balance, 1353.00);
}

TEST(AccountTest, Get_Account_Invalid) {
    Account* result = get_account(1);
    ASSERT_TRUE(result == nullptr);
    EXPECT_EQ(result, nullptr);
}

TEST(AccountTest, Creat_Account_AlreadyExists) {
    bool result1 = create_account(1, 2000.50);
    EXPECT_TRUE(result1);
    EXPECT_EQ(listAccount[1].balance, 2000.50);
    EXPECT_EQ(listAccount[1].id, 1);
    EXPECT_EQ(numAccounts, 2); 
    
    bool result2 = create_account(1, 2050.50);
    EXPECT_FALSE(result2);

}

TEST(AccountTest, Withdraw_Success) {
    Account* account = get_account(1);
    ASSERT_TRUE(account != nullptr);
    bool result = withdraw(account, 812.50);
    EXPECT_TRUE(result);
    EXPECT_EQ(listAccount[1].balance, 2000.50 - 812.50);

}

TEST(AccountTest, Withdraw_Failed) {
    Account* account = get_account(1);
    ASSERT_TRUE(account != nullptr);
    bool result = withdraw(account, 2001.00);
    EXPECT_FALSE(result);
    EXPECT_EQ(listAccount[1].balance, 1188);

}

TEST(AccountTest, Deposit_Succes) {
    Account* account = get_account(1);
    ASSERT_TRUE(account != nullptr);
    bool result = deposit(account, 812.50);
    EXPECT_TRUE(result);
    EXPECT_EQ(listAccount[1].balance, 1188 + 812.50);

}

TEST(AccountTest, Deposit_Failed) {
    Account* account = get_account(1);
    ASSERT_TRUE(account != nullptr);
    bool result = deposit(account, DBL_MAX);
    EXPECT_FALSE(result);
    EXPECT_EQ(listAccount[1].balance, 2000.50);

}
/*
*/
