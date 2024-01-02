#include<iostream>
using namespace std;

int main(){
    int n,k;
    cout<<"Enter Number of Toys:";
    cin>>n;
    int toycosts[n];
    for(int i=0;i<n;i++){
        cout<<"Enter cost of Toy #"<<i<<" :"<<endl;
        cin>>toycosts[i];
    }
    
    cout<<"Enter amount you have:"<<endl;
    cin>>k;
    int remaining = k;
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(toycosts[j]>toycosts[j+1]){
                int temp;
                temp = toycosts[j];
                toycosts[j]=toycosts[j+1];
                toycosts[j+1]=temp;
            }
        }
    }
    int count=0;
    cout<<"The Cost of items you can buy are ";
    for(int i=0;i<n;i++){
        if(toycosts[i]<=remaining){
            count++;
            remaining-=toycosts[i];
            cout<<toycosts[i]<<" ";
        }
        if(toycosts[i]>remaining){
            break;
        }
    }
    cout<<endl<<"Total Toys : "<<count<<endl;

}
