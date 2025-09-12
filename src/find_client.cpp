#include "../include/bank_system/client_utils.h"
#include "../include/bank_system/client_management.h"
#include "../../../helpers/io_utils.h"
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;


namespace client_management {
  bool findClient(bool showHeader){

      if(showHeader) printHeader("Find client screen");

      vector<stClient> vClients = loadClientsDataFromFile(clientsFileName);

      string accountNumber = io_utils::readString("Please enter account number ? ");

      stClient client;
      
      if (findClientByAccountNumber(accountNumber, vClients, client)) {
          displayClientRecord(client);
          return true;
      } else {
          cout << "\nClient with account number (" << accountNumber << ") is NOT found!\n";
          return false;
      }
  }
}