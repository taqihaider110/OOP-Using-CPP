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
		void pop() {
			if(!empty()) {
				top--;
			}
			else{
				cout<<"Stack is Empty!"<<endl;
			}
		}
		char Top(){
			if(!empty()){
				return arr[top];
			}
			else{
				cout<<"Array Empty, Returning 'X'...\n";
				return 'X';
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

bool MatchDelim(string ex){
	stack delims;
	for(int i=0;i<ex.length();i++){
		if(ex[i]=='{'||ex[i]=='('||ex[i]=='['){
			delims.push(ex[i]);
		}
		else if(ex[i]==')'||ex[i]=='}'||ex[i]==']'){
			if(ex[i]==')' && delims.Top()=='('){
				delims.pop();
			}
			else if(ex[i]==']' && delims.Top()=='['){
				delims.pop();
			}
			else if(ex[i]=='}' && delims.Top()=='{'){
				delims.pop();
			}
			else{
				cout<<"Open and Close Brackets Mismatched at position "<<i<<endl;
				return false;
			}
		}    
	}
	if(delims.empty()){
		cout<<"Expression is valid\n";
		return true;
	}
	else{
		cout<<"Unclosed Delimiters Remain\n";
		delims.display();
		return false;
	}
}

int main(){
	string exp;
	cout<<"Enter Expressions to match the Delimiters:\n";
	getline(cin,exp);
	MatchDelim(exp);
	
}