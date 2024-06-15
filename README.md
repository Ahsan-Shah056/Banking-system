<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Banking System Project</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 20px;
        }
        h1, h2 {
            color: #333;
        }
        p {
            line-height: 1.6;
            color: #666;
        }
        ul {
            list-style-type: disc;
            margin-left: 20px;
        }
        .code {
            background-color: #f4f4f4;
            padding: 10px;
            border-radius: 4px;
            overflow-x: auto;
            margin-bottom: 20px;
        }
        .code pre {
            margin: 0;
        }
    </style>
</head>
<body>
    <h1><strong>Banking System Project</strong></h1>

    <h2><strong>Overview</strong></h2>
    <p>
        This project is a simple console-based banking system in C++ that allows users to create accounts, log in, manage their balances, and simulate investments. It uses a text file (<code>accounts.txt</code>) to store account details.
    </p>

    <h2><strong>Features</strong></h2>
    <ul>
        <li>
            <strong>Account Creation:</strong>
            <ul>
                <li>Users can create new accounts by providing their name, age (18+), username, and password.</li>
                <li>Two account types are supported: Savings and Personal.</li>
                <li>Each account is assigned a unique account number.</li>
            </ul>
        </li>
        <li>
            <strong>Login:</strong>
            <ul>
                <li>Users can log in with their username and password to access their accounts.</li>
            </ul>
        </li>
        <li>
            <strong>Account Management:</strong>
            <ul>
                <li>Users can view their account details including account number, type, and balance.</li>
                <li>Available transactions include withdrawals, deposits, and transfers.</li>
            </ul>
        </li>
        <li>
            <strong>Transactions:</strong>
            <ul>
                <li><strong>Withdrawals:</strong> Deduct funds from the account if the balance is sufficient.</li>
                <li><strong>Deposits:</strong> Add funds to the account.</li>
                <li><strong>Transfers:</strong> Send funds to another user's account by providing the recipient's username.</li>
            </ul>
        </li>
        <li>
            <strong>Investment Simulation:</strong>
            <ul>
                <li>Simulates an investment in one of five major companies (Apple, Google, Microsoft, Amazon, Tesla) and updates the user's balance based on the investment outcome.</li>
            </ul>
        </li>
    </ul>

    <h2><strong>Key Functions</strong></h2>
    <div class="code">
        <pre><code>isAgeValid(int age): Checks if the age is 18 or above.
generateAccountNumber(bool usedNumbers[]): Generates a unique account number.
login(const string& username, const string& password): Validates login credentials.
displayAccountDetails(const string& username): Shows account details.
updateAccount(const string& username, double amount, bool isDeposit): Updates the balance based on transactions.
simulateInvestment(const string& username): Simulates an investment and updates the balance.
        </code></pre>
    </div>

    <h2><strong>Usage</strong></h2>
    <ul>
        <li>
            <strong>Compile and Run:</strong>
            <ul>
                <li>Compile the code using a C++ compiler (e.g., g++) and run the executable.</li>
            </ul>
        </li>
        <li>
            <strong>User Interaction:</strong>
            <ul>
                <li>Users are prompted to either log into an existing account or create a new one.</li>
                <li>Post login, users can choose from various transaction options or simulate an investment.</li>
            </ul>
        </li>
    </ul>
</body>
</html>
