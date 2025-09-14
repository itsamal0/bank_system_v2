#include <iostream>
#include <limits>
#include "../include/bank_system/menu_utils.h"
#include "../include/helpers/io_utils.h"
using namespace std;

namespace menu_utils {

    void showMenu(const string& title, const vector<string>& options) {
        cout << "=================================\n";
        cout << "          " << title << "\n";
        cout << "=================================\n";
        for (int i = 0; i < options.size(); i++) {
            cout << "[" << i + 1 << "] " << options[i] << "\n";
        }
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        return readValidChoice(choice, minValue, maxValue);
    }
}