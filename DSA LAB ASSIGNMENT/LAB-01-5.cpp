#include<iostream>
using namespace std;
class Array{
	int row;
	int column;
	bool arr[5][5];
	public:
	Array(int r=5,int c=5):row(r),column(c){
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				arr[i][j]=false;
			}	
		}
		arr[0][1]=true;
		arr[1][0]=true;
		arr[1][2]=true;
		arr[2][1]=true;
		arr[2][4]=true;
		arr[3][1]=true;
		arr[3][2]=true;
		arr[4][1]=true;
		arr[4][2]=true;
		arr[4][3]=true;
	}
	void display(){
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	void search(int city1,int city2){
		for(int i=0;i<5;i++){
			if(arr[city1][i]==arr[city2][i] && arr[city2][i]==true && arr[city1][i]==true ){
				cout<<"Common Neighbour of City1 and City2 are index "<<i<<endl;
			}
		}
	}
};

int main(){
	Array cities;
	cities.search(0,2);
	cities.search(1,4);
	cities.display();
}