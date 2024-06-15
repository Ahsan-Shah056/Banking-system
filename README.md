# **Banking System Project**

## **Overview**
This project is a simple console-based banking system in C++ that allows users to create accounts, log in, manage their balances, and simulate investments. It uses a text file (`accounts.txt`) to store account details.

## **Features**

- **Account Creation:**
  - Users can create new accounts by providing their name, age (18+), username, and password.
  - Two account types are supported: Savings and Personal.
  - Each account is assigned a unique account number.

- **Login:**
  - Users can log in with their username and password to access their accounts.

- **Account Management:**
  - Users can view their account details including account number, type, and balance.
  - Available transactions include withdrawals, deposits, and transfers.

- **Transactions:**
  - **Withdrawals:** Deduct funds from the account if the balance is sufficient.
  - **Deposits:** Add funds to the account.
  - **Transfers:** Send funds to another user's account by providing the recipient's username.

- **Investment Simulation:**
  - Simulates an investment in one of five major companies (Apple, Google, Microsoft, Amazon, Tesla) and updates the user's balance based on the investment outcome.

## **Key Functions**

- `isAgeValid(int age)`: Checks if the age is 18 or above.
- `generateAccountNumber(bool usedNumbers[])`: Generates a unique account number.
- `login(const string& username, const string& password)`: Validates login credentials.
- `displayAccountDetails(const string& username)`: Shows account details.
- `updateAccount(const string& username, double amount, bool isDeposit)`: Updates the balance based on transactions.
- `simulateInvestment(const string& username)`: Simulates an investment and updates the balance.

## **Usage**

- **Compile and Run:**
  - Compile the code using a C++ compiler (e.g., g++) and run the executable.

- **User Interaction:**
  - Users are prompted to either log into an existing account or create a new one.
  - Post login, users can choose from various transaction options or simulate an investment.
