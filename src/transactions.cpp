#include <iostream>
#include <limits>
#include "../include/bank_system/transactions.h"
#include "../include/bank_system/menu_utils.h"
#include "../include/bank_system/client_utils.h"
#include "../include/bank_system/client_management.h"
#include "../../../helpers/io_utils.h"
#include <string>
using namespace std;

namespace transactions
{

    enum enTransactionsMenuOptions
    {
        DEPOSIT = 1,
        WITHDRAW = 2,
        TOTAL_BALANCES = 3,
        MAIN_MENU = 4,
    };

    vector<string> vTransactionsMenuOptions = {
        "Deposit",
        "Withdraw",
        "Total balances",
        "Main menu",
    };

    string chooseClient()
    {
        client_management::stClient client;
        string accountNumber = "";

        do
        {
            accountNumber = client_management::findClient(false);

        } while (accountNumber == "");

        return accountNumber;
    }

    double readTransactionAmount(const string &actionType)
    {
        return io_utils::readPositiveNumber("\n\nPlease enter " + actionType + " amount? ");
    }

    bool confirmTransaction()
    {
        char answer;
        cout << "\n\nAre you sure you want to perform this transaction? [y/n]: ";
        cin >> answer;
        return toupper(answer) == 'Y';
    }

    // Update only the balance of a client by account number
    void updateClientBalance(string accountNumber, string actionType, double amount)
    {
        vector<client_management::stClient> vClients = client_management::loadClientsDataFromFile(client_management::clientsFileName);
        cin.ignore(1000, '\n');

        // Update only the balance in the vector
        for (client_management::stClient &c : vClients)
        {
            if (c.accountNumber == accountNumber)
            {
                actionType == "deposit" ? c.accountBalance += amount : c.accountBalance -= amount;
                break;
            }
        }

        // Save updated clients to file
        saveClientsDataToFile(client_management::clientsFileName, vClients);
        cout << "\n\nBalance updated successfully.\n";
        return;
    }

    void processTransaction(const string &actionType)
    {
        string accountNumber = chooseClient();
        double amount = readTransactionAmount(actionType);

        if (confirmTransaction())
            updateClientBalance(accountNumber, actionType, amount);
    }

    void showTransactionMenu()
    {
        int choice = 0;
        do
        {
            system("cls");

            menu_utils::showMenu("Transactions Menu", vTransactionsMenuOptions);
            choice = menu_utils::readMenuChoice(1, vTransactionsMenuOptions.size());

            handleTransactionChoice(choice);

            if (choice != MAIN_MENU)
            {
                cout << "\nPress any key to go back to transactions menu...";
                system("pause >nul");
            }

        } while (choice != MAIN_MENU);
    }

    void handleTransactionChoice(int choice)
    {

        system("cls");

        switch (choice)
        {
        case DEPOSIT:
            deposit();
            break;
        case WITHDRAW:
            withdraw();
            break;
        case TOTAL_BALANCES:
            totalBalances();
            break;
        case MAIN_MENU:
            break;
        }
    }

    void deposit()
    {
        client_management::printHeader("Deposit screen");
        processTransaction("deposit");
    }

    void withdraw()
    {
        client_management::printHeader("Withdraw screen");
        processTransaction("withdraw");
    }
    void totalBalances()
    {
        cout << "Show balances selected (logic to be implemented)\n";
    }

}