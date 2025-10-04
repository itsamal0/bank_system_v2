#include "../include/bank_system/identity.h"
#include "../include/bank_system/user_utils.h"
#include "../include/bank_system/client_utils.h"
#include "../include/bank_system/client_management.h"
#include "../include/helpers/io_utils.h"
#include <iostream>
#include <limits>
using namespace std;

namespace manage_users {

    // Update a user by account number
    void updateUser() {
        identity::stUser user;
        char answer = 'N';

        client_management::printHeader("Update user screen");


        string username = io_utils::readString("\nPlease enter username ? ");

        if (username == "Admin" && identity::currentUser.username != "Admin") {
            cout << "\nYou cannot update this user.\n";
            return;
        }

        vector<identity::stUser> vUsers = user_utils::loadUsersDataFromFile(user_utils::usersFileName);

        if (user_utils::findUserByUsername(username, vUsers, user)) {

            user_utils::displayUserRecord(user);

            cout << "\n\nAre you sure you want to update this user? [y/n]: ";
            cin >> answer;

            if (toupper(answer) == 'Y') {
                // Clear input buffer
                cin.ignore(1000, '\n');

                identity::stUser updatedUser;

                updatedUser.username = username;
                updatedUser.password = io_utils::readString("\nEnter new password: ");
                updatedUser.permissions = user_utils::setUserPermissions();

                // Update the user in the vector
                for (identity::stUser &u : vUsers) {
                    if (u.username == username) {
                        u = updatedUser;
                        break;
                    }
                }

                // Save updated users to file
                user_utils::saveUsersDataToFile(user_utils::usersFileName, vUsers);
                cout << "\n\nUser updated successfully.\n";
                return;
            }
        }
        else {
            cout << "\nUser with username (" << username << ") is NOT found!";
        }
    }
}