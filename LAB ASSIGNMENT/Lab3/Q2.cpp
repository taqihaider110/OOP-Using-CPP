#include<iostream>
using namespace std;

class tollbooth{
    int totalcars;
    double totalmoneycollected;
    public:
        tollbooth():totalcars(0),totalmoneycollected(0){}
        tollbooth(int C,double M){totalcars=C;totalmoneycollected=M;}
        void PayingCar(){
            totalcars++;
            totalmoneycollected+=0.50;
        }
        void display(){
            cout<<"Total cars that passed tollbooth : "<<totalcars<<endl;
            cout<<"Total Money from cars : "<<totalmoneycollected<<" $"<<endl;
        }
};

int main(){
    tollbooth toll1;
    char opt='y';
    while(opt=='y'||opt=='Y'){
        cout<<"Has a car passed the tollbooth? press 'Y' to increment."<<endl<<"Press any thing else to display total"<<endl;
        cin>>opt;
        if(opt=='y'||opt=='Y'){toll1.PayingCar();}
    }
    toll1.display();
}