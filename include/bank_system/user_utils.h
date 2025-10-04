#pragma once
#include <string>
#include <vector>
using namespace std;

namespace user_utils {
    const string usersFileName = "data/users.txt";
    identity::stUser readUserInput();
    identity::stUser convertLineToUserRecord(string str, string separator);
    string convertUserRecordToLine(identity::stUser user, string separator);
    vector<identity::stUser> loadUsersDataFromFile(string fileName);
    bool findUserByUsername(const string &username, const vector<identity::stUser> &vUsers, identity::stUser &user);
    vector<identity::stUser> saveUsersDataToFile(const string &fileName, const vector<identity::stUser> &vUsers);
    void displayUserRecord(const identity::stUser &user);
    int setUserPermissions();
    identity::stUser readNewUser();
}