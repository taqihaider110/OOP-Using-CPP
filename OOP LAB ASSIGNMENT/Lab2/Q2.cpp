#include<iostream>
#include <string>
using namespace std;
class BankAccount{
    long double AccountBalance;
    float Interest;
	public:
    BankAccount(): AccountBalance(740), Interest(0.01){} 
		long double Display_AccountBalance(){
			return AccountBalance;
		}
	    void deposits(float amount){
		    AccountBalance += amount;
		}
		void withdrawls(float amount){
            if(amount<=AccountBalance){
			    AccountBalance -= amount;
			    cout<<" withdrawl of "<<amount<<" successful."<<endl;
		    }
            else{
                cout<<"Not enough Amount Available:("<<endl;
            }
        }
		float  InterestRate(float t){
            t=t/12;
			return AccountBalance*Interest*t;
		}
		void LastDetail(){
			cout<<"ACCOUNT BALANCE "<<AccountBalance<<endl;
		}
};
int main(){
	string Name;
    float t;
	cout<<"ENTER YOUR NAME: ";
	getline (cin, Name);
	cout<<endl;
	string account_num;
	cout<<"ENTER YOUR ACCOUNT NUMBER: ";
	getline (cin,account_num);
	BankAccount account;
    long double amount;
    int no_of_transactions=0;
	int choose;
	system("cls");
	while(1){
		cout << "Menu:"<<endl;
        cout << "1. Display the account balance"<<endl;
        cout << "2. Display the number of transactions"<<endl;
        cout << "3. Display interest earned for this period"<<endl;
        cout << "4. Make a deposit"<<endl;
        cout << "5. Make a withdrawal"<<endl;
        cout << "6. Exit the program"<<endl;
        cout << "Enter your choice: ";
        cin >> choose;
        system("cls");
	switch(choose){
		case 1:
			cout<<"ACCOUNT BALANCE IS "<<account.Display_AccountBalance()<<endl;
			break;
		case 2:
			 cout<<"Number of Transactions:"<<no_of_transactions<<endl;
			break;
		case 3:
            cout<<"Enter Time in terms of Months ";
            cin>>t;
			cout<<"Interest earned for this period:"<<account.InterestRate(t)<<endl;
			break;
		case 4:
			cout<<"Make a deposit: ";
			cin>>amount;
			account.deposits(amount);
			cout<<"Deposit of"<<amount<<"successful."<<endl;
			no_of_transactions=no_of_transactions+1;
			break;
		case 5:
			cout<<"Make a withdrawal: ";
			cin>>amount;
			account.withdrawls(amount);
			no_of_transactions=no_of_transactions+1;
			break;
		case 6:
            system("cls");
			cout<<"Name of Customer: "<<Name<<endl;
			cout<<"ACCOUNT NUMBER: "<<account_num<<endl;
			account.LastDetail();
            exit(0);    
        default:
            cout<<"Invalid choice";
    }
    }
}