#include "../include/bank_system/identity.h"
#include "../include/bank_system/user_utils.h"
#include "../include/bank_system/client_utils.h"
#include "../include/bank_system/client_management.h"
#include <iostream>
#include <limits>
using namespace std;

namespace manage_users {
    // Add a new user and save to file
    void addUser() {
        char addMore = 'N';

        do {
            system("cls");
            client_management::printHeader("Add new user screen");

            cout << "\nAdding new user:\n\n";
            identity::stUser client = user_utils::readNewUser();
            client_management::addDataLineToFile(user_utils::usersFileName, user_utils::convertUserRecordToLine(client, "#//#"));

            cout << "\nUser added successfully. Add another user? [Y/N]: ";
            cin >> addMore;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        } while (toupper(addMore) == 'Y');
    }
}