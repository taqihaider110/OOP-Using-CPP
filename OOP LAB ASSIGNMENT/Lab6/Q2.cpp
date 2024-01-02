#include<iostream>
using namespace std;
class calculator{
	double num1;
    double num2,num3;
	public:
		//function overloading concept:
		double multiply(double a, double b){
			num1=a;
            num2=b;
            return num1*num2;
		}
		double multiply(double a,double b,double c){
			num1=a;
            num2=b;
            num3=c;
            return num1*num2*num3;
		}
		double sum(double a,double b){
            num1=a;
            num2=b;
			return num1+num2;
		}
		double sum(double a,double b,double c){
			num1=a;
            num2=b;
            num3=c;
            return num1+num2+num3;
		}
		double subtract(double a,double b){
			num1=a;
            num2=b;
            return num1-num2;
		}
		double subtract(double a,double b,double c){
			num1=a;
            num2=b;
            num3=c;
            return num1-num2-num3;}
		float divide(double a,double b){
			num1=a;
            num2=b;
            return num1/num2;
		}
		float divide(double a,double b,double c){
			num1=a;
            num2=b;
            num3=c;
            double n=num1/num2/num3;
            return n;}
};
int main(){
	calculator c;
    double A,B,C;
    cout<<"Enter first num:"<<endl;
    cin>>A;  
    cout<<"Enter second number:"<<endl;
    cin>>B;  
    cout<<"Enter third number:"<<endl;
    cin>>C;  

	cout<<"The product of two integers are:"<<c.multiply(A,B)<<endl;
	cout<<"The product of three integers are:"<<c.multiply(A,B,C)<<endl;
	cout<<"The sum of two integers are:"<<c.sum(A,B)<<endl;
	cout<<"The sum of three integers are:"<<c.sum(A,B,C)<<endl;
	cout<<"The difference of two integers are:"<<c.subtract(A,B)<<endl;
	cout<<"The difference of three integers are:"<<c.subtract(A,B,C)<<endl;
	cout<<"The quotient of two integers are:"<<c.divide(A,B)<<endl;
	cout<<"The quotient of three integers are:"<<c.divide(A,B,C)<<endl;
}
