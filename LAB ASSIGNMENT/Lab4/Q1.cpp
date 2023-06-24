#include <iostream>
#include <cstring>
using namespace std;
class Employee {
private:
    char* EmployeeName;
    int EmployeeId;
public:
    Employee(const char* name, int id){
    	EmployeeId=id;
        EmployeeName = new char[strlen(name)+1];
        strcpy(EmployeeName, name);
    }
	char* getName(){
        return EmployeeName;
    }
    void name(const char* name) {
        delete[] EmployeeName;
        EmployeeName = new char[strlen(name)+1];
        strcpy(EmployeeName, name);
    }
    int getId(){
        return EmployeeId;
    }
};

int main() {
    Employee Emp1("MUHAMMAD", 1001);
    Employee Emp2("TAQI", 1002);
    Employee Emp3("HAIDER", 1003);
	cout<<"Employee1: "<< Emp1.getName()<<"("<<Emp1.getId()<<")"<<endl;
    cout<<"Employee2: "<< Emp2.getName()<<"("<<Emp2.getId()<<")"<<endl;
    cout<<"Employee3: "<< Emp3.getName()<<"("<<Emp3.getId()<<")"<<endl;
	Emp2.name("FATIMA");
    cout <<"Employee2: "<<Emp2.getName()<<"("<<Emp2.getId()<<")"<<endl;
    return 0;
}
