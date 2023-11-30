#include<iostream>
#include<string>

using namespace std;

class stack {
		char arr[20];
		int top=-1;
	public:
		stack() {
			for(int i=0; i<20; i++) {
				arr[i]=0;
			}
		}
		bool full() {
			return top==19;
		}
		bool empty() {
			return top==-1;
		}

		void push(char value) {
			if(!full()) {
				top++;
				arr[top]=value;
			} else {
				cout<<"Array is Full.\n";
				return;
			}
		}
		char pop() {
			if(!empty()) {
				char temp = arr[top];
				top--;
				return temp;
			} else {
				cout<<"Array is Empty.\n";
				return -1;
			}
		}
		void display() {
			cout<<"\n--";
			for(int i=0; i<=top; i++) {
				cout<<arr[i];
			}
			cout<<"--\n";
		}
};

bool checkp(string s) {
	stack word;
	for(int i=0; i<s.length(); i++) {
		word.push(s[i]);
	}
	string reversed="";
	for(int i=0; i<s.length(); i++) {
		reversed+=word.pop();
	}
	return s==reversed;
}

int main() {
	string str;
	cout<<"Enter String to check for palindrome:\n";
	getline(cin,str);
	if(checkp(str)) {
		cout<<"String is Palindrome\n";
	} else {
		cout<<"String is NOT Palindrome\n";
	}
}