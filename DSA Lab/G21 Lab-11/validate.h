#include<iostream>
using namespace std;

#ifndef VALIDATE_H
#define VALIDATE_H


template <class T>
T InputValid(){
	T input;
	return input;
};

template <>
int InputValid<int>(){
	int input;
	cout<<"Input an Integer Value [REAL numbers will be truncated]:\n";
	cin>>input;
	while(!cin){
		fflush(stdin);
		cin.clear();
		cout<<"Invalid Input Type Try Again.\n Please Input a Integer Value [REAL numbers will be truncated]: \n";
		cin>>input;
	}
	return input;
}

template <>
float InputValid<float>(){
	float input;
	cout<<"Input a Real Number:\n";
	cin>>input;
	while(!cin){
		fflush(stdin);
		cin.clear();
		cout<<"Invalid Input Type Try Again.\n Please Input a Real Number:\n";
		cin>>input;
	}
	return input;
}



#endif