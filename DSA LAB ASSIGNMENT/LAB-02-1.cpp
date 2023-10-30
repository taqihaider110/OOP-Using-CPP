#include<iostream>
using namespace std;
void swap(int* x,int* y){
	int temp=*x;
	*x=*y;
	*y=temp;
}
//Sorting for Decending Order...
int main(){
	int size;
	cout<<"Enter Size Of Array:";
	cin>>size;
	int arr[size];
	cout<<"Enter Array Elements:"<<endl;
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	for(int i=0;i<size-1;i++){
		bool isSorted=false;
		for(int j=0;j<(size-1);j++){
			if(arr[j]<arr[j+1]){//Sorting for Decending Order...
//			if(arr[j]>arr[j+1]){//Sorting for Ascending Order (LOGIC).. 
				swap(&arr[j],&arr[j+1]);
				isSorted=true;
			}
//			}
		}
		if(!isSorted){
			cout<<"Already Sorted!"<<endl;
			break;
		}
	}
	
		for(int i=0;i<size;i++){
			cout<<arr[i]<<" ";
	}
	return 0;
}