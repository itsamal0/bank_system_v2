#include <iostream>
#include "../include/bank_system/transactions.h"
#include "../include/bank_system/menu_utils.h"
#include "../include/bank_system/client_utils.h"
using namespace std;

namespace transactions {

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
  }

  void withdraw()
  {
    client_management::printHeader("Withdraw screen");
  }

  void totalBalances()
  {
    cout << "Show balances selected (logic to be implemented)\n";
  }

}