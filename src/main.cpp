#include <iostream>
#include <limits>
#include "../include/bank_system/client_management.h"
#include "../../../helpers/io_utils.h"
using namespace std;

enum enMainMenuOptions {
    SHOW_CLIENTS = 1,
    ADD_CLIENT = 2,
    DELETE_CLIENT = 3,
    UPDATE_CLIENT = 4,
    FIND_CLIENT = 5,
    EXIT_PROGRAM = 6
};

void showMainMenu() {
    cout << "=================================\n";
    cout << "          Bank System\n";
    cout << "=================================\n";
    cout << "[1] Show Clients List\n";
    cout << "[2] Add Client\n";
    cout << "[3] Delete Client\n";
    cout << "[4] Update Client Info\n";
    cout << "[5] Find Client\n";
    cout << "[6] Exit\n";
    cout << "=================================\n";
}

int readValidChoice(int initialChoice, int minValue, int maxValue) {
    int choice = initialChoice;
    while (!io_utils::isValidNumber() || !io_utils::isNumberInRange(choice, minValue, maxValue)) {
        cout << "Invalid choice! Please enter a valid number between "
             << minValue << " and " << maxValue << ": ";
        cin >> choice;
    }
    return choice;
}

int readMenuChoice(int minValue, int maxValue) {  
    int choice;  
    cout << "Choose what do you want to do? [" << minValue << " to " << maxValue << "]: ";  
    cin >> choice;  
    return readValidChoice(choice, minValue, maxValue);
}

void bankSystem() {
    int choice = 0;

    do {
        system("cls");

        showMainMenu();
        choice = readMenuChoice(1, 6);

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
        case EXIT_PROGRAM:
            io_utils::exitProgram();
            break;
        }

        if (choice != EXIT_PROGRAM) {
            cout << "\nPress any key to go back to main menu...";
            system("pause >nul");
        }

    } while (choice != EXIT_PROGRAM);
}

int main() {
    bankSystem();
    return 0;
}