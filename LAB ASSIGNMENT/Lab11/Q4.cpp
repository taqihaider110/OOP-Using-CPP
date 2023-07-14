#include<iostream>
#include<map>
#include<string>
using namespace std;

void retrieval(map<string,char>& mapped,string name) {
	map<string, char>::iterator itr = mapped.begin();
	while (itr != mapped.end()) {
		if (name == itr->first) {
			cout << "the grade of the given student is: " << itr->second << endl;
			break;
		}
		itr++;
	}
	if (itr == mapped.end()) {
		cout << "The name doesnot exist!" << endl;
	}
}

void update(map<string, char>& mapped, string name, char grd) {
	map<string, char>::iterator itr = mapped.begin();
	while (itr != mapped.end()) {
		if (name == itr->first) {
			itr->second==grd;
			break;
		}
		itr++;
	}
	if (itr == mapped.end()) {
		cout << "The name doesnot exist!" << endl;
	}
}

void del(map<string, char>& mapped, string name) {
	map<string, char>::iterator itr = mapped.begin();
	while (itr != mapped.end()) {
		if (name == itr->first) {
			mapped.erase(name);
			cout << "The corresponding key and value was deleted!" << endl;
			break;
		}
		itr++;
	}
	if (itr == mapped.end()) {
		cout << "The name doesnot exist!" << endl;
	}
}

void display(map<string, char>& mapped) {
	int count = 1;
	map<string, char>::iterator itr = mapped.begin();
	while (itr != mapped.end()) {
		
		cout << count << "." << itr->first << "'s grade is: " << itr->second << endl;
		itr++;
	}
}

int main() {
	string name;
	char grade;
	map<string, char> grademap;
	char choice;
	cout << "do you want to enter student grades?(Y/N)";
	cin >> choice;
	while (choice == 'y' || choice == 'Y') {
		cout << "Enter name: ";
		cin >> name;
		cout << "\nEnter the respective grade: ";
		cin >> grade;
		grademap[name] = grade;
		cout << "\n";
		cout << "do you want to enter another kids grade?(Y/N): ";
		cin >> choice;
	}
	cout << "Enter a student's name to retrieve the grade: " << endl;
	cin >> name;
	retrieval(grademap, name);
	cout << "Enter a student's name to update the grade: ";
	cin >> name;
	cout << endl;
	cout << "Enter new grade: ";
	cin >> grade;
	cout << endl;
	update(grademap, name, grade);
	cout << "Enter a student's name to delete: ";
	cin >> name;
	cout << endl;
	del(grademap, name);
	display(grademap);
}