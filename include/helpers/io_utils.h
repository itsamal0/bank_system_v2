#pragma once
#include <string>
#include <iostream>
using namespace std;

namespace io_utils {
    string readString(const string& message);
    int readPositiveNumber(const string& message);
    char readLetter(const string& message);
    void exitProgram();
    bool isValidNumber();
    bool isNumberInRange(int n, int minValue, int maxValue);

    template<typename T>
    T readPositiveValue(const string& message) {
        T num;
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
}