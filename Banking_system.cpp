#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const char* FILENAME = "accounts.txt";  // Common file for account details
bool isAgeValid(int age) { return age >= 18; }

int generateAccountNumber(bool usedNumbers[]) {
    for (int i = 0; i < 10; ++i) {
        if (!usedNumbers[i]) {
            usedNumbers[i] = true;
            return i + 1;
        }
    }
    return -1;
}

bool login(const string& username, const string& password) {
    ifstream file(FILENAME);
    string line, storedUsername, storedPassword, unused;
    while (getline(file, line)) {
        stringstream ss(line);
        ss >> unused >> storedUsername >> storedPassword >> unused >> unused;
        if (storedUsername == username && storedPassword == password) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}



void displayAccountDetails(const string& username) {
    ifstream file(FILENAME);
    string line, storedUsername, accountNumber, accountType, dummy;
    double balance;
    bool found = false;

    while (getline(file, line)) {
        stringstream ss(line);
        ss >> accountNumber >> storedUsername >> dummy >> accountType >> balance;
        if (storedUsername == username) {
            cout << "Account Number: " << accountNumber << endl;
            cout << "Username: " << storedUsername << endl;
            cout << "Account Type: " << accountType << endl;
            cout << "Current Balance: $" << balance << endl;
            found = true;
            break;
        }
    }

    if (!found) cout << "Account not found." << endl;
    file.close();
}



void updateAccount(const string& username, double amount, bool isDeposit) {
    ifstream inFile(FILENAME);
    ofstream outFile("temp.txt");
    string line;
    bool found = false;

    while (getline(inFile, line)) {
        stringstream ss(line);
        string storedAccountNumber, storedUsername, password, accountType;
        double balance;
        ss >> storedAccountNumber >> storedUsername >> password >> accountType >> balance;

        if (storedUsername == username) {
            if (isDeposit) {
                balance += amount;
            } else {
                if (balance >= amount) {
                    balance -= amount;
                } else {
                    cout << "Insufficient funds for withdrawal." << endl;
                    outFile << line << endl;  // Write back unchanged line
                    continue;
                }
            }
            outFile << storedAccountNumber << " " << storedUsername << " " << password << " " << accountType << " " << balance << endl;
            found = true;
        } else {
            outFile << line << endl;
        }
    }

    if (!found) {
        cout << "Account not found." << endl;
    } else {
        cout << "Transaction successful. Updated details are saved." << endl;
    }

    inFile.close();
    outFile.close();
    remove(FILENAME);
    rename("temp.txt", FILENAME);
}



void simulateInvestment(const string& username) {
    ifstream inFile(FILENAME);
    string line;
    double balance = 0.0;

    while (getline(inFile, line)) {
        stringstream ss(line);
        string storedAccountNumber, storedUsername, password, accountType;
        ss >> storedAccountNumber >> storedUsername >> password >> accountType >> balance;

        if (storedUsername == username) {
            break;
        }
    
    }
    inFile.close();

    const int APPLE = 1;
    const int GOOGLE = 2;
    const int MICROSOFT = 3;
    const int AMAZON = 4;
    const int TESLA = 5;

    srand(time(0)); 
    int random = rand() % 5 + 1; 

    double appleInvestment = balance * 0.1;
    double googleInvestment = balance * 0.2;
    double microsoftInvestment = balance * 0.3;
    double amazonInvestment = balance * 0.15;
    double teslaInvestment = balance * 0.05;

    double updatedBalance = balance;
    switch(random) {
        case APPLE:
            updatedBalance += appleInvestment;
            break;
        case GOOGLE:
            updatedBalance += googleInvestment;
            break;
        case MICROSOFT:
            updatedBalance += microsoftInvestment;
            break;
        case AMAZON:
            updatedBalance += amazonInvestment;
            break;
        case TESLA:
            updatedBalance += teslaInvestment;
            break;
    }

    cout << "Your updated account balance after investment would be: $" << updatedBalance << endl;
}



int main() {
    string name, username, password;
    int age, accountType, userChoice, transactionChoice;
    double amount;
    bool usedNumbers[10] = {false};

    // Load existing account numbers to ensure uniqueness
    ifstream inFile(FILENAME);
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string storedAccountNumber;
        ss >> storedAccountNumber;
        int num = stoi(storedAccountNumber);
        if (num >= 1 && num <= 10) usedNumbers[num - 1] = true;
    }
    inFile.close();

    cout << "Do you want to log into an existing account (1) or open a new account (2)?\n";
    cin >> userChoice;

    while (userChoice != 1 && userChoice != 2) {
        cout << "Invalid choice, please select 1 to log into an existing account or 2 to open a new one.\n";
        cin >> userChoice;
    }

    if (userChoice == 2) {
        // Open a new account
        cout << "Select account type:\n1. Savings\n2. Personal\n";
        cin >> accountType;
        while (accountType != 1 && accountType != 2) {
            cout << "Invalid choice, please select 1 for Savings or 2 for Personal.\n";
            cin >> accountType;
        }

        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter your age: ";
        cin >> age;
        while (!isAgeValid(age)) {
            cout << "Invalid age, you must be at least 18 years old.\n";
            cin >> age;
        }

        int accountNumber = generateAccountNumber(usedNumbers);
        cout << "Choose a username: ";
        cin >> username;

        cout << "Enter a password: ";
        cin >> password;

        ofstream outFile(FILENAME, ios::app);
        outFile << accountNumber << " " << username << " " << password << " " << (accountType == 1 ? "Savings" : "Personal") << " " << 0.0 << endl;
        outFile.close();

        cout << "Account created successfully! Your account number is " << accountNumber << ".\n";
    } else {
        // Log into an existing account
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;

        if (login(username, password)) {
            cout << "Login successful.\n";
            displayAccountDetails(username);

           do{ cout << "Select transaction type:\n1. Withdraw\n2. Deposit\n3. Transfer\n4. Simulate Investment.\n0. To Exit\n";
    cin >> transactionChoice;
    
    while (transactionChoice > 4) {
        cout << "Invalid choice, please select 1 for Withdraw, 2 for Deposit, 3 for Transfer, or 4 to Simulate Investment.\n";
        cin >> transactionChoice;
    }
    if (transactionChoice ==0){
        break;
    }
    else if (transactionChoice != 4) {  // If not Simulate Investment
        cout << "Enter the amount: ";
        cin >> amount;
    }

    if (transactionChoice == 3) {  // Transfer
        string recipientUsername;
        cout << "Enter recipient's username: ";
        cin >> recipientUsername;
        // First pass: Deduct amount from sender's account
        updateAccount(username, amount, false);
        // Second pass: Add amount to recipient's account
        updateAccount(recipientUsername, amount, true);
    } else if (transactionChoice == 4) {  
        simulateInvestment(username);
    } else {
        updateAccount(username, amount, transactionChoice == 2);
    }}while (transactionChoice !=0);

        } else {
            cout << "Login failed. Invalid username or password.\n";
        }
    }

    return 0;
}



