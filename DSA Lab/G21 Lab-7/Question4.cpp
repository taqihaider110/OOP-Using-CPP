#include<iostream>
using namespace std;

double raise(double num,int p){
	if(p<2){
		return num;
	}
	else{
		return num * raise(num,p-1);
	}
}

int main(){
	double num;
	//Validation
	cout<<"Enter value want to raise to a power: ";
	cin>>num;
	while(!cin){
		cin.clear();
		fflush(stdin);
		cout<<"Invalid Data Type, please Enter an DOUBLE:\n";
		cin>>num;
	}
	cout<<endl;
	unsigned int power;
	//Validation
	cout<<"Enter the Power to want to raise:"<<endl;
	cin>>power;
		while(!cin){
		cin.clear();
		fflush(stdin);
		cout<<"Invalid Data Type, please Enter an INTEGER:\n";
		cin>>power;
	}
	cout<<endl;
	cout<<"Value raised = "<<raise(num,power)<<endl;
	
}