#include "../include/bank_system/identity.h"
#include "../include/bank_system/user_utils.h"
#include "../include/bank_system/client_utils.h"
#include "../include/bank_system/client_management.h"
#include "../include/helpers/io_utils.h"
#include <iostream>
#include <limits>
using namespace std;

namespace manage_users {

    // Mark a user for deletion
    bool markUserForDeleteByUsername(const string &username, vector<identity::stUser> &vUsers) {
        for (identity::stUser &u : vUsers) {
            if (u.username == username) {
                u.markForDelete = true;
                return true;
            }
        }
        return false;
    }

    // Delete a user by username
    void deleteUser() {
        identity::stUser user;
        char answer = 'N';

        client_management::printHeader("Delete user screen");

        vector<identity::stUser> vUsers = user_utils::loadUsersDataFromFile(user_utils::usersFileName);

        string username = io_utils::readString("\nPlease enter username ? ");

        if (username == "Admin") {
            cout << "\nYou cannot delete this user.\n";
            return;
        }

        if (user_utils::findUserByUsername(username, vUsers, user)) {
            user_utils::displayUserRecord(user);

            cout << "\n\nAre you sure you want to delete this user? (y/n): ";
            cin >> answer;

            if (toupper(answer) == 'Y') {
                markUserForDeleteByUsername(username, vUsers);
                user_utils::saveUsersDataToFile(user_utils::usersFileName, vUsers);

                vUsers = user_utils::loadUsersDataFromFile(user_utils::usersFileName);
                cout << "\n\nUser deleted successfully.\n";
                return;
            }
        }
        else {
            cout << "\nUser with username (" << username << ") is NOT found!\n";
        }
    }
}