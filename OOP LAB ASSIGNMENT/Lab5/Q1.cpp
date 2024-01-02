#include<iostream>
using namespace std;
class Child{
	private:
		int privateInt;
	protected:
		int protectedInt;
	public:
		int publicInt;
		//Getters
		int getPrivateInt(){
			return privateInt;
		}
		int getPublicInt(){
			return publicInt;
		}
		int getProtectedInt(){
			return protectedInt;
		}
		//Setters
		void setPrivateInt(int x){
			privateInt=x;
		}
		void setPublicInt(int x){
			publicInt=x;
		}
		void setProtectedInt(int x){
			protectedInt=x;
		}	
};
//Public Inheritance
class publicChild:public Child{
	public:
		void access_members(){
			cout<<"Public Child Access:"<<endl;
			cout<<"Public Int:"<<getPublicInt()<<endl;
			cout<<"Private Int:"<<getPrivateInt()<<endl;
			cout<<"Protected Int:"<<getProtectedInt()<<endl;
			setPublicInt(1);
			setPrivateInt(1);
			setProtectedInt(1);
		}
};
//Private Inheritance
class privateChild:private Child{
	public:
	void access_members(){
			cout<<"Private Child Access:"<<endl;
			cout<<"Public Int:"<<getPublicInt()<<endl;
			setPublicInt(2);
			cout<<"Private Int:"<<getPrivateInt()<<endl;
			setPrivateInt(2);
			cout<<"Protected Int:"<<getProtectedInt()<<endl;
			setProtectedInt(2);
		}
};
//Protected Inheritance
class protectedChild:protected Child{
	public:
		void access_members(){
			cout<<"Protected Child Access:"<<endl;
			cout<<"Public Int:"<<getPublicInt()<<endl;
			setPublicInt(3);
			cout<<"Private Int:"<<getPrivateInt()<<endl;
			setPrivateInt(3);
			cout<<"Protected Int:"<<getProtectedInt()<<endl;
			setProtectedInt(3);
		}	
};
int main(){
	publicChild o1;
	o1.access_members();
	protectedChild o2;
	o2.access_members();
	privateChild o3;
	o3.access_members();
}