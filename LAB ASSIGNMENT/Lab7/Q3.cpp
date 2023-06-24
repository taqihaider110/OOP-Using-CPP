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
		friend class Payroll;
};

class Payroll{
	public:
		void changepay(Employee& person){
			cout<<"Enter new salary of "<<person.name<<endl;
			cin>>person.salary;
		}
};

int main(){
	Employee person("Taqi","Student",78,1400);
	cout<<"----------------------"<<endl;
	person.showdata();
	Payroll salary;
	salary.changepay(person);
	cout<<"----------------------"<<endl;
	person.showdata();
}