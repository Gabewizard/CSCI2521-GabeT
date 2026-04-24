/**
 * @file Lab10_gtoninelli.cpp
 * @author Gabriel Toninelli
 * @date 2026-04-23
 * @brief Demonstrates bank account classes, file output, and saving account data.
 */

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <fstream>
#include <iomanip>
using namespace std;

/**
 * @brief Stores basic customer information.
 */
class Customer
{
private:
    string customerID;
    string email;

public:
    /**
     * @brief Default constructor for Customer.
     * @return None.
     */
    Customer();

    /**
     * @brief Parameterized constructor for Customer.
     * @param id The customer ID.
     * @param emailAddr The customer email address.
     * @return None.
     */
    Customer(const string& id, const string& emailAddr);

    /**
     * @brief Gets the customer ID.
     * @return The customer ID.
     */
    string getCustomerID() const;

    /**
     * @brief Gets the customer email.
     * @return The customer email.
     */
    string getEmail() const;

    /**
     * @brief Prints customer information.
     * @return None.
     */
    void printCustomerInfo() const;
};

/**
 * @brief Stores basic account information and transactions.
 */
class Account
{
protected:
    string accountNumber;
    double balance;
    Customer owner;

    vector<double> deposits;
    vector<double> withdrawals;

    /**
     * @brief Prints the account summary after close of business.
     * @param previousBalance The balance before transactions.
     * @param totalDeposits The total deposits.
     * @param totalWithdrawals The total withdrawals.
     * @param newBalance The new balance.
     * @return None.
     */
    void printSummary(double previousBalance, double totalDeposits, double totalWithdrawals, double newBalance) const;

public:
    /**
     * @brief Default constructor for Account.
     * @return None.
     */
    Account();

    /**
     * @brief Parameterized constructor for Account.
     * @param accNum The account number.
     * @param initialBalance The starting balance.
     * @param customer The account owner.
     * @return None.
     */
    Account(const string& accNum, double initialBalance, const Customer& customer);

    /**
     * @brief Virtual destructor for Account.
     * @return None.
     */
    virtual ~Account();

    /**
     * @brief Adds a deposit to the account.
     * @param amount The deposit amount.
     * @return True if the deposit is valid, false otherwise.
     */
    bool deposit(double amount);

    /**
     * @brief Adds a withdrawal to the account.
     * @param amount The withdrawal amount.
     * @return True if the withdrawal is valid, false otherwise.
     */
    bool withdraw(double amount);

    /**
     * @brief Processes deposits and withdrawals.
     * @return None.
     */
    virtual void closeOfBusiness();

    /**
     * @brief Gets the current balance.
     * @return The current balance.
     */
    double getBalance() const;

    /**
     * @brief Gets the account number.
     * @return The account number.
     */
    string getAccountNumber() const;

    /**
     * @brief Gets the account owner.
     * @return The customer object.
     */
    Customer getCustomer() const;

    /**
     * @brief Prints account information.
     * @return None.
     */
    virtual void printAccountInfo() const;

    /**
     * @brief Prints pending deposits and withdrawals.
     * @return None.
     */
    void printTransactions() const;
};

/**
 * @brief Stores savings account information with interest.
 */
class SavingsAccount : public Account
{
protected:
    float interest;

public:
    /**
     * @brief Default constructor for SavingsAccount.
     * @return None.
     */
    SavingsAccount();

    /**
     * @brief Parameterized constructor for SavingsAccount.
     * @param accNum The account number.
     * @param initialBalance The starting balance.
     * @param interest The daily interest rate.
     * @param customer The account owner.
     * @return None.
     */
    SavingsAccount(const string& accNum, double initialBalance, float interest, const Customer& customer);

    /**
     * @brief Processes transactions and applies interest.
     * @return None.
     */
    void closeOfBusiness();

    /**
     * @brief Prints savings account information.
     * @return None.
     */
    void printAccountInfo() const;

    /**
     * @brief Saves savings account information to a file.
     * @return None.
     */
    void Save() const;
};

/**
 * @brief Prints the program menu.
 * @return None.
 */
void printMenu();

/**
 * @brief Gets a valid menu option from the user.
 * @return The selected menu option.
 */
int getMenuOption();

/**
 * @brief Checks whether an amount is valid.
 * @param amount The amount to check.
 * @return True if the amount is greater than zero, false otherwise.
 */
bool isAmountValid(double amount);

/**
 * @brief Checks whether a menu choice is valid.
 * @param choice The menu choice.
 * @return True if the choice is valid, false otherwise.
 */
bool isMenuChoiceValid(int choice);

/**
 * @brief Prints an invalid menu choice message.
 * @return None.
 */
void printInvalidMenuChoiceMessage();

/**
 * @brief Gets a deposit amount from the user.
 * @return The deposit amount.
 */
double getDepositAmount();

/**
 * @brief Gets a withdrawal amount from the user.
 * @return The withdrawal amount.
 */
double getWithdrawalAmount();

/**
 * @brief Prints an invalid amount message.
 * @return None.
 */
void printInvalidAmountMessage();

const int DEPOSIT = 1;
const int WITHDRAWAL = 2;
const int CLOSE_OF_BUSINESS = 3;
const int SAVE = 4;
const int QUIT = 5;

/**
 * @brief Entry point for the banking program.
 * @return 0 to indicate success.
 */
int main()
{
    Customer customer("0123456789", "customer@cscc.edu");
    SavingsAccount* account = new SavingsAccount("5423678409", 100.00, .05, customer);

    account->printAccountInfo();

    int menuChoice = getMenuOption();

    while (menuChoice != QUIT)
    {
        double deposit = 0;
        double withdrawal = 0;

        switch (menuChoice)
        {
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
            account->Save();
            break;

        case SAVE:
            account->Save();
            break;
        }

        menuChoice = getMenuOption();
    }

    delete account;
    account = nullptr;

    return 0;
}

Customer::Customer()
{
    customerID = "Unknown";
    email = "none@example.com";
}

Customer::Customer(const string& id, const string& emailAddr)
{
    customerID = id;
    email = emailAddr;
}

string Customer::getCustomerID() const
{
    return customerID;
}

string Customer::getEmail() const
{
    return email;
}

void Customer::printCustomerInfo() const
{
    cout << "Customer ID: " << customerID << endl;
    cout << "Email: " << email << endl;
}

Account::Account()
{
    accountNumber = "0000000000";
    balance = 0.0;
    owner = Customer();
}

Account::Account(const string& accNum, double initialBalance, const Customer& customer)
{
    accountNumber = accNum;
    balance = initialBalance;
    owner = customer;
}

Account::~Account()
{
}

bool Account::deposit(double amount)
{
    if (amount > 0)
    {
        deposits.push_back(amount);
        return true;
    }

    return false;
}

bool Account::withdraw(double amount)
{
    if (amount > 0)
    {
        withdrawals.push_back(amount);
        return true;
    }

    return false;
}

void Account::closeOfBusiness()
{
    double totalDeposits = accumulate(deposits.begin(), deposits.end(), 0.0);
    double totalWithdrawals = accumulate(withdrawals.begin(), withdrawals.end(), 0.0);

    double previousBalance = balance;
    double newBalance = previousBalance + totalDeposits - totalWithdrawals;

    printSummary(previousBalance, totalDeposits, totalWithdrawals, newBalance);

    balance = newBalance;

    deposits.clear();
    withdrawals.clear();
}

void Account::printSummary(double previousBalance, double totalDeposits, double totalWithdrawals, double newBalance) const
{
    cout << "Account Number: " << accountNumber << endl;
    cout << "Previous Balance: $" << previousBalance << endl;
    cout << "Total Deposits: $" << totalDeposits << endl;
    cout << "Total Withdrawals: $" << totalWithdrawals << endl;
    cout << "New Balance after COB: $" << newBalance << endl;
}

double Account::getBalance() const
{
    return balance;
}

string Account::getAccountNumber() const
{
    return accountNumber;
}

Customer Account::getCustomer() const
{
    return owner;
}

void Account::printAccountInfo() const
{
    cout << "Account Number: " << accountNumber << endl;
    cout << "Current Balance: $" << balance << endl;
    owner.printCustomerInfo();
}

void Account::printTransactions() const
{
    cout << "Deposits: ";

    for (double d : deposits)
    {
        cout << "$" << d << " ";
    }

    cout << endl;

    cout << "Withdrawals: ";

    for (double w : withdrawals)
    {
        cout << "$" << w << " ";
    }

    cout << endl;
}

SavingsAccount::SavingsAccount() : Account()
{
    interest = 1;
}

SavingsAccount::SavingsAccount(const string& accNum, double initialBalance, float interest, const Customer& customer)
    : Account(accNum, initialBalance, customer)
{
    this->interest = interest;
}

void SavingsAccount::closeOfBusiness()
{
    double totalDeposits = accumulate(deposits.begin(), deposits.end(), 0.0);
    double totalWithdrawals = accumulate(withdrawals.begin(), withdrawals.end(), 0.0);

    double previousBalance = balance;
    double interestToApply = previousBalance <= 0 ? 0 : interest;
    double newBalance = (previousBalance + totalDeposits - totalWithdrawals) * (1 + interestToApply);

    printSummary(previousBalance, totalDeposits, totalWithdrawals, newBalance);

    balance = newBalance;

    deposits.clear();
    withdrawals.clear();
}

void SavingsAccount::printAccountInfo() const
{
    cout << "Account Number: " << accountNumber << endl;
    cout << "Current Balance: $" << balance << endl;
    cout << "Interest Rate: " << interest * 100 << "%" << endl;
    owner.printCustomerInfo();
}

void SavingsAccount::Save() const
{
    ofstream outFile("account_summary.txt");

    outFile << fixed << setprecision(2);
    outFile << "Account Number: " << accountNumber << endl << endl;
    outFile << "Current Balance: $" << balance << endl << endl;
    outFile << "Daily Interest Rate: " << interest << endl;

    outFile.close();

    cout << "Account summary saved to account_summary.txt" << endl;
}

void printMenu()
{
    cout << "\nCSCC Bank and Trust" << endl;
    cout << "Select an option:" << endl;
    cout << DEPOSIT << ". Make a deposit" << endl;
    cout << WITHDRAWAL << ". Make a withdrawal" << endl;
    cout << CLOSE_OF_BUSINESS << ". Close of Business" << endl;
    cout << SAVE << ". Save Account Summary" << endl;
    cout << QUIT << ". Quit" << endl;
}

int getMenuOption()
{
    int choice = 0;

    do
    {
        printMenu();
        cin >> choice;

        if (!isMenuChoiceValid(choice))
        {
            printInvalidMenuChoiceMessage();
        }

    } while (!isMenuChoiceValid(choice));

    return choice;
}

bool isMenuChoiceValid(int choice)
{
    return choice >= DEPOSIT && choice <= QUIT;
}

bool isAmountValid(double amount)
{
    return amount > 0;
}

void printInvalidMenuChoiceMessage()
{
    cout << "Invalid option selected. Please try again." << endl;
}

double getDepositAmount()
{
    double deposit = 0;

    do
    {
        cout << "Please enter the deposit amount: $";
        cin >> deposit;

        if (!isAmountValid(deposit))
        {
            printInvalidAmountMessage();
        }

    } while (!isAmountValid(deposit));

    return deposit;
}

double getWithdrawalAmount()
{
    double withdrawal = 0;

    do
    {
        cout << "Please enter the withdrawal amount: $";
        cin >> withdrawal;

        if (!isAmountValid(withdrawal))
        {
            printInvalidAmountMessage();
        }

    } while (!isAmountValid(withdrawal));

    return withdrawal;
}

void printInvalidAmountMessage()
{
    cout << "The dollar amount must be greater than $0.00. Please try again." << endl;
}