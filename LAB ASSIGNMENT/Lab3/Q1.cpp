#include<iostream>
using namespace std;

class Example{
    int Value;
    public:
        Example(int v){Value=v;}
        Example(Example& obj){Value=obj.Value;}
        void showdata(){
            cout<<"Value: "<<Value<<endl;
        }
};

int main(){
    Example obj1(20);
    Example obj2(obj1);
    Example obj3=obj1;
    cout<<"Object 1: "<<endl;
    obj1.showdata();
    cout<<"Object 2: "<<endl;
    obj2.showdata();
    cout<<"Object 3: "<<endl;
    obj3.showdata();
}