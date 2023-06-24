#include<iostream>
#include <stdio.h>
using namespace std;
int main(){
	float i,j,total_amt=200000,withdraw;
	char code,choice;
	char account_number[10];
	float tax;
	cout<<"Enter Account type"<<endl<<"1) \"S\" for saving"<<endl<<"2) \"C\" for Current"<<endl;
	cin>>choice;
	if(choice=='S' || choice== 's'){
		cout<<"Enter Account Number: ";
		cin>>account_number;
		while(1){
			cout<<endl;
			cout<<"enter Code: ";
			cin>>code;
			cout<<endl;
			if(code=='S' || code=='s' ){
				cout<<"ENTER amount to withdraw: ";
				cin>>withdraw;
				if(withdraw>50000 && withdraw<=100000){
					tax = withdraw * 0.05;
					total_amt=total_amt-withdraw-tax;
					break;
				}
				else if(withdraw<=50000){
					tax = withdraw* 0.02;
					cout<<"tax"<<tax<<endl;
					total_amt=total_amt-withdraw;
//					cout<<"before TAX "<<total_amt<<endl;
					total_amt=total_amt-tax;
//					cout<<"AF TAX "<<total_amt<<endl;
					break;
				}
				else{
					cout<<"Can\'t Withdraw more than 100000";
				}
				
			}	
		}
	}
	if(choice=='c' || choice== 'C'){
		cout<<endl;
		cout<<"Enter Account Number: ";
		cin>>account_number;
		while(1){
			cout<<endl;
			cout<<"enter Code: ";
			cin>>code;
			cout<<endl;
			if(code=='C' || code=='c' ){
				cout<<"ENTER amount to withdraw: ";
				cin>>withdraw;
				if(withdraw>50000 && withdraw<=100000){
					tax += withdraw*0.05;
					total_amt=total_amt-withdraw-tax-100;
					break;
				}
				else if(withdraw<=50000){
					total_amt =total_amt-withdraw-100;
					break;
				}
				else{
					cout<<"Can\'t Withdraw more than 100000";
				}
				
			}
		}
	}
//	system("cls");
	cout<<"Withdraw Amount: "<<withdraw<<endl;
	cout<<"Total Amount: "<<total_amt<<endl;
	cout<<"Tax Paid: "<<tax;
}
