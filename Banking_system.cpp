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

   const int NUM_COMPANIES = 10;
    const int APPLE = 1;
    const int GOOGLE = 2;
    const int MICROSOFT = 3;
    const int AMAZON = 4;
    const int TESLA = 5;
    const int FACEBOOK = 6;
    const int NETFLIX = 7;
    const int IBM = 8;
    const int ORACLE = 9;
    const int INTEL = 10;

    const string LOW_RISK[] = {"Apple", "Google", "Microsoft", "IBM", "Oracle"};
    const string HIGH_RISK[] = {"Amazon", "Tesla", "Facebook", "Netflix", "Intel"};
    const int LOW_RISK_COUNT = 5;
    const int HIGH_RISK_COUNT = 5;

    cout << "=============================================\n";
    cout << "             Investment Opportunities         \n";
    cout << "=============================================\n";
    cout << "Choose a company to invest in:\n\n";
    cout << "Low Risk Companies:\n";
    cout << " 1. Apple\n";
    cout << " 2. Google\n";
    cout << " 3. Microsoft\n";
    cout << " 8. IBM\n";
    cout << " 9. Oracle\n\n";
    cout << "High Risk Companies:\n";
    cout << " 4. Amazon\n";
    cout << " 5. Tesla\n";
    cout << " 6. Facebook\n";
    cout << " 7. Netflix\n";
    cout << " 10. Intel\n";
    cout << "=============================================\n";
    cout << "Enter the number corresponding to your choice: ";

    int choice;
    cin >> choice;

    srand(time(0));
    double investmentReturnPercent = ((rand() % 21) - 10) / 100.0; // Random percentage between -10% and 10%
    if (choice >= 4 && choice <= 7 || choice == 10) {
        investmentReturnPercent *= 2; // High risk companies have higher volatility
    }

    double investmentAmount;
    string companyName;

    switch(choice) {
        case APPLE:
            companyName = "Apple";
            investmentAmount = balance * 0.1;
            break;
        case GOOGLE:
            companyName = "Google";
            investmentAmount = balance * 0.1;
            break;
        case MICROSOFT:
            companyName = "Microsoft";
            investmentAmount = balance * 0.1;
            break;
        case AMAZON:
            companyName = "Amazon";
            investmentAmount = balance * 0.15;
            break;
        case TESLA:
            companyName = "Tesla";
            investmentAmount = balance * 0.15;
            break;
        case FACEBOOK:
            companyName = "Facebook";
            investmentAmount = balance * 0.15;
            break;
        case NETFLIX:
            companyName = "Netflix";
            investmentAmount = balance * 0.15;
            break;
        case IBM:
            companyName = "IBM";
            investmentAmount = balance * 0.1;
            break;
        case ORACLE:
            companyName = "Oracle";
            investmentAmount = balance * 0.1;
            break;
        case INTEL:
            companyName = "Intel";
            investmentAmount = balance * 0.15;
            break;
        default:
            cout << "Invalid choice. No investment made.\n";
            return;
    }

    double investmentReturn = investmentAmount * investmentReturnPercent;
    double updatedBalance = balance + investmentReturn;

    cout << "\nYou chose to invest in " << companyName << ".\n";
    if (investmentReturn > 0) {
        cout << "Congratulations! Your investment grew by $" << investmentReturn << ".\n";
    } else if (investmentReturn < 0) {
        cout << "Unfortunately, your investment decreased by $" << -investmentReturn << ".\n";
    } else {
        cout << "Your investment neither gained nor lost value.\n";
    }

    cout << "Your updated account balance is: $" << updatedBalance << endl;
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

    cout << "=========================================================\n";
    cout << "                Welcome to the Banking System            \n";
    cout << "=========================================================\n";
    cout << "Do you want to:\n1. Log into an existing account\n2. Open a new account\n";
    cin >> userChoice;

    while (userChoice != 1 && userChoice != 2) {
        cout << "Invalid choice. Please try again.\n";
        cout << "Do you want to:\n1. Log into an existing account\n2. Open a new account\n";
        cin >> userChoice;
    }

    if (userChoice == 2) {
        cout << "=========================================================\n";
        cout << "                   Open a New Account                    \n";
        cout << "=========================================================\n";
        cout << "Select account type:\n1. Savings\n2. Personal\n";
        cin >> accountType;
        while (accountType != 1 && accountType != 2) {
            cout << "Invalid choice. Please try again.\n";
            cout << "Select account type:\n1. Savings\n2. Personal\n";
            cin >> accountType;
        }

        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter your age: ";
        cin >> age;
        while (!isAgeValid(age)) {
            cout << "Invalid age, you must be at least 18 years old.\n";
            cout << "Enter your age: ";
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
        cout << "=========================================================\n";
        cout << "             Log into an Existing Account                \n";
        cout << "=========================================================\n";
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;

        if (login(username, password)) {
            cout << "Login successful.\n";
            displayAccountDetails(username);

            do {
                cout << "=========================================================\n";
                cout << "                   Transaction Menu                      \n";
                cout << "=========================================================\n";
                cout << "Select transaction type:\n";
                cout << "1. Withdraw\n";
                cout << "2. Deposit\n";
                cout << "3. Transfer\n";
                cout << "4. Simulate Investment\n";
                cout << "0. Exit\n";
                cin >> transactionChoice;

                while (transactionChoice < 0 || transactionChoice > 4) {
                    cout << "Invalid choice. Please try again.\n";
                    cout << "Select transaction type:\n";
                    cout << "1. Withdraw\n";
                    cout << "2. Deposit\n";
                    cout << "3. Transfer\n";
                    cout << "4. Simulate Investment\n";
                    cout << "0. Exit\n";
                    cin >> transactionChoice;
                }

                if (transactionChoice == 0) {
                    break;
                } else if (transactionChoice != 4) {  // If not Simulate Investment
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
                }
            } while (transactionChoice != 0);

        } else {
            cout << "Login failed. Invalid username or password.\n";
        }
    }

    return 0;
}




