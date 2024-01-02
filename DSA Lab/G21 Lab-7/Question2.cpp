#include<iostream>
using namespace std;

int factorial(int n) {
	if(n<2) {
		return 1;
	} else {
		return n*factorial(n-1);
	}
}

int main() {
	int n;
	cout<<"Enter the value to find factorial of:(Float Values will be treated as truncated Integers): ";
	cin>>n;
	while(!cin) {
		cin.clear();
		fflush(stdin);
		cout<<"Invalid Data Type, please Enter an INTEGER:\n";
		cin>>n;
	}
	cout<<endl;
	cout<<factorial(n)<<"\t";
	cout<<endl;
}