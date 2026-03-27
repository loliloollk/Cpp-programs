#include <iostream>
#include <limits>
#include <ostream>
#include <string>

class BankAccount {
private:
  std::string name;
  double balance;

public:
  BankAccount(std::string name, double balance) {
    this->name = name;
    this->balance = balance;
  }
  void withdraw(double amount) {
    if (0 < amount && amount <= balance) {
      balance -= amount;
      std::cout << "You have withdrawn from your balance: " << amount
                << std::endl;
      std::cout << "Your balance is: " << balance << std::endl;
    } else if (balance < amount) {
      std::cout << "There are not enough money in the balance." << std::endl;
    } else if (amount < 0) {
      std::cout << "Invalid value. The value must be greater than 0."
                << std::endl;
    }
  }

  void deposit(double amount) {
    if (amount > 0) {
      balance += amount;
      std::cout << "You have topped up your balance by: " << amount
                << std::endl;
      std::cout << "Your balance is: " << balance << std::endl;
    } else {
      std::cout << "Invalid value. The value must be greater than 0"
                << std::endl;
    }
  }
  void displayStatus() {
    std::cout << "Owner's name: " << name << std::endl;
    std::cout << "Currently balance: " << balance << std::endl;
  }
};

void Menu() {
  std::cout << "1. Create an account \n2. log in to an account \n3. Exit"
            << std::endl;
}

void AccountMenu() {
  std::cout << "1. Show the account info \n2. Deposit money \n3. Withdraw "
               "money \n4. Back"
            << std::endl;
}

int main() {
  std::cout << "Welcome to the \"World's most mega cool bank\"" << std::endl;
  std::string name;
  std::string login;
  std::string password;
  std::string userLogin;
  std::string userPassword;
  double balance = 0;
  short choice;
  bool success = false;
  BankAccount *account = nullptr;
  do {
    std::cout << "To select it, enter the corresponding number: " << std::endl;
    Menu();
    std::cin >> choice;
    if (std::cin.fail()) { // Cin check
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid value." << std::endl;
      std::cout << "\n";
      continue;
    }
    std::cout << "\n";
    switch (choice) {
    case 1:
      // Checking for an account
      if (account != nullptr) {
        std::cout << "Account already exists! You cannot create another one."
                  << std::endl;
        break; // Back to main menu
      }
      // Creating an account
      while (success == false) {
        std::cout << "Create the login and password." << std::endl;
        std::cout << "Login: ";
        std::cin >> login;
        std::cout << "Password: ";
        std::cin >> password;
        std::cout << "Enter your name and the initial balance amount"
                  << std::endl;
        std::cout << "Owner's name: ";
        std::cin >> name;
        std::cout << "Initial balance: ";
        std::cin >> balance;
        if (std::cin.fail()) {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "The balance can only contain numbers." << std::endl;
          std::cout << "\n";
          continue;
        }
        std::cout << "\n";
        // checking balance value
        if (balance <= 0) {
          std::cout << "Invalid value. The balance must be greater than 0."
                    << std::endl;
          continue;
        } else {
          account = new BankAccount(name, balance);
          success = true;
        }
      }
      break;

    case 2:
      // Checking for an account
      if (account == nullptr) {
        std::cout << "Error: Create an account first!" << std::endl;
        break;
      }
      // logining to an account
      success = false;
      while (success == false) {
        std::cout << "Login: ";
        std::cin >> userLogin;
        std::cout << "Password: ";
        std::cin >> userPassword;
        if (userLogin == login && userPassword == password) {
          bool inAccount = true;
          std::cout << "Success." << std::endl;
          while (inAccount == true) {
            AccountMenu();
            short accChoice;
            std::cin >> accChoice;
            if (std::cin.fail()) {
              std::cin.clear();
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                              '\n');
              std::cout << "Invalid value." << std::endl;
              std::cout << "\n";
              continue;
            }
            double amount;
            std::cout << "\n";
            switch (accChoice) {
            case 1:
              account->displayStatus();
              break;
            case 2:
              std::cout << "Amount: ";
              amount = 0;
              std::cin >> amount;
              if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                '\n');
                std::cout << "The amount can only contain numbers."
                          << std::endl;
                std::cout << "\n";
                continue;
              }
              account->deposit(amount);
              break;
            case 3:
              std::cout << "Amount: ";
              amount = 0;
              std::cin >> amount;
              if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                '\n');
                std::cout << "The amount can only contain numbers."
                          << std::endl;
                std::cout << "\n";
                continue;
              }
              account->withdraw(amount);
              break;
            case 4:
              inAccount = false;
              break;
            }
          }
          success = true;
        } else {
          // Retry
          std::cout << "Invalid login or password." << std::endl;
          std::cout << "\n";
          continue;
        }
      }
      break;

    case 3:
      // Exit
      delete account;
      return 0;

    default:
      // Retry
      std::cout << "Invalid value." << std::endl;
      std::cout << "\n";
      continue;
    }
  } while (true);
  return 0;
}
