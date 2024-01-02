#include<iostream>
using namespace std;

int fibonacci(int n) {
	if(n<2) {
		return n;
	} else {
		return fibonacci(n-1)+fibonacci(n-2);
	}
}

int main() {
	int n;
	cout<<"Enter nth term of Fibonacci to Show series (Float Values will be treated as truncated Integers): ";
	cin>>n;
	while(!cin) {
		cin.clear();
		fflush(stdin);
		cout<<"Invalid Data Type, please Enter an INTEGER:\n";
		cin>>n;
	}
	cout<<endl;
	for(int i=0; i<n; i++) {
		cout<<fibonacci(i)<<"\t";
	}
	cout<<endl;
}