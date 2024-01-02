#include<iostream>
#include<string>
using namespace std;

int main(){
	char** names;
	string name;
	int n,loc;
	cout<<"Enter number of students: ";
	cin>>n;
	names = new char*[n];
	for(int i=0;i<n;i++){
		cout<<"Enter name of student #"<<i+1<<" : ";
		fflush(stdin);
		getline(cin, name);
		names[i]=new char[name.length()+1];
		for(int j=0;j<name.length();j++){
			names[i][j]=name[j];
		}
		names[i][name.length()]='\0';
	}
	cout<<endl<<endl;
	for(int i=0;i<n;i++){
		int j=0;
		while(names[i][j]!='\0'){
			cout<<names[i][j];
			j++;
		}
		cout<<endl;
	}
	bool found=false;
	cout<<endl<<endl;
	cout<<"Enter name to search :";
	getline(cin, name);
	for(int i=0;i<n;i++){
		int j=0;
		while(names[i][j]==name[j] && names[i][j]!='\0'){
			j++;
		}
		if(names[i][j]=='\0'){
			found=true;
			loc=i;
		}
	}
	if(found==true){
		cout<<"The name was found at index "<<loc<<endl;
	}
	else{
		cout<<"Name not found"<<endl;
	}
}