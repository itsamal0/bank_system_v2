#include <iostream>
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


int main() {
    return 0;
}