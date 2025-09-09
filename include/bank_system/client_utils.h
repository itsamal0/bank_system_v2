#pragma once
#include <string>

namespace client_management {

    struct stClient {
        string accountNumber;
        string pinCode;
        string name;
        string phone;
        double accountBalance;
    };
}