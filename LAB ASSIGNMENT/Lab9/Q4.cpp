#include<iostream>
#include<string>
using namespace std;
class EncryptionTechnique{
	protected:
		string message;
	public:
		EncryptionTechnique(string s):message(""){  //Automatically converts all lowercases to uppercases on initialization
			for(int i=0;i<s.size();i++){
				message+=toupper(s[i]);
			}
		}
		virtual string encrypt()=0;	
};

class EncryptionTechnique1:public EncryptionTechnique{
	public:
		EncryptionTechnique1(string s):EncryptionTechnique(s){}
		string encrypt(){
			string encrypted="";
			int x;
			for(int i=0;i<message.size();i++){
				x=message[i];
				encrypted+=to_string(x);
			}
			return encrypted;
		}
};

class EncryptionTechnique2:public EncryptionTechnique{
	public:
		EncryptionTechnique2(string s):EncryptionTechnique(s){}
		string encrypt(){
			string encrypted="";
			int x;
			for(int i=0;i<message.size();i++){
				x=message[i]+2;
				encrypted+=to_string(x);
			}
			return encrypted;
		}
};

int main(){
	EncryptionTechnique1 obj1("Hello");
	EncryptionTechnique2 obj2("HELLO");
	cout<<"Method 1 Encryption : "<<obj1.encrypt()<<endl;
	cout<<"Method 2 Encryption : "<<obj2.encrypt()<<endl;	
}
