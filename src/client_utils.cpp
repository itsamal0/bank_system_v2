#include <iostream>
#include <fstream>
#include <limits>
#include "../include/bank_system/client_utils.h"
#include "../../../helpers/io_utils.h"
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
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        newClient.accountNumber   = io_utils::readString("\nEnter account number: ");
        newClient.pinCode         = io_utils::readString("\nEnter pin code: ");
        newClient.name            = io_utils::readString("\nEnter name: ");
        newClient.phone           = io_utils::readString("\nEnter phone number: ");
        newClient.accountBalance  = io_utils::readPositiveNumber("\nEnter account balance: ");
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
   
}