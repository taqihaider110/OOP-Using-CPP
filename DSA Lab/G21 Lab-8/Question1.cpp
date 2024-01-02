#include<iostream>
using namespace std;

void merge(int arr[],int l,int m,int r) {
	int n1=m-l+1,n2=r-m;

	int L[n1],R[n2];
	for(int i=0; i<n1; i++) {
		L[i]=arr[l+i];
	}
	for(int i=0; i<n2; i++) {
		R[i]=arr[m+i+1];
	}

	int i=0,j=0,k=l;
	while(i<n1 && j<n2) {
		if(L[i]<R[j]) {
			arr[k]=L[i];
			k++;
			i++;
		} else {
			arr[k]=R[j];
			k++;
			j++;
		}
	}
	while(i<n1) {
		arr[k]=L[i];
		k++;
		i++;
	}
	while(j<n2) {
		arr[k]=R[j];
		k++;
		j++;
	}
}
void mergesort(int arr[],int l,int r) {
	if(l<r) {
		int mid=(l+r)/2;
		mergesort(arr,l,mid);
		mergesort(arr,mid+1,r);
		merge(arr,l,mid,r);
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
	mergesort(arr,0,n-1);
	cout<<"Sorted array"<<endl;
	for(int i=0; i<n; i++) {
		cout<<arr[i]<<"\t";
	}
}
