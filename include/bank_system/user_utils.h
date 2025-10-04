#pragma once
#include <string>
#include <vector>
using namespace std;

namespace user_utils {
    const string usersFileName = "data/users.txt";
    identity::stUser readUserInput();
    identity::stUser convertLineToUserRecord(string str, string separator);
    vector<identity::stUser> loadClientsDataFromFile(string fileName);
    bool findUserByUsername(const string &username, const vector<identity::stUser> &vUsers, identity::stUser &user);
    int setUserPermissions();
}