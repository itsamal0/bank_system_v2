#pragma once
#include <string>

namespace identity {

    enum enPermissions {
        PERM_ALL             = -1,
        PERM_SHOW_CLIENTS    = 1,
        PERM_ADD_CLIENT      = 2,
        PERM_DELETE_CLIENTS  = 4,
        PERM_UPDATE_CLIENTS  = 8,
        PERM_FIND_CLIENTS    = 16,
        PERM_TRANSACTIONS    = 32,
        PERM_MANAGE_USERS    = 64
    };


    struct stUser {
        std::string username;
        std::string password;
        int permissions;
        bool markForDelete = false;
    };

    extern stUser currentUser;

    bool login();
    stUser registerUser();
    bool auth(const stUser& loginAttempt);
}