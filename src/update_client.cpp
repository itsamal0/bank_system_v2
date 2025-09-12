#include "../include/bank_system/client_utils.h"
#include "../include/bank_system/client_management.h"
#include "../../../helpers/io_utils.h"
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;


namespace client_management {

    // Update a client by account number
    void updateClient() {
        stClient client;
        char answer = 'n';

        printHeader("Update client screen");

        vector<stClient> vClients = loadClientsDataFromFile(clientsFileName);
            
        string accountNumber = io_utils::readString("Please enter account number ? ");

        if (findClientByAccountNumber(accountNumber, vClients, client)) {
            displayClientRecord(client);

            cout << "\n\nAre you sure you want to update this client? (y/n): ";
            cin >> answer;

            if (toupper(answer) == 'Y') {
                // Clear input buffer
                cin.ignore(1000, '\n');

                stClient updatedClient;
                updatedClient.accountNumber = accountNumber;
                updatedClient.pinCode = io_utils::readString("\nEnter new pin code: ");
                updatedClient.name = io_utils::readString("\nEnter new name: ");
                updatedClient.phone = io_utils::readString("\nEnter new phone: ");
                updatedClient.accountBalance = io_utils::readPositiveNumber("\nEnter new account balance: ");

                // Update the client in the vector
                for (stClient& c : vClients) {
                    if (c.accountNumber == accountNumber) {
                        c = updatedClient;
                        break;
                    }
                }

                // Save updated clients to file
                saveClientsDataToFile(clientsFileName, vClients);
                cout << "\n\nClient updated successfully.\n";
                return;
            }
        } else {
            cout << "\nClient with account number (" << accountNumber << ") is NOT found!";
        }
    }
}