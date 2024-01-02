#include<iostream>
using namespace std;

class Array2D{
	int** arr;
	int rows,cols;
	public:
		Array2D():arr(NULL),rows(0),cols(0){} //Default Constructor
		Array2D(int r,int c):arr(NULL),rows(r),cols(c){ //Parametrized COnstructor
			arr=new int*[rows];
			for(int i=0;i<rows;i++){
				arr[i]=new int[cols];
			}
		}
		Array2D(Array2D& Obj):arr(NULL),rows(Obj.rows),cols(Obj.cols){ ///Copy Constructor
			arr=new int*[rows];
			for(int i=0;i<rows;i++){
				arr[i]=new int[cols];
			}
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++){
					arr[i][j]=Obj.arr[i][j];
				}
			}
		}
		/*void operator=(Array2D& obj){
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++){
					arr[i][j]=obj.arr[i][j];
				}
			}
		}*/
		Array2D operator+(Array2D& obj){
			Array2D temp(rows,cols);
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++){
					temp.arr[i][j]=arr[i][j]+obj.arr[i][j];
				}
			}
			return temp;
		}
		Array2D operator-(Array2D& obj){
			Array2D temp(rows,cols);
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++){
					temp.arr[i][j]=arr[i][j]-obj.arr[i][j];
				}
			}
			return temp;
		}
		Array2D operator*(Array2D& obj){
			if(cols==obj.rows && rows==obj.rows){
				Array2D temp(rows,obj.cols);
				for(int i=0;i<rows;i++){
					for(int j=0;j<cols;j++){
						temp.arr[i][j]=arr[i][j]*obj.arr[i][j];
					}
				}
				return temp;
			}
			cout<<"Invalid Matrices for multiplication."<<endl;
		}
		int operator()(int r,int c){
			if(r<rows && r>=0 && c<cols && c>=0){
				return arr[r][c];
			}
			cout<<"Index out of bounds. returning 0"<<endl;
			return 0;
		}
		void set(){
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++){
					cin>>arr[i][j];
				}
			}
		}
		void show(){
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++){
					cout<<arr[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		~Array2D(){ //Destructor
			delete arr;
		}
		bool binarySearch(int target) {
 			cout<<"Checking for "<<target<<" via binary search"<<endl;
			int low=0;
 			int high=cols;
  			int i=rows-1;
			while(arr[i][0]>target){
				i--;
			}
  			while (low <= high) {
    			int mid = low + (high - low) / 2;
    			if (arr[i][mid] == target){
    				cout<<"FOUND"<<endl;
    				return true;
				}
    			if (arr[i][mid] < target){
   			 		low = mid + 1;
				}
	    		else{
	    			high = mid - 1;
				}
			}
			cout<<"NOT FOUND"<<endl;
	  		return false;
		}
};
int main(){
	cout<<"-----------------"<<endl;
	int r,c;
	cout<<"Enter rows of 2d array:"<<endl;
	cin>>r;
	cout<<"Enter columns of 2d array:"<<endl;
	cin>>c;
	Array2D obj(r,c);
	
	cout<<"Enter data for "<<r<<"*"<<c<<" array:"<<endl;
	obj.set();
	cout<<"---------"<<endl;
	obj.show();
	cout<<endl<<"Enter Target to find:"<<endl;
	int target;
	cin>>target;
	obj.binarySearch(target);
}