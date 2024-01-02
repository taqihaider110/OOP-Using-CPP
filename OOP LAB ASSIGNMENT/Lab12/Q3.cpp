#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Person {
private:
    string name;
    int age;

public:
	Person():name(""),age(0){}
    Person(const string& personName, int personAge) : name(personName), age(personAge) {}

    // Getter methods
    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }
};

int main() {
    // Create an instance of the Person class and name it person1
    Person person1("Taqi Haider", 20);

    // Write person1 object into a binary file
    ofstream outFile("person.bin", ios::binary);
    if (outFile.is_open()) {
        outFile.write(reinterpret_cast<const char*>(&person1), sizeof(person1));
        outFile.close();
        cout << "Successfully wrote person1 object to the file." << endl;
    }
    else {
        cout << "Failed to open the file for writing." << endl;
    }

    // Read the person1 object from the file
    Person readPerson;
    ifstream inFile("person.bin", ios::binary);
    if (inFile.is_open()) {
        inFile.read(reinterpret_cast<char*>(&readPerson), sizeof(readPerson));
        inFile.close();
        cout << "Successfully read person1 object from the file." << endl;
        cout << "Name: " << readPerson.getName() << endl;
        cout << "Age: " << readPerson.getAge() << endl;
    }
    else {
        cout << "Failed to open the file for reading." << endl;
    }

    return 0;
}
