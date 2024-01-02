#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Employee {
    private:
        char* FirstName;
        string LastName;
        int MonthlySalary;
    public:
        Employee(char* FirstN, string LastN, int Sal) {
            FirstName = new char[strlen(FirstN) + 1];
            strcpy(FirstName, FirstN);
            LastName = LastN;
            setMonthlySalary(Sal);
        }
        ~Employee() {
            delete[] FirstName;
        }
        string getFirstName() {
            return FirstName;
        }
        string getLastName() {
            return LastName;
        }
        void setMonthlySalary(int Sal) {
            if (Sal >= 0) {
                MonthlySalary = Sal;
            } else {
                MonthlySalary = 0;
            }
        }
        int getYearlySalary() {
            return MonthlySalary * 12;
        }
        void giveRaise() {
            MonthlySalary *= 1.1;
        }
};

int main() {
    Employee emp1("Babar", "Azam", 65000);
    Employee emp2("Shaheen", "Afridi", 50000);

    cout << emp1.getFirstName() << " " << emp1.getLastName() << endl;
    cout << "Yearly salary is: " << emp1.getYearlySalary() << endl;

    cout << emp2.getFirstName() << " " << emp2.getLastName() << endl;
    cout << "Yearly salary is: " << emp2.getYearlySalary() << endl;

    emp1.giveRaise();
    emp2.giveRaise();

    cout << emp1.getFirstName() << " " << emp1.getLastName() << endl;
    cout << "Yearly salary after raise is: " << emp1.getYearlySalary() << endl;

    cout << emp2.getFirstName() << " " << emp2.getLastName() << endl;
    cout << "Yearly salary after raise is: " << emp2.getYearlySalary() << endl;

    return 0;
}
