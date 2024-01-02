#include<bits/stdc++.h>
using namespace std;

//This assumes CGPAs are already given
int main(){
	float students[5][5]={{3.66,3.33,4.0,3.0,2.66},{3.33,3.0,3.66,3.0,0},{4.0,3.66,2.66,0,0},{2.66,2.33,4.0,0,0},{3.33,3.66,4.0,3.0,3.33}};
	float count=0,total=0;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			total+=students[i][j];
			(students[i][j] != 0 )?count=count+1:count=count;
		}
		cout<<"CGPA (ignoring -- subjects) of student #"<<i+1<<" "<<total/count<<endl;
		count=0;total=0;	
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			total+=students[i][j];
		}
		cout<<"CGPA of student #"<<i+1<<"  "<<total/5<<endl;
		count=0;total=0;	
	}
}

/*  This one takes input of all GPAs then calculates for those
#include<iostream>
using namespace std;

int main(){
	float cgpa;
	int NoOfSub;
	int CreditHours=3;
	float gradePoints=0;
	float grades;
	cout<<"enter total number of subjects"<<endl;
	cin>>NoOfSub;
	
	for(int i=1;i<=NoOfSub;i++){
	cout<<"enter the grades of courses"<<i<<" "<<endl;
	cin>>grades;
	gradePoints+=grades*3;
	CreditHours=3*NoOfSub;
	}
	
	cgpa=gradePoints/CreditHours;
	cout<<"cgpa of sem is"<<cgpa<<endl;
	return 0;
}
*/
