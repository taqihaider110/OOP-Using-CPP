#include<iostream>
#include<string>
using namespace std;
class DecryptionTechnique{
	protected:
		string message;
	public:
		DecryptionTechnique(string s):message(s){}
		virtual string decrypt()=0;	
};

class DecryptionTechnique1:public DecryptionTechnique{
	public:
		DecryptionTechnique1(string s):DecryptionTechnique(s){}
		string decrypt(){
			string decrypted="",temp="";
			int Temp;
			char x;
			for(int i=0;i<message.size();i+=2){
				temp=message.substr(i,2);
				Temp=stoi(temp);
				x=Temp;
				decrypted+=x;
				temp="";
			}
			return decrypted;
		}
};

class DecryptionTechnique2:public DecryptionTechnique{
	public:
		DecryptionTechnique2(string s):DecryptionTechnique(s){}
		string decrypt(){
			string decrypted="",temp="";
			int Temp;
			char x;
			for(int i=0;i<message.size();i+=2){
				temp=message.substr(i,2);
				Temp=stoi(temp);
				x=Temp-2;
				decrypted+=x;
				temp="";
			}
			return decrypted;
		}
};

int main(){
	DecryptionTechnique1 obj1("7269767679");
	DecryptionTechnique2 obj2("7471787881");
	cout<<"Method 1 Decryption : "<<obj1.decrypt()<<endl;
	cout<<"Method 2 Decryption : "<<obj2.decrypt()<<endl;	
}
