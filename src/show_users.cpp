#include "../include/bank_system/identity.h"
#include "../include/bank_system/user_utils.h"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

namespace manage_users {

    void printUserRecord(const identity::stUser &user) {
        cout << "| " << setw(16) << left << user.username;
        cout << "| " << setw(10) << left << user.password;
        cout << "| " << setw(15) << left << user.permissions;
        cout << endl;
    }

    void showUsers() {
        vector<identity::stUser> vUsers = user_utils::loadUsersDataFromFile(user_utils::usersFileName);

        if (vUsers.empty()) {
            cout << "There are no users yet!\n";
            return;
        }

        cout << "\n\t\t\t\t\tUser list (" << vUsers.size() << ") user(s).\n";

        cout << "\n" << string(50, '_') << "\n";

        cout << "\n| " << setw(16) << left << "Username"
             << "| " << setw(10) << left << "Password"
             << "| " << setw(15) << left << "Permissions";

        cout << "\n" << string(50, '_') << "\n\n";

        for (const identity::stUser &user : vUsers) {
            printUserRecord(user);
        }

        cout << "\n"
             << string(50, '_') << "\n";
    }
}