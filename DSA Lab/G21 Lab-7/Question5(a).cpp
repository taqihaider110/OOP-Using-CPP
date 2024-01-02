#include<iostream>
using namespace std;

void printodds(int num) {
	if(num>1) {
		printodds(num-1);
		if(num%2==1) {
			cout<<num<<endl;
		}
	} else {
		cout<<1<<endl;
		return;
	}
}
int main() {
	int n;
	cout<<"Enter the value you want to print the odds between 1-this value:";
	cin>>n;
	while(!cin){
		cin.clear();
		fflush(stdin);
		cout<<"Invalid Data Type, please Enter an Integer:\n";
		cin>>n;
	}
	cout<<endl;
	printodds(n);
	//ODDS in between 1-n
}