#include "../include/helpers/io_utils.h"
#include "../include/helpers/string_utils.h"
#include "../include/bank_system/identity.h"
#include "../include/bank_system/user_utils.h" 
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
using namespace identity;

namespace user_utils {

    stUser readUserInput() {
        stUser loginAttempt;
        loginAttempt.username = io_utils::readString("\nEnter username: ");
        loginAttempt.password = io_utils::readString("\nEnter password: ");

        return loginAttempt;
    } 

    // Convert a line from file to a user struct
    stUser convertLineToUserRecord(string str, string separator = "#//#") {
        stUser newUser;
        vector<string> vString = string_utils::splitString(str, separator);

        newUser.username = vString[0];
        newUser.password = vString[1];
        newUser.permissions = stoi(vString[2]);

        return newUser;
    }

    // Convert a user struct to a single line string with separator
    string convertUserRecordToLine(stUser user, string separator) {
        string stUserRecord = "";
        stUserRecord += user.username + separator;
        stUserRecord += user.password + separator;
        stUserRecord += to_string(user.permissions);
        return stUserRecord;
    }


    // Load users data from file into a vector
    vector<stUser> loadUsersDataFromFile(string fileName) {
        vector<stUser> vUsers;
        fstream myFile;
        myFile.open(fileName, ios::in);

        if (myFile.is_open()) {
            string line;
            while (getline(myFile, line)) {
                vUsers.push_back(convertLineToUserRecord(line));
            }
            myFile.close();
        }

        return vUsers;
    }

    // Find a user by username
    bool findUserByUsername(const string &username, const vector<stUser> &vUsers, stUser &foundUser){
        for (const stUser &u : vUsers){
            if (u.username == username) {
                foundUser = u;
                return true;
            }
        }
        return false;
    }

    // Save all users back to file
    vector<stUser> saveUsersDataToFile(const string &fileName, const vector<stUser> &vUsers) {
        fstream myFile(fileName, ios::out);

        if (myFile.is_open()) {
            for (const stUser &u : vUsers) {
                if (!u.markForDelete) {
                    myFile << convertUserRecordToLine(u, "#//#") << endl;
                }
            }
            myFile.close();
        }

        return vUsers;
    }

    // Print a single user record
    void displayUserRecord(const stUser &user) {
        cout << "\n\nThe following are the user details:\n";
        cout << "****************************************";
        cout << "\nUsername       : " << user.username;
        cout << "\nPassword       : " << user.password;
        cout << "\nPermissions    : " << user.permissions;
        cout << "\n****************************************\n";
    }

    int setUserPermissions() {
        char answer = 'N';
        int permissions = 0;

        cout << "\nDo you want to give full access? [y/n]: ";
        cin >> answer;

        if (toupper(answer) == 'Y') {
            return identity::PERM_ALL;
        }

        cout << "\nDo you want to give access to: \n";

        cout << "\nShow client list? [y/n]: ";
        cin >> answer;

        if (toupper(answer) == 'Y')
            permissions += identity::PERM_SHOW_CLIENTS;

        cout << "\nAdd client? [y/n]: ";
        cin >> answer;

        if (toupper(answer) == 'Y')
            permissions += identity::PERM_ADD_CLIENT;

        cout << "\nDelete client? [y/n]: ";
        cin >> answer;

        if (toupper(answer) == 'Y')
            permissions += identity::PERM_DELETE_CLIENTS;

        cout << "\nUpdate client info? [y/n]: ";
        cin >> answer;

        if (toupper(answer) == 'Y')
            permissions += identity::PERM_UPDATE_CLIENTS;

        cout << "\nFind client? [y/n]: ";
        cin >> answer;

        if (toupper(answer) == 'Y')
            permissions += identity::PERM_FIND_CLIENTS;

        cout << "\nTransactions? [y/n]: ";
        cin >> answer;

        if (toupper(answer) == 'Y')
            permissions += identity::PERM_TRANSACTIONS;

        cout << "\nManage users? [y/n]: ";
        cin >> answer;

        if (toupper(answer) == 'Y')
            permissions += identity::PERM_MANAGE_USERS;

        return permissions;
    }

    // Read new user data from user
    stUser readNewUser() {
        stUser newUser;
        bool userExists = false;

        vector<stUser> vUsers = loadUsersDataFromFile(usersFileName);
        stUser foundUser;

        do {
            newUser.username = io_utils::readString("\nEnter username: ");

            userExists = findUserByUsername(newUser.username, vUsers, foundUser);

            if (userExists) {
                cout << "\nUser with [" << newUser.username << "] already exists, enter another username.\n";
            }

        } while (userExists);

        newUser.password = io_utils::readString("\nEnter password: ");
        newUser.permissions = setUserPermissions();
        newUser.markForDelete = false;

        return newUser;
    }

    bool hasPermission(identity::enPermissions permission) {
        if (permission == identity::enPermissions::PERM_ALL || (identity::currentUser.permissions & permission)) {
            return true;
        }

        return false;
    }

    void showAccessDeniedMsg(){
        cout << "\n----------------------------------------------\n";
        cout << "\nAccess denied, \nYou don't have permission to do this, \nPlease contact your admin.\n";
        cout << "\n----------------------------------------------\n";
    }

}