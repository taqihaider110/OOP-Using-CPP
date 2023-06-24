#include<iostream>
using namespace std;
int main(){
    float fahrenheit,celsius;
    cout<<"Enter the value of fahrenheit "<<endl;
    cin>>fahrenheit;
    celsius=(fahrenheit-32)/1.8;
    cout<<"The Value in Celsius is "<<celsius<<endl;
    return 0;
}