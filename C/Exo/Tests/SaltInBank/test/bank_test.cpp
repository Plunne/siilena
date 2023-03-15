#include <stdlib.h>

#include "gtest/gtest.h"

extern "C" {
	#include "../bank.h"
}

User listUser[MAX_USER];
int numUsers;
Account listAccount[MAX_ACCOUNT];
int numAccounts;

class BankTest : public ::testing::TestWithParam<std::tuple<User*, int*, Account*, int*>> {};

TEST_P(BankTest, BankCreation) {

	User* liUser		= std::get<0>(GetParam());
	int *nUsers			= std::get<1>(GetParam());
	Account* liAccount	= std::get<2>(GetParam());
	int *nAccount		= std::get<3>(GetParam());
	Bank* bank = create_bank(liUser, nUsers, liAccount, nAccount);

	EXPECT_EQ(bank, nullptr);
}

INSTANTIATE_TEST_SUITE_P(
	CreateBank, BankTest,
	::testing::Values(
		std::make_tuple(nullptr,	&numUsers,	listAccount,	&numAccounts),
		std::make_tuple(listUser,	nullptr,	listAccount,	&numAccounts),
		std::make_tuple(listUser,	&numUsers,	nullptr,		&numAccounts),
		std::make_tuple(listUser,	&numUsers,	listAccount,	nullptr)
	)
);

/*
*/
