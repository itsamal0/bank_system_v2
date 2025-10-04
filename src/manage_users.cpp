#include <iostream>
#include <vector>
#include <string>
#include "../include/bank_system/manage_users.h"
#include "../include/bank_system/menu_utils.h"
using namespace std;

namespace manage_users {
    enum enManageUsersMenuOptions {
        LIST_USERS = 1,
        ADD_USER,
        DELETE_USER,
        UPDATE_USER,
        FIND_USER,
        MAIN_MENU,
    };

    vector<string> vManageUsersMenuOptions = {
        "List users",
        "Add new user",
        "Delete user",
        "Update user",
        "Find user",
        "Main menu",
    };

    void showManageUsersMenu() {
        int choice = 0;

        do {
            system("cls");

            menu_utils::showMenu("Manage Users Menu", vManageUsersMenuOptions);

            choice = menu_utils::readMenuChoice(1, vManageUsersMenuOptions.size());

            system("cls");

            switch (choice) {
                case LIST_USERS:
                    manage_users::showUsers();
                    break;
                case ADD_USER:
                    manage_users::addUser();
                    break;
                case DELETE_USER:
                    manage_users::deleteUser();
                    break;
                case UPDATE_USER:
                    cout << "\nUpdate user\n";
                    break;
                case FIND_USER:
                    cout << "\nFind user\n";
                    break;
            }

            if (choice != MAIN_MENU) {
                cout << "\nPress any key to go back to main menu...";
                system("pause >nul");
            }


        } while (choice != MAIN_MENU);
    }

}