#include<iostream>
using namespace std;

void EnterChar(char ch) {
	char ch2;
	cout<<"Enter Character: ";
	cin>>ch2;
	if(ch2!=ch) {
		EnterChar(ch);
		cout<<ch2<<"\t";
	}
}

int main() {
	// Special range is not same
	// A-Z, a-z, 0-9
	// ANYTHING ELSE is SPECIAL
	char special;
	cout<<"Input a special Character(anything not an alphabate or number special): ";
	cin>>special;
	cout<<endl<<endl;
	EnterChar(special);
}