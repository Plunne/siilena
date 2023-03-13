#include "user.h"
#include <string.h>

bool create_user(int id, char* name) {

    /* Check to long */
    if ((strlen(name) < 3) || (strlen(name) > MAX_NAME)) {
        errno = EINVAL;
        return false;
    }

    /* Check id too high */
    if ((id < 0) || (id >= MAX_USER)) {
        errno = EDOM;
        return false;
    }
    
    /* Check if already exists */
    if (get_user(name) != NULL) return false;
    
    /* Increment numUser */
    if ((numUsers >= 0) && (numUsers < MAX_USER)) {
    
        /* Init User */
        User user = { id, "" };

        /* Set new name */
        strncpy(user.name, name, MAX_NAME);
    
        /* Inc user */
        listUser[id] = user;
        numUsers++;
        return true;
    }
    else {
        return false;
    }
}

User* get_user(char* name) {
    
    /* Check is Letter */
    for (int i = 0; i < strlen(name); i++) {
        if (!(((name[i] >= 'a') && (name[i] <= 'z'))
            || ((name[i] >= 'A') && (name[i] <= 'Z'))))
        {
            return NULL;
        }
    }

    /* Check starts with Caps */
    if (!((name[0] >= 'A') && (name[0] <= 'Z'))) return NULL;

    /* Check is in list */
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(listUser[i].name, name) == 0) {
            return &listUser[i];
        }
    }
    return NULL;
}