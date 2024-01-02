#include<iostream>
using namespace std;
class Account{
	int account_bal;
	int account_no;
	int security_code;
	static int count;
	public:
		Account(int ab,int an,int sc){
			account_bal=ab;
			account_no=an;
			security_code=sc;
			count++;
	
		}
		void printdata(){
			cout<<"account balance is:"<<account_bal<<"\taccount no is:"<<account_no<<"\tsecurity code is:"<<
			security_code<<"\tno of object is:"<<count<<endl;
		}
		
		
};
int Account::count;
int main(){
	Account a1(50000,01234,567);
	a1.printdata();
	Account a2(30000,91234,9567);
	a2.printdata();
	
	
	
}
