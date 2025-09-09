#pragma once
#include <string>

namespace client_management {

    struct stClient {
        std::string accountNumber;
        std::string pinCode;
        std::string name;
        std::string phone;
        double accountBalance;
    };
    
    void printHeader(std::string headerText);
    std::string convertRecordToLine(stClient client, std::string separator = "#//#");
    stClient readNewClient();
    void addDataLineToFile(const std::string& fileName, const std::string& stDataLine);

}