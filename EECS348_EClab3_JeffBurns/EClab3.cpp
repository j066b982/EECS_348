/*
EC lab 3, bank program
Jeff Burns
references: w3schools.com, geeksforgeeks.com
last edited:11-26-2023

*/
#include <iostream>
using namespace std;

class Account {
    protected:
        string accountNumber;
        string accountHolder;
        float interestRate;
    public:
        Account(string accountNumber, string accountHolder) {
            this->accountNumber = accountNumber;
            this->accountHolder = accountHolder;
        }
        virtual void deposit(float amount) = 0;
        virtual void withdraw(float amount) = 0;
        virtual void display() = 0;
        
};

class SavingsAccount : public Account {
    private:
        float balance;
    public:
        SavingsAccount(string accountNumber, string accountHolder, float balance, float interestRate) : Account(accountNumber, accountHolder) {
            this->balance = balance;
            this->interestRate = interestRate;
        }
        void deposit(float amount) {
            balance += amount;
        }
        void withdraw(float amount) {
            if (balance < amount) {
                cout << "Insufficient Funds" << endl;
            } else {
                balance -= amount;
                
            }
        }
       
        void display() {
            cout << "Account deteials for Saving Account (ID " << accountNumber <<")" << endl; 
            
            cout << "Account Holder: " << accountHolder << endl;
            
            cout << "Balance: $" << balance << endl;
            cout << "Interest Rate " << interestRate << endl;
        }
};

class CurrentAccount : public Account {
    private:
        float balance;
    public:
        CurrentAccount(string accountNumber, string accountHolder, float balance) : Account(accountNumber, accountHolder) {
            this->balance = balance;
        }
        void deposit(float amount) {
            balance += amount;
        }
        void withdraw(float amount) {
            if (balance - amount < -500) {
                cout << "Insufficient Funds" << endl;
            } else {
                balance -= amount;
            }
        }
        void display() {
            cout << "Account Details for Current Account (ID " << accountNumber <<")" << endl;
            
            cout << "Account Holder: " << accountHolder << endl;
            
            cout << "Balance: $" << balance << endl;
            cout << "Over Draft Limit: $500" << endl;
        }
};

int main() {
    Account* accounts[2];
    accounts[0] = new SavingsAccount("s123", "John Doe", 5000, 0.02);
    accounts[1] = new CurrentAccount("c456", "Jane Doe", 10000);
    cout<<endl;
    
    accounts[0]->display();
    cout<<endl;
    accounts[1]->display();
    cout<<endl;
    accounts[0]->deposit(1000);
    accounts[0]->display();
    cout<<endl;
    accounts[0]->withdraw(2000);
    accounts[0]->display();
    cout<<endl;
    accounts[1]->deposit(5000);
    accounts[1]->display();
    cout<<endl;
    accounts[1]->withdraw(15000);
    accounts[1]->display();

    return 0;
}
