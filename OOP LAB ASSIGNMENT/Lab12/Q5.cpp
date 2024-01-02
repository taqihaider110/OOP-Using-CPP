#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main() {
	string s;
	int count = 0;
	ifstream readfile("story.txt");
	if (!readfile) {
		cout << "file doesnot exist";
	}
	else {
		while (getline(readfile, s)) {
			if (s[0] != 'A') {
				count++;
				cout << s << endl;
			}
			
		}
	}
	cout << "lines not starting with'A'are: " << count;
}