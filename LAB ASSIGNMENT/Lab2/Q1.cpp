#include<iostream>
#include<string>
using namespace std;
class student{
    string name[100];
    string roll_no[100];
	string semester[100];
	char sec[100];
    int counter;
	public:
	    void initcounter(void){
	    	counter=0;
		}
		void setData(void);
	    void displayData(void); 
};
void student:: setData(void){
 		cout<<"Name of the student is:"<<endl;
		cin>>name[counter];
		cout<<"Roll no of the student is:"<<endl;
		cin>>roll_no[counter];
		cout<<"Semester of the student is:"<<endl;
		cin>>semester[counter];
		cout<<"Section of the student is:"<<endl;
		cin>>sec[counter];
		counter++;
 }
void student:: displayData(void){
		cout<<"Displaying Data of Section A students:"<<endl;
	for(int i=0;i<counter;i++){
		if(sec[i]=='A'){
			cout<<"Name of the student is:"<<name[i]<<endl;
			cout<<"Roll no of the student is:"<<roll_no[i]<<endl;
			cout<<"Semester of the student is:"<<semester[i]<<endl;
			cout<<"Section of the student is:"<<sec[i]<<endl;
		}
	}
}
int main(){
	student s;
	s.initcounter();
	s.setData();
	s.setData();
	s.setData();
	s.setData();
	s.displayData();
	return 0;
}