#include <iostream>
#include <limits>
#include <vector>
#include "../include/bank_system/client_management.h"
#include "../include/helpers/io_utils.h"
#include "../include/bank_system/menu_utils.h"
#include "../include/bank_system/transactions.h"
#include "../include/bank_system/identity.h"
#include "../include/bank_system/manage_users.h"
using namespace std;

enum enMainMenuOptions {
    SHOW_CLIENTS = 1,
    ADD_CLIENT = 2,
    DELETE_CLIENT = 3,
    UPDATE_CLIENT = 4,
    FIND_CLIENT = 5,
    TRANSACTIONS = 6,
    MANAGE_USERS = 7,
    EXIT_PROGRAM = 8
};

vector<string> mainMenuOptions = {
    "Show Clients List",
    "Add Client",
    "Delete Client",
    "Update Client Info",
    "Find Client",
    "Transactions",
    "Manage Users",
    "Logout"
};

void showMainMenu() {
    int choice = 0;

    do {
        system("cls");

        menu_utils::showMenu("Bank System", mainMenuOptions);
        choice = menu_utils::readMenuChoice(1, mainMenuOptions.size());

        system("cls");

        switch (choice) {
        case SHOW_CLIENTS:
            client_management::showClients();
            break;
        case ADD_CLIENT:
            client_management::addClient();
            break;
        case DELETE_CLIENT:
            client_management::deleteClient();
            break;
        case UPDATE_CLIENT:
            client_management::updateClient();
            break;
        case FIND_CLIENT:
            client_management::findClient();
            break;
        case TRANSACTIONS:
            transactions::showTransactionMenu();
            break;
        case MANAGE_USERS:
            manage_users::showManageUsersMenu();
            break;
        case EXIT_PROGRAM:
            io_utils::exitProgram();
            break;
        }

        if (choice != EXIT_PROGRAM && choice != TRANSACTIONS && choice != MANAGE_USERS) {
            cout << "\nPress any key to go back to main menu...";
            system("pause >nul");
        }

    } while (choice != EXIT_PROGRAM);
}

void bankSystem() {
    bool loginSuccessful = identity::login();

    if (loginSuccessful)
        showMainMenu();
}

int main() {
    system("cls");
    bankSystem();
    return 0;
}