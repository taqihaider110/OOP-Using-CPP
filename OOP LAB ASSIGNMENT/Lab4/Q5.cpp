#include <iostream>
#include <string> 
using namespace std;
class hotel{
	private:
		int rent;
		float total;
		float totalrent() {
				int temp=days-1;
				int discount=(rent*days)*0.1;
				if(temp>7){
					total=(rent*days)-discount;//10% discount is given to customer.
					return total;
				}
				else{
					total=(rent*days);
					return total;
				}
			}
	public:
		int days;
		string CustomerName;
		hotel(){
			days=0;
			rent=1000.85;
		}
		hotel(int a){
			days=a;
			rent=1000.85;
			float totalrent();	
		}
		void getName(string ch){
			CustomerName=ch;
		}
		void show(){
			cout<<"NAME OF CUSTOMER: "<<CustomerName<<endl;
			cout<<"NUMBER OF DAYS: "<<days<<endl;
			cout<<"RENT: "<<totalrent()<<endl;
		}
};
int main(){
	string name;
	int days;
	cout<<"enter customer name: ";
	getline(cin,name);
	cout<<"Enter number of days: ";
	cin>>days;
	hotel obj1(days);
	obj1.getName(name);
	system("cls");
	obj1.show();
}
