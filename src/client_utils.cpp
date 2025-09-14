#include <iostream>
#include <fstream>
#include <limits>
#include "../include/bank_system/client_utils.h"
#include "../../../helpers/io_utils.h"
#include "../../../helpers/string_utils.h"
using namespace std;

namespace client_management {

    void printHeader(string headerText){
        cout << "-------------------------------------\n";
        cout << "\t" << headerText << endl;
        cout << "-------------------------------------\n";
    }

    // Convert a client struct to a single line string with separator
    string convertRecordToLine(stClient client, string separator) {
        string stClientRecord = "";
        stClientRecord += client.accountNumber + separator;
        stClientRecord += client.pinCode + separator;
        stClientRecord += client.name + separator;
        stClientRecord += client.phone + separator;
        stClientRecord += to_string(client.accountBalance);
        return stClientRecord;
    }

    // Read new client data from user
    stClient readNewClient() {
        stClient newClient;
        newClient.accountNumber   = io_utils::readString("\nEnter account number: ");
        newClient.pinCode         = io_utils::readString("\nEnter pin code: ");
        newClient.name            = io_utils::readString("\nEnter name: ");
        newClient.phone           = io_utils::readString("\nEnter phone number: ");
        newClient.accountBalance  = io_utils::readPositiveValue<double>("\nEnter account balance: ");
        return newClient;
    }

    // Add a single line of data to a file
    void addDataLineToFile(const string& fileName, const string& stDataLine) {
        fstream myFile;
        myFile.open(fileName, ios::out | ios::app);
        if (myFile.is_open()) {
            myFile << stDataLine << endl;
            myFile.close();
        } else {
            cout << "\nError: Unable to open file " << fileName << endl;
        }
    }
   
    // Convert a line from file to a client struct
    stClient convertLineToRecord(string str, string separator) {
        stClient newClient;
        vector<string> vString = string_utils::splitString(str, separator);

        newClient.accountNumber  = vString[0];
        newClient.pinCode        = vString[1];
        newClient.name           = vString[2];
        newClient.phone          = vString[3];
        newClient.accountBalance = stod(vString[4]);

        return newClient;
    }

    // Load clients data from file into a vector
    vector<stClient> loadClientsDataFromFile(string fileName) {
        vector<stClient> vClients;
        fstream myFile;
        myFile.open(fileName, ios::in);

        if (myFile.is_open()) {
            string line;
            while (getline(myFile, line)) {
                vClients.push_back(convertLineToRecord(line));
            }
            myFile.close();
        }

        return vClients;
    }

    // Find a client by account number
    bool findClientByAccountNumber(const string& accountNumber, const vector<stClient>& vClients, stClient& client) {
        for (const stClient& c : vClients) {
            if (c.accountNumber == accountNumber) {
                client = c;
                return true;
            }
        }
        return false;
    }

    
    // Print a single client record
    void displayClientRecord(const stClient& client) {
        cout << "\n\nThe following are the account details:\n";
        cout << "****************************************";
        cout << "\nAccount Number : " << client.accountNumber;
        cout << "\nPin Code       : " << client.pinCode;
        cout << "\nName           : " << client.name;
        cout << "\nPhone          : " << client.phone;
        cout << "\nAccount Balance: " << client.accountBalance;
        cout << "\n****************************************\n";
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

}