#include <iostream>
using namespace std;
class Account
{
protected:
    double balance;

public:
    Account(double balance) : balance(balance) {}
    void deposit(double money)
    {
        balance += money;
        cout << money << " deposited in the account" << endl;
    }
    void withdraw(double money)
    {
        balance -= money;
        cout << money << " withdrawn from account" << endl;
    }
    void checkBalance()
    {
        cout << "Your current Account Balance is " << balance << endl;
    }
};
class InterestAccount : virtual public Account
{
protected:
    double interest;
    const float interestRate = 30;

public:
    InterestAccount(double balance) : Account(balance) {}
    void deposit(double money)
    {
        interest = money * (interestRate / 100);
        balance += money + interest;
        cout << money + interest << " deposited in the account" << endl;
    }
};
class ChargingAccount : virtual public Account
{
protected:
    const float fee = 25;

public:
    ChargingAccount(double money) : Account(money) {}
    void withdraw(double money)
    {
        balance -= (money + fee);
        cout << money + fee << " withdrawn from account" << endl;
    }
};
class ACI : public InterestAccount, public ChargingAccount
{
public:
    ACI(double money) : InterestAccount(money), ChargingAccount(money), Account(money) {}
    void transfer(double money, Account &account)
    {
        deposit(money);
        balance -= money;
    }
    void transfer(double money, InterestAccount &interestAccount)
    {
        interestAccount.deposit(money);
        balance -= money;
    }
    void transfer(double money, ChargingAccount &chargingAccount)
    {
        chargingAccount.deposit(money);
        balance -= money;
    }
};
int main()
{
    Account account(1000);
    InterestAccount interestAccount(1000);
    ChargingAccount chargingAccount(1000);
    ACI aci(1000);
    account.deposit(100);
    account.withdraw(50);
    account.checkBalance();
    interestAccount.deposit(100);
    interestAccount.checkBalance();
    chargingAccount.withdraw(50);
    chargingAccount.checkBalance();
    aci.transfer(100, account);
    aci.transfer(100, interestAccount);
    aci.transfer(100, chargingAccount);
    aci.checkBalance();
    account.checkBalance();
    interestAccount.checkBalance();
    chargingAccount.checkBalance();
    return 0;
}
