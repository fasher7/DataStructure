// it can be made better but for learning basic purpose it is better to look at this

#include <iostream>
using namespace std;

struct customer
{
    string name;
    string aNumber;
    float balance;
    void hisBalance()
    {
        cout << "New Balance: " << balance;
    }
};

int main()
{
    float withdraw;
    float deposit;
    string choose;

    customer user;
    customer *works = new customer[3];

    for (int i = 0; i < 3; ++i)
    {
        cout << "Your name? ";
        cin >> works[i].name;
        cout << "Your account number? ";
        cin >> works[i].aNumber;
        cout << "Current Balance: ";
        cin >> works[i].balance;
        user.balance = works[i].balance;
        cout << endl;
        cout << "Do you want to withdraw/deposit? " << endl;
        cin >> choose;
        if (choose == "withdraw")
        {
            cout << "How much? ";
            cin >> withdraw;
            works[i].balance = user.balance - withdraw;
            user.balance = works[i].balance;
            user.hisBalance();
            cout << endl;
        }
        else if (choose == "deposit")
        {
            cout << "How much? ";
            cin >> deposit;
            works[i].balance = user.balance + deposit;
            user.balance = works[i].balance;
            user.hisBalance();
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
