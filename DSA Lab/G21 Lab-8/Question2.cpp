#include<iostream>
using namespace std;

int partition(int arr[],int l,int r) {
	int pivot=arr[r];

	int i=l-1;

	for(int j=l; j<=r; j++) {
		if(arr[j]<pivot) {
			i++;
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	int temp=arr[i+1];
	arr[i+1]=arr[r];
	arr[r]=temp;
	return i+1;
}

void quicksort(int arr[],int l,int r) {
	if(l<r) {
		int pi = partition(arr,l,r);
		quicksort(arr,l,pi-1);
		quicksort(arr,pi+1,r);
	}
}
int main() {
	int n;
	cout<<"Enter size of an array you want to sort:"<<endl;
	cin>>n;
	while(!cin) {
		cin.clear();
		fflush(stdin);
		cout<<"Invalid Data Type, please Enter an Integer:\n";
		cin>>n;
	}
	cout<<endl;
	int arr[n];
	for(int i=0; i<n; i++) {
		cout<<"Enter element:"<<i<<":of an array"<<endl;
		cin>>arr[i];
		while(!cin) {
			cin.clear();
			fflush(stdin);
			cout<<"Invalid Data Type, please Enter an Integer:\n";
			cin>>arr[i];
		}
		cout<<endl;
		cin.clear();
		fflush(stdin);
	}
	quicksort(arr,0,n-1);
	cout<<"Sorted array"<<endl;
	for(int i=0; i<n; i++) {
		cout<<arr[i]<<"\t";
	}
}