#include<iostream>
#include<string>
using namespace std;
int main(){
    string rn;
    float sub1,sub2,sub3,sub4,sub5,total_marks,percentage;
    cout<<"Enter your roll No and Total marks out of 100 "<<endl;
    cin>>rn>>sub1>>sub2>>sub3>>sub4>>sub5;
    total_marks=sub1+sub2+sub3+sub4+sub5;
    percentage=(total_marks/500)*100;
    cout<<"The total marks is "<<total_marks<<" out of 500 and the Percentage is "<<percentage<<"%"<<endl;
    return 0;
}