#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100 // Maximum number of accounts
#define MAX_TRANSACTIONS 100 // Maximum number of transactions per account


/* 
* Structure for a transaction
*/
struct Transaction {
    int amount;
    char transactionType[20]; // Type of transaction (e.g., deposit, withdrawal)
};

/* 
* Structure for an account
*/
struct Account {
    unsigned long long int accountNumber;
    char firstName[50];
    char lastName[50];
    int balance;
    struct Transaction history[MAX_TRANSACTIONS]; // Transaction history for the account
    int transactionCount; // Number of transactions for the account
};

struct Account accounts[MAX_ACCOUNTS]; // Array of accounts
int numAccounts = 0; // Number of accounts created so far

unsigned long long int nextAccountNumber = 9000876544ULL; // Next available account number

/* 
* Function to create a new account
* Input: None
* Return: None
*/
void createAccount() {
    struct Account newAccount;

    printf("Enter your first name: ");
    scanf("%s", newAccount.firstName);
    printf("Enter your last name: ");
    scanf("%s", newAccount.lastName);

    newAccount.accountNumber = nextAccountNumber++; // Assign account number
    printf("Your account number is %llu\n", newAccount.accountNumber);

    newAccount.balance = 0; // Initialize balance to 0
    newAccount.transactionCount = 0; // Initialize transaction count to 0

    accounts[numAccounts++] = newAccount; // Add the new account to the array
}

/* 
* Function to find an account by its account number
* Input: accountNumber - The account number to search for
* Return: The index of the found account, or -1 if not found
*/
int findAccountByNumber(unsigned long long int accountNumber) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            return i; // Return the index of the found account
        }
    }
    return -1; // Return -1 if no account with the given account number is found
}

/* 
* Function to deposit money into an account
* Input: accountIndex - The index of the account to deposit money into
* Return: None
*/
void deposit(int accountIndex) {
    int amount;
    printf("Enter amount to deposit: ");
    scanf("%d", &amount);

    accounts[accountIndex].balance += amount; // Update account balance
    strcpy(accounts[accountIndex].history[accounts[accountIndex].transactionCount].transactionType, "deposit");
    accounts[accountIndex].history[accounts[accountIndex].transactionCount].amount = amount;
    accounts[accountIndex].transactionCount++;

    printf("Transaction completed successfully.\n");
    printf("Your bank balance is %d\n", accounts[accountIndex].balance);
}

/* 
* Function to withdraw money from an account
* Input: accountIndex - The index of the account to withdraw money from
* Return: None
*/
void withdraw(int accountIndex) {
    int amount;
    printf("Enter amount to withdraw: ");
    scanf("%d", &amount);

    if (amount <= accounts[accountIndex].balance) {
        accounts[accountIndex].balance -= amount; // Update account balance
        strcpy(accounts[accountIndex].history[accounts[accountIndex].transactionCount].transactionType, "withdrawal");
        accounts[accountIndex].history[accounts[accountIndex].transactionCount].amount = amount;
        accounts[accountIndex].transactionCount++;

        printf("Transaction completed successfully.\n");
        printf("Your bank balance is %d\n", accounts[accountIndex].balance);
    } else {
        printf("Insufficient funds.\n");
    }
}

/* 
* Function to check the balance of an account
* Input: accountIndex - The index of the account to check the balance of
* Return: None
*/
void checkBalance(int accountIndex) {
    printf("Your bank balance is %d\n", accounts[accountIndex].balance);
}

/* 
* Function to display the transaction history of an account
* Input: accountIndex - The index of the account to display the transaction history of
* Return: None
*/
void displayTransactionHistory(int accountIndex) {
    printf("Transaction History:\n");
    for (int i = 0; i < accounts[accountIndex].transactionCount; ++i) {
        printf("Transaction %d: Type: %s, Amount: %d\n", i + 1, accounts[accountIndex].history[i].transactionType, accounts[accountIndex].history[i].amount);
    }
}

/* 
* Main function
*/
int main() {
    int choice;

    while (1) {
        printf("Welcome to JLSS BANK\n");
        printf("Choose an option:\n");
        printf("1. Create New account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check balance\n");
        printf("5. Transaction history\n");
        printf("0. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numAccounts < MAX_ACCOUNTS) {
                    createAccount();
                } else {
                    printf("Maximum number of accounts reached.\n");
                }
                break;
            case 2:
                if (numAccounts > 0) {
                    unsigned long long int accountNumber;
                    printf("Enter account number: ");
                    scanf("%llu", &accountNumber);
					printf("%llu", accountNumber);

                    int accountIndex = findAccountByNumber(accountNumber);
                    if (accountIndex != -1) {
                        deposit(accountIndex);
                    } else {
                        printf("Account not found.\n");
                    }
                } else {
                    printf("No accounts available.\n");
                }
                break;
            case 3:
                if (numAccounts > 0) {
                    unsigned long long int accountNumber;
                    printf("Enter account number: ");
                    scanf("%llu", &accountNumber);

                    int accountIndex = findAccountByNumber(accountNumber);
                    if (accountIndex != -1) {
                        withdraw(accountIndex);
                    } else {
                        printf("Account not found.\n");
                    }
                } else {
                    printf("No accounts available.\n");
                }
                break;
            case 4:
                if (numAccounts > 0) {
                    unsigned long long int accountNumber;
                    printf("Enter account number: ");
                    scanf("%llu", &accountNumber);

                    int accountIndex = findAccountByNumber(accountNumber);
                    if (accountIndex != -1) {
                        checkBalance(accountIndex);
                    } else {
                        printf("Account not found.\n");
                    }
                } else {
                    printf("No accounts available.\n");
                }
                break;
            case 5:
                if (numAccounts > 0) {
                    unsigned long long int accountNumber;
                    printf("Enter account number: ");
                    scanf("%llu", &accountNumber);

                    int accountIndex = findAccountByNumber(accountNumber);
                    if (accountIndex != -1) {
                        displayTransactionHistory(accountIndex);
                    } else {
                        printf("Account not found.\n");
                    }
                } else {
                    printf("No accounts available.\n");
                }
                break;
            case 0:
                exit(0);
            default:
                printf("Error! Please choose a valid option.\n");
        }

        printf("\n");
    }
    return 0;
}
