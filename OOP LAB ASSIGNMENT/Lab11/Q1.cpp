#include<iostream>
#include<stdexcept>
#include<string>
using namespace std;

int main() {
	bool digitfound = false;
	cout << "Enter your username: ";
	string uname;
	cin >> uname;
	try {
		cout << "Enter your password: ";
		string pass;
		cin >> pass;
		int passlen = pass.length();
		if (passlen >= 6) {
			for (int i = 0; i < passlen; i++) {
				
				if (pass[i] >= '0' && pass[i] <= '9') {
					digitfound = true;
				}
				else {
					continue;
				}
			}
		}
		if (digitfound == false) {
			throw 0;
		}
	}
	catch (int x) {
		if (x == 0) {
			cout << "password does not meet the requirements!";
			exit(1);
		}

	}
	cout << "data entered successfully!";
}