#include "../include/bank_system/identity.h"
#include "../include/bank_system/user_utils.h"
#include "../include/bank_system/client_utils.h"
#include <iostream>
using namespace std;

namespace identity {
  bool login() {

    bool loginFaild = false;
    stUser loginAttempt;

    do {
      system("cls");
      client_management::printHeader("Login Screen");

      if (loginFaild) {
        cout << "\nInvalid username or password, try again\n";
      }

      loginAttempt = user_utils::readUserInput();

      loginFaild = !auth(loginAttempt);

    } while (loginFaild);

    return true;
  }
}