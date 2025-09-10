#pragma once
#include <string>
#include <vector>

namespace client_management {

    struct stClient {
        std::string accountNumber;
        std::string pinCode;
        std::string name;
        std::string phone;
        double accountBalance;
        bool markForDelete = false;
    };
    
    void printHeader(std::string headerText);
    std::string convertRecordToLine(stClient client, std::string separator = "#//#");
    stClient readNewClient();
    void addDataLineToFile(const std::string& fileName, const std::string& stDataLine);
    stClient convertLineToRecord(std::string str, std::string separator = "#//#");
    std::vector<stClient> loadClientsDataFromFile(std::string fileName);
    bool findClientByAccountNumber(const std::string& accountNumber, const std::vector<stClient>& vClients, stClient& client);
    void displayClientRecord(const stClient& client);

}