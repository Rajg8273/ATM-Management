#include <iostream>
#include <string>
using namespace std;

class atm {
private:
    long int account_No;
    string name;
    int PIN;
    double balance;
    string mobile_No;

public:
    void setData(long int account_No_a, string name_a, int PIN_a, double balance_a, string mobile_No_a) {
        account_No = account_No_a;
        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        mobile_No = mobile_No_a;
    }

    long int getAccountNo() {
        return account_No;
    }

    string getName() {
        return name;
    }

    int getPIN() {
        return PIN;
    }

    double getBalance() {
        return balance;
    }

    string getMobileNo() {
        return mobile_No;
    }

    void setMobile(string mob_prev, string mob_new) {
        if (mob_prev == mobile_No) {
            mobile_No = mob_new;
            cout << "Successfully Updated Mobile No." << endl;
            cin.ignore();
        } else {
            cout << "Incorrect! Old Mobile No." << endl;
            cin.ignore();
        }
    }

    void cashWithDraw(int amount_a) {
        if (amount_a > 0 && amount_a <= balance) {
            balance -= amount_a;
            cout << "Please Collect Your Cash" << endl;
            cout << "Available Balance: " << balance << endl;
            cin.ignore();
        } else {
            cout << "Invalid Input or Insufficient Balance" << endl;
            cin.ignore();
        }
    }
};

int main() {
    int choice = 0, enterPIN;
    long int enterAccountNo;

    atm user1;
    user1.setData(987654321, "Hardik", 1234, 50000, "9370054900");

    do {
        cout << "**** Welcome to ATM ****" << endl;
        cout << "Enter Your Account No: ";
        cin >> enterAccountNo;

        cout << "Enter PIN: ";
        cin >> enterPIN;

        if ((enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN())) {
            do {
                int amount = 0;
                string oldMobileNo, newMobileNo;

                cout << "\n**** Welcome to ATM ****" << endl;
                cout << "Select Options: " << endl;
                cout << "1. Check Balance" << endl;
                cout << "2. Cash Withdraw" << endl;
                cout << "3. Show User Details" << endl;
                cout << "4. Update Mobile No." << endl;
                cout << "5. Exit" << endl;
                cin >> choice;

                switch (choice) {
                case 1:
                    cout << "Your Bank Balance is: " << user1.getBalance() << endl;
                    cin.ignore();
                    break;

                case 2:
                    cout << "Enter the amount: ";
                    cin >> amount;
                    user1.cashWithDraw(amount);
                    break;

                case 3:
                    cout << "*** User Details are: ***" << endl;
                    cout << "-> Account No: " << user1.getAccountNo() << endl;
                    cout << "-> Name: " << user1.getName() << endl;
                    cout << "-> Balance: " << user1.getBalance() << endl;
                    cout << "-> Mobile No: " << user1.getMobileNo() << endl;
                    cin.ignore();
                    break;

                case 4:
                    cout << "Enter Old Mobile No: ";
                    cin >> oldMobileNo;
                    cout << "Enter New Mobile No: ";
                    cin >> newMobileNo;
                    user1.setMobile(oldMobileNo, newMobileNo);
                    break;

                case 5:
                    cout << "Thank you for using the ATM. Goodbye!" << endl;
                    exit(0);

                default:
                    cout << "Invalid Option! Please try again." << endl;
                }
            } while (1);
        } else {
            cout << "Invalid Account No or PIN! Please try again." << endl;
            cin.ignore();
        }
    } while (1);

    return 0;
}
