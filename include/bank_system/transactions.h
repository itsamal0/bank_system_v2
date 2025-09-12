#pragma once
#include <string>

namespace transactions {
    void showTransactionMenu();
    void handleTransactionChoice(int choice);
    void deposit();
    void withdraw();
    void totalBalances();
}