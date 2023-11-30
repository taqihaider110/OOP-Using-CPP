#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n;
	cout<<"Enter Rows of 2d Array: ";
	cin >> m;
	cout<<"Enter Columns of 2d Array: ";
	cin >> n;
	int arr1d[m*n],arr2d[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<"Enter ARRAY2D ["<<i+1<<"]["<<j+1<<"] :"<<endl;
			cin>>arr2d[i][j];
		}	
	}
	cout<<"Copying to 1darray in column major order"<<endl;
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			arr1d[count++]=arr2d[j][i];
		}	
	}
	
	cout<<"printing 1d array"<<endl;
	for(int i=0;i<m*n;i++){
		cout<<arr1d[i]<<endl;
	}
}