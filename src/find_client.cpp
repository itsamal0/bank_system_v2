#include "../include/bank_system/client_utils.h"
#include "../include/bank_system/client_management.h"
#include "../include/helpers/io_utils.h"
#include "../include/bank_system/user_utils.h"
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;


namespace client_management {
  string findClient(bool showHeader){
      if (!user_utils::hasPermission(identity::PERM_FIND_CLIENTS)) {
         user_utils::showAccessDeniedMsg();
         return "";
      }

      if(showHeader) printHeader("Find client screen");

      vector<stClient> vClients = loadClientsDataFromFile(clientsFileName);

      string accountNumber = io_utils::readString("Please enter account number ? ");

      stClient client;
      
      if (findClientByAccountNumber(accountNumber, vClients, client)) {
          displayClientRecord(client);
          return client.accountNumber;
      } else {
          cout << "\nClient with account number (" << accountNumber << ") is NOT found!\n";
          return "";
      }
  }
}