#include <iostream>
#include <limits>
#include "../include/bank_system/client_management.h"
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

void showClients() {
    cout << "Clients list:\n";
}

void deleteClient() {
    cout << "Delete a client\n";
}

void updateClient() {
    cout << "Update client info\n";
}

void findClient() {
    cout << "Find a client\n";
}

void exitProgram() {
    cout << "=================================\n";
    cout << "          Program ends.\n";
    cout << "=================================\n";
    cout << "Press any key to close the program...";
    system("pause >nul");
}

bool isValidNumber() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

bool isNumberInRange(int n, int minValue, int maxValue){
    return n >= minValue && n <= maxValue;
}

int readValidChoice(int initialChoice) {  
    int choice = initialChoice;  
    while (!isValidNumber() || !isNumberInRange(choice, 1, 6)) {  
        cout << "Invalid choice! Please enter a valid number between 1 and 6: ";  
        cin >> choice;  
    }  
    return choice;  
}

int readMenuChoice() {  
    int choice;  
    cout << "Choose what do you want to do? [1 to 6]: ";  
    cin >> choice;  
    return readValidChoice(choice);  
}

void bankSystem() {
    int choice = 0;

    do {
        system("cls");

        showMainMenu();
        choice = readMenuChoice();

        system("cls");

        switch (choice) {
        case SHOW_CLIENTS:
            showClients();
            break;
        case ADD_CLIENT:
            client_management::addClient();
            break;
        case DELETE_CLIENT:
            deleteClient();
            break;
        case UPDATE_CLIENT:
            updateClient();
            break;
        case FIND_CLIENT:
            findClient();
            break;
        case EXIT_PROGRAM:
            exitProgram();
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