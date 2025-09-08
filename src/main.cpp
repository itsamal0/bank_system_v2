#include <iostream>
#include <limits>
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

void addClient() {
    cout << "Add a new client\n";
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

int main() {
    return 0;
}