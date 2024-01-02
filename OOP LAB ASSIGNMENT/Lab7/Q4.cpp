#include<iostream>
using namespace std;

class Employee{
	
	string name,designation;
	int id,salary;
	
	public:
		Employee(string n,string d,int i,int s):name(n),designation(d),id(i),salary(s){}
		void showdata(){
			cout<<"Name : "<<name<<endl<<"Desg. : "<<designation<<endl<<"ID : "<<id<<endl<<"Salary :"<<salary<<endl;
		}	
		friend void changepay(Employee& person);
};

void changepay(Employee& person){ //function to change payroll
			cout<<"Enter new salary of "<<person.name<<endl;
			cin>>person.salary;
}

int main(){
	Employee person("Taqi","Developer",48,750);
	cout<<"----------------------"<<endl;
	person.showdata();
	changepay(person);
	cout<<"----------------------"<<endl;
	person.showdata();
}