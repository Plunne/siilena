#include <stdlib.h>

#include "gtest/gtest.h"

extern "C" {
    #include "../user.h"
}
User listUser[MAX_USER];
int numUsers = 0;
/*
*/
TEST(UserTest, CreateUser_id_negatif) {
    bool result = create_user(-1, "Test");
    EXPECT_FALSE(result);
    EXPECT_EQ(numUsers, 0);
    EXPECT_EQ(errno, EINVAL);
}

TEST(UserTest, CreateUser_id_too_large) {
    bool result = create_user(MAX_USER, "Test");
    EXPECT_FALSE(result);
    EXPECT_EQ(numUsers, 0);
}

TEST(UserTest, CreateUser_name_too_small) {
    bool result = create_user(0, "");
    EXPECT_FALSE(result);
    EXPECT_EQ(numUsers, 0);
}

TEST(UserTest, CreateUser_name_too_large) {
    char* adresse = (char*)malloc(51);
    bool result = create_user(0, adresse);
    EXPECT_FALSE(result);
    EXPECT_EQ(numUsers, 0);
}

TEST(UserTest, Create_User_valid) {
    bool result = create_user(0, "Alice");
    EXPECT_TRUE(result);
    
    EXPECT_STREQ(listUser[0].name, "Alice");
    EXPECT_EQ(listUser[0].id, 0);

    EXPECT_EQ(numUsers, 1); 
}
/*
*/
TEST(UserTest, Get_User_Valid) {
    User* result = get_user("Alice");
    ASSERT_TRUE(result != nullptr);
    EXPECT_EQ(result->id, 0);
    EXPECT_STREQ(result->name, "Alice");
}

TEST(UserTest, Get_User_Invalid) {
    User* result = get_user("Ali");
    EXPECT_EQ(result, nullptr);
}

TEST(UserTest, Creat_User_AlreadyExists) {
    bool result1 = create_user(1, "Alicia");
    EXPECT_TRUE(result1);
    EXPECT_STREQ(listUser[1].name, "Alicia");
    EXPECT_EQ(listUser[1].id, 1);
    EXPECT_EQ(numUsers, 2); 
    
    bool result2 = create_user(2, "Alicia");
    EXPECT_FALSE(result2);

}

TEST(UserTest, Get_User_NotLetters) {
    User* result = get_user("Alice2");
    EXPECT_EQ(result, nullptr);
}

TEST(UserTest, Get_User_FirstCap) {
    User* result = get_user("alice");
    EXPECT_EQ(result, nullptr);
}

