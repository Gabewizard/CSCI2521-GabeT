/**
 * @file Lab9_gabet.cpp
 * @author Gabriel Toninelli
 * @date 2026-04-23
 * @brief Demonstrates inheritance and polymorphism with a bank account system.
 */

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

const int DEPOSIT = 1;
const int WITHDRAWAL = 2;
const int CLOSE_OF_BUSINESS = 3;
const int QUIT = 4;

/**
 * @brief Represents a bank customer.
 */
class Customer {
private:
    string customerID;
    string email;

public:
    /**
     * @brief Default constructor.
     */
    Customer() {
        customerID = "Unknown";
        email = "none@example.com";
    }

    /**
     * @brief Creates a customer with an ID and email.
     * @param id The customer ID.
     * @param emailAddr The customer email address.
     */
    Customer(const string& id, const string& emailAddr) {
        customerID = id;
        email = emailAddr;
    }

    /**
     * @brief Gets the customer ID.
     * @return The customer ID.
     */
    string getCustomerID() const {
        return customerID;
    }

    /**
     * @brief Gets the customer email.
     * @return The customer email.
     */
    string getEmail() const {
        return email;
    }

    /**
     * @brief Prints customer information.
     * @return Nothing.
     */
    void printCustomerInfo() const {
        cout << "Customer ID: " << customerID << endl;
        cout << "Email: " << email << endl;
    }
};

/**
 * @brief Represents a basic bank account.
 */
class Account {
protected:
    string accountNumber;
    double balance;
    Customer owner;
    vector<double> deposits;
    vector<double> withdrawals;

    /**
     * @brief Prints the close of business summary.
     * @param previousBalance The balance before transactions.
     * @param totalDeposits The total deposits.
     * @param totalWithdrawals The total withdrawals.
     * @param newBalance The final balance.
     * @return Nothing.
     */
    void printSummary(double previousBalance, double totalDeposits, double totalWithdrawals, double newBalance) const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Previous Balance: $" << previousBalance << endl;
        cout << "Total Deposits: $" << totalDeposits << endl;
        cout << "Total Withdrawals: $" << totalWithdrawals << endl;
        cout << "New Balance after COB: $" << newBalance << endl;
    }

public:
    /**
     * @brief Default constructor.
     */
    Account() {
        accountNumber = "0000000000";
        balance = 0.0;
        owner = Customer();
    }

    /**
     * @brief Creates an account.
     * @param accNum The account number.
     * @param initialBalance The starting balance.
     * @param customer The account owner.
     */
    Account(const string& accNum, double initialBalance, const Customer& customer) {
        accountNumber = accNum;
        balance = initialBalance;
        owner = customer;
    }

    /**
     * @brief Virtual destructor.
     */
    virtual ~Account() {
    }

    /**
     * @brief Adds a deposit transaction.
     * @param amount The deposit amount.
     * @return True if valid, false otherwise.
     */
    bool deposit(double amount) {
        if (amount > 0) {
            deposits.push_back(amount);
            return true;
        }

        return false;
    }

    /**
     * @brief Adds a withdrawal transaction.
     * @param amount The withdrawal amount.
     * @return True if valid, false otherwise.
     */
    bool withdraw(double amount) {
        if (amount > 0) {
            withdrawals.push_back(amount);
            return true;
        }

        return false;
    }

    /**
     * @brief Applies transactions at close of business.
     * @return Nothing.
     */
    virtual void closeOfBusiness() {
        double totalDeposits = accumulate(deposits.begin(), deposits.end(), 0.0);
        double totalWithdrawals = accumulate(withdrawals.begin(), withdrawals.end(), 0.0);

        double previousBalance = balance;
        double newBalance = previousBalance + totalDeposits - totalWithdrawals;

        printSummary(previousBalance, totalDeposits, totalWithdrawals, newBalance);

        balance = newBalance;

        deposits.clear();
        withdrawals.clear();
    }

    /**
     * @brief Prints account information.
     * @return Nothing.
     */
    virtual void printAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
        owner.printCustomerInfo();
    }
};

/**
 * @brief Represents a savings account with daily interest.
 */
class SavingsAccount : public Account {
private:
    double dailyInterestRate;

public:
    /**
     * @brief Creates a savings account.
     * @param accNum The account number.
     * @param initialBalance The starting balance.
     * @param customer The account owner.
     * @param interestRate The daily interest rate.
     */
    SavingsAccount(const string& accNum, double initialBalance, const Customer& customer, double interestRate)
        : Account(accNum, initialBalance, customer) {
        dailyInterestRate = interestRate;
    }

    /**
     * @brief Applies transactions and adds daily interest.
     * @return Nothing.
     */
    void closeOfBusiness() override {
        double totalDeposits = accumulate(deposits.begin(), deposits.end(), 0.0);
        double totalWithdrawals = accumulate(withdrawals.begin(), withdrawals.end(), 0.0);

        double previousBalance = balance;
        double newBalance = previousBalance + totalDeposits - totalWithdrawals;

        if (newBalance > 0) {
            newBalance = newBalance + (newBalance * dailyInterestRate);
        }

        printSummary(previousBalance, totalDeposits, totalWithdrawals, newBalance);

        balance = newBalance;

        deposits.clear();
        withdrawals.clear();
    }

    /**
     * @brief Prints savings account information.
     * @return Nothing.
     */
    void printAccountInfo() const override {
        Account::printAccountInfo();
        cout << "Interest Rate: " << dailyInterestRate * 100 << "%" << endl;
    }
};

/**
 * @brief Prints the menu.
 * @return Nothing.
 */
void printMenu() {
    cout << "\nCSCC Bank and Trust" << endl;
    cout << "Select an option:" << endl;
    cout << DEPOSIT << ". Make a deposit" << endl;
    cout << WITHDRAWAL << ". Make a withdrawal" << endl;
    cout << CLOSE_OF_BUSINESS << ". Close of Business" << endl;
    cout << QUIT << ". Quit" << endl;
}

/**
 * @brief Checks if the menu choice is valid.
 * @param choice The menu choice.
 * @return True if valid, false otherwise.
 */
bool isMenuChoiceValid(int choice) {
    return choice >= DEPOSIT && choice <= QUIT;
}

/**
 * @brief Checks if an amount is valid.
 * @param amount The dollar amount.
 * @return True if valid, false otherwise.
 */
bool isAmountValid(double amount) {
    return amount > 0;
}

/**
 * @brief Prints an invalid menu choice message.
 * @return Nothing.
 */
void printInvalidMenuChoiceMessage() {
    cout << "Invalid option selected. Please try again." << endl;
}

/**
 * @brief Prints an invalid amount message.
 * @return Nothing.
 */
void printInvalidAmountMessage() {
    cout << "The dollar amount must be greater than $0.00. Please try again." << endl;
}

/**
 * @brief Gets the user's menu choice.
 * @return The valid menu choice.
 */
int getMenuOption() {
    int choice = 0;

    do {
        printMenu();
        cin >> choice;

        if (!isMenuChoiceValid(choice)) {
            printInvalidMenuChoiceMessage();
        }
    } while (!isMenuChoiceValid(choice));

    return choice;
}

/**
 * @brief Gets a deposit amount.
 * @return The valid deposit amount.
 */
double getDepositAmount() {
    double deposit = 0;

    do {
        cout << "Please enter the deposit amount: $";
        cin >> deposit;

        if (!isAmountValid(deposit)) {
            printInvalidAmountMessage();
        }
    } while (!isAmountValid(deposit));

    return deposit;
}

/**
 * @brief Gets a withdrawal amount.
 * @return The valid withdrawal amount.
 */
double getWithdrawalAmount() {
    double withdrawal = 0;

    do {
        cout << "Please enter the withdrawal amount: $";
        cin >> withdrawal;

        if (!isAmountValid(withdrawal)) {
            printInvalidAmountMessage();
        }
    } while (!isAmountValid(withdrawal));

    return withdrawal;
}

/**
 * @brief Entry point for the banking program.
 * @return 0 to indicate successful execution.
 */
int main() {
    Customer customer("0123456789", "customer@cscc.edu");

    Account* account = new SavingsAccount("5423678409", 100.00, customer, 0.02);

    account->printAccountInfo();

    int menuChoice = getMenuOption();

    while (menuChoice != QUIT) {
        double deposit = 0;
        double withdrawal = 0;

        switch (menuChoice) {
        case DEPOSIT:
            deposit = getDepositAmount();
            account->deposit(deposit);
            break;

        case WITHDRAWAL:
            withdrawal = getWithdrawalAmount();
            account->withdraw(withdrawal);
            break;

        case CLOSE_OF_BUSINESS:
            account->closeOfBusiness();
            break;
        }

        menuChoice = getMenuOption();
    }

    delete account;
    account = nullptr;

    return 0;
}