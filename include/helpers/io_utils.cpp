#include "io_utils.h"
#include "string_utils.h"
#include <iostream>
#include <limits>
using namespace std;

namespace io_utils {

    string readString(const string& message) {
        string str;
        do {

            cout << message;
            getline(cin, str);

            str = string_utils::trim(str);
            
            if (str.empty()) 
                cout << "Input cannot be empty, please try again.\n";

        } while (str.empty());

        return str;
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

    int readPositiveNumber(const string& message) {
        int num;
        bool validInput = false;
        do {
            cout << message;
            cin >> num;
            if (cin.fail() || num <= 0) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Please enter a positive number.\n";
            } else {
                validInput = true;
            }
        } while (!validInput);
        return num;
    }

    char readLetter(const string& message) {
        char c;
        cout << message;
        cin >> c;
        return c;
    }

    void exitProgram() {
        cout << "=================================\n";
        cout << "          Program ends.\n";
        cout << "=================================\n";
        cout << "Press any key to close the program...";
        system("pause >nul");
    }

}