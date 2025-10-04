#include "../include/bank_system/identity.h"
#include "../include/bank_system/user_utils.h"
#include "../include/bank_system/client_utils.h"
#include "../include/helpers/io_utils.h"
#include <iostream>
#include <limits>
using namespace std;

namespace manage_users {
    bool findUser() {

        client_management::printHeader("Find user screen");

        vector<identity::stUser> vUsers = user_utils::loadUsersDataFromFile(user_utils::usersFileName);

        string username = io_utils::readString("\nPlease enter username ? ");

        identity::stUser user;

        if (user_utils::findUserByUsername(username, vUsers, user)) {
            user_utils::displayUserRecord(user);
            return true;
        }
        else {
            cout << "\nuser with username (" << username << ") is NOT found!\n";
            return false;
        }
    }
}