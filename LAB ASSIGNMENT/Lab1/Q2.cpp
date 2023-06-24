#include<iostream>
using namespace std;
int swaps(int *a,int *b,int *c){
    int temp=*a;
    *a=*b;
    *b=*c;
    *c=temp;
    return 0;
}
int main(){
    int a,b,c;
    cout<<"Enter the value of a,b and c "<<endl;
    cin>>a>>b>>c;
    cout<<"The Value before swap of a is "<<a<<" and b is "<<b<<" and c is "<<c<<endl;
    swaps(&a,&b,&c);
    cout<<"The Value after swap of a is "<<a<<" and b is "<<b<<" and c is "<<c<<endl;
    return 0;
}