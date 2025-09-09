#include "../include/bank_system/client_utils.h"
#include "../include/bank_system/client_management.h"
#include <iostream>
using namespace std;

namespace client_management {
  
    // Add a new client and save to file
    void addClient() {
        char addMore = 'Y';

        do {
            system("cls");
            printHeader("Add new clients screen");

            cout << "\nAdding new client:\n\n";
            stClient client = readNewClient();
            addDataLineToFile(clientsFileName, convertRecordToLine(client));

            cout << "\nClient added successfully. Add another client? [Y/N]: ";
            cin >> addMore;

        } while (toupper(addMore) == 'Y'); 
    }
}