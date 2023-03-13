#ifndef USER_H
#define USER_H

#define MAX_NAME 50
#define MAX_USER 100

#include <stdbool.h>
#include <errno.h>

typedef struct {
    int id;
    char name[MAX_NAME];
} User;

extern User listUser[MAX_USER];
extern int numUsers;

bool create_user(int id, char* name);

User* get_user(char* name);

#endif /* USER_H */
