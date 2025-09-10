#include "../include/bank_system/client_utils.h"
#include "../include/bank_system/client_management.h"
#include "../../../helpers/io_utils.h"
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;


namespace client_management {
    // Mark a client for deletion
    bool markClientForDeleteByAccountNumber(const string& accountNumber, vector<stClient>& vClients) {
        for (stClient& c : vClients) {
            if (c.accountNumber == accountNumber) {
                c.markForDelete = true;
                return true;
            }
        }
        return false;
    }

    // Save all clients back to file
    vector<stClient> saveClientsDataToFile(const string& fileName, const vector<stClient>& vClients) {
        fstream myFile(fileName, ios::out);

        if (myFile.is_open()) {
            for (const stClient& c : vClients) {
                if (!c.markForDelete) {
                    myFile << convertRecordToLine(c) << endl;
                }
            }
            myFile.close();
        }

        return vClients;
    }

    // Delete a client by account number
    void deleteClient() {
        stClient client;
        char answer = 'n';

        vector<stClient> vClients = loadClientsDataFromFile(clientsFileName);
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string accountNumber = io_utils::readString("Please enter account number ? ");

        if (findClientByAccountNumber(accountNumber, vClients, client)) {
            displayClientRecord(client);

            cout << "\n\nAre you sure you want to delete this client? (y/n): ";
            cin >> answer;

            if (toupper(answer) == 'Y') {
                markClientForDeleteByAccountNumber(accountNumber, vClients);
                saveClientsDataToFile(clientsFileName, vClients);

                vClients = loadClientsDataFromFile(clientsFileName);
                cout << "\n\nClient deleted successfully.\n";
                return;
            }
        } else {
            cout << "\nClient with account number (" << accountNumber << ") is NOT found!\n";
        }

    }
}