# **Banking System Project**

## **Overview**
Welcome to the Banking System Project! This simple console-based application, written in C++, allows you to create and manage bank accounts. With features like account creation, login, balance management, and investment simulation, this project is designed to provide a comprehensive banking experience.

## **Features**

### **Account Creation**
- Create a new account by providing your name, age (18+), username, and password.
- Choose between two account types: Savings or Personal.
- Receive a unique account number upon creation.

### **Login**
- Securely log into your account using your username and password.

### **Account Management**
- View your account details, including account number, account type, and current balance.
- Perform various transactions such as withdrawals, deposits, and transfers.

### **Transactions**
- **Withdrawals:** Easily withdraw funds from your account if the balance is sufficient.
- **Deposits:** Conveniently deposit funds into your account.
- **Transfers:** Transfer funds to another user's account by providing the recipient's username.

### **Investment Simulation**
- Simulate investments in one of ten major companies: Apple, Google, Microsoft, Amazon, Tesla, Facebook, Netflix, IBM, Oracle, and Intel.
- Experience different investment outcomes and see how your balance changes.

## **Key Functions**

- **isAgeValid(int age):** Ensures that the user is at least 18 years old.
- **generateAccountNumber(bool usedNumbers[]):** Generates a unique account number.
- **login(const string& username, const string& password):** Validates login credentials.
- **displayAccountDetails(const string& username):** Displays account details.
- **updateAccount(const string& username, double amount, bool isDeposit):** Updates the account balance based on transactions.
- **simulateInvestment(const string& username):** Simulates an investment and updates the balance.

## **Getting Started**

### **Compiling and Running the Code**
1. **Compile the code:** Use a C++ compiler (e.g., g++) to compile the source code.
2. **Run the executable:** Execute the compiled program to start the banking system.

### **User Interaction**
1. **Start the program:** Upon starting, you'll be greeted with a welcome message.
2. **Choose an action:** You can either log into an existing account or create a new one.
3. **Perform transactions:** After logging in, choose from a variety of transaction options or simulate an investment.

### **Example Session**
1. **Welcome to the Banking System**
2. **Do you want to:**
   - 1. Log into an existing account
   - 2. Open a new account
3. **Select transaction type:**
   - 1. Withdraw
   - 2. Deposit
   - 3. Transfer
   - 4. Simulate Investment
   - 0. Exit

Enjoy managing your finances with this simple yet powerful Banking System Project! Stay tuned for updates and new features.
