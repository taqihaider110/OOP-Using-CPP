#include<iostream>
#include<string>

using namespace std;

class stack {
		float arr[20];
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

		void push(float value) {
			if(!full()) {
				top++;
				arr[top]=value;
			} else {
				cout<<"Array is Full.\n";
				return;
			}
		}
		float pop() {
			if(!empty()) {
				int temp = arr[top];
				top--;
				return temp;
			} else {
				cout<<"Array is Empty.\n";
				return -1;
			}
		}

};

float solveeq(stack &obj,string exp) {
	string curr="";
	for(int i=0; i<exp.length(); i++) {
		curr = exp[i];
		if(curr>="0"&&curr<="9") {
			obj.push(stoi(curr));
		} else if(exp[i]=='+') {
			float temp=obj.pop();
			obj.push(obj.pop()+temp);
		} else if(exp[i]=='-') {
			float temp=obj.pop();
			obj.push(obj.pop()-temp);
		} else if(exp[i]=='/') {
			float temp=obj.pop();
			obj.push(obj.pop()/temp);
		} else if(exp[i]=='*') {
			float temp=obj.pop();
			obj.push(obj.pop()*temp);
		} else {
			cout<<"Invalid Character!"<<endl;
		}
	}
	return obj.pop();
}

int main() {
	string exp;
	stack e;
	cout<<"Enter Postfix Expression without Exponents (Numbers will be read as Single Digits and as INTEGERS): \n";
	cin>>exp;
	cout<<"Answer of your Expression: "<<solveeq(e,exp)<<endl;
}