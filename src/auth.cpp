#include "../include/bank_system/identity.h"
#include "../include/bank_system/user_utils.h"
#include <iostream>
#include <vector>
using namespace std;

namespace identity
{
    bool auth(const stUser &loginAttempt)
    {
        vector<stUser> vUsers = user_utils::loadUsersDataFromFile(user_utils::usersFileName);
        stUser foundUser;

        if (user_utils::findUserByUsername(loginAttempt.username, vUsers, foundUser))
        {
            if (foundUser.password == loginAttempt.password)
            {
                currentUser = foundUser;
                return true;
            }
        }

        return false;
    }
}