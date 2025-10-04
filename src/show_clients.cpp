#include "../include/bank_system/client_utils.h"
#include "../include/bank_system/show_clients.h"
#include "../include/bank_system/client_management.h"
#include "../include/bank_system/user_utils.h"
#include <iostream>
#include <iomanip>
using namespace std;

namespace client_management {

    // Print a single client record
    void printClientRecord(stClient client, bool summaryMode) {

        cout << "| " << setw(16) << left  << client.accountNumber;

        if(!summaryMode) 
            cout << "| " << setw(10) << left  << client.pinCode;

        cout << "| " << setw(20) << left  << client.name;

        if(!summaryMode) 
            cout << "| " << setw(15) << left  << client.phone;

        cout << "| " << setw(10) << left << client.accountBalance;
        cout << endl;
    }

    // Print all clients in a formatted table
    double showClients(bool summaryMode) {
        if (!user_utils::hasPermission(identity::PERM_SHOW_CLIENTS)) {
            user_utils::showAccessDeniedMsg();
            return 0;
        }

        double totalBalances = 0;

        vector<stClient> vClients = loadClientsDataFromFile(clientsFileName);
        
        if(vClients.size() == 0) {
          cout << "There is no clients yet!\n";
          return 0;
        }

        cout << "\n\t\t\t\t\t\tClient list (" << vClients.size() << ") client(s).\n";

        cout << "\n" << string(100, '_') << "\n";

        cout << "\n| " << setw(16) << left << "Account Number";

        if(!summaryMode) 
            cout << "| " << setw(10) << left << "Pin Code";

        cout << "| " << setw(20) << left << "Client Name";

        if(!summaryMode) 
            cout << "| " << setw(15) << left << "Phone";

        cout << "| " << setw(10) << right << "Balance";
        cout << "\n" << string(100, '_') << "\n\n";

        for (stClient& client : vClients) {
            printClientRecord(client, summaryMode);
            cout << endl;

            if(summaryMode) totalBalances += client.accountBalance;
        }
        
        cout << "\n" << string(100, '_') << "\n";

        return summaryMode ? totalBalances : 0;
    }
}