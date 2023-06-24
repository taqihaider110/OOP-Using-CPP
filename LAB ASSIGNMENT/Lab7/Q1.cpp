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
				for(int j=0;j<cols;j++){
					arr[i][j]=0;
				}
			}
		}
		Array2D(Array2D& Obj):arr(NULL),rows(Obj.rows),cols(Obj.cols){ ///Copy Constructor
			arr=new int*[rows];
			for(int i=0;i<rows;i++){
				arr[i]=new int[cols];
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
			Array2D temp(rows,cols);
			if(cols==obj.rows && rows==obj.rows){   //Performs Matrix Multiplication of 2 matrices.
				for(int k=0;k<rows;k++){
					for(int i=0;i<rows;i++){
						for(int j=0;j<cols;j++){
							temp.arr[k][i]+=arr[k][j]*obj.arr[j][i];
						}
					}
				}
				return temp;
			}
			cout<<"Invalid Matrices for multiplication. returning empty object"<<endl;
			return temp;
		}
		Array2D operator*(int x){ //Scalar Multiplication
			Array2D temp(rows,cols);
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++){
					temp.arr[i][j]=x*arr[i][j];
				}
			}
			return temp;
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
};

int main(){
	Array2D obj1(2,2),obj2(2,2),obj3(2,2);
	cout<<"Enter data for 2*2 array 1:"<<endl;
	obj1.set();
	cout<<"Enter data for 2*2 array 2:"<<endl;
	obj2.set();
	cout<<"-----------------"<<endl;
	int i,j;
	cout<<"Enter Row and Column to search in Array 1:"<<endl;
	cin>>i>>j;
	int x = obj1(i,j);
	cout<<"Result of Overloaded () operator for indexing: "<<x<<endl;
	cout<<"-----------------"<<endl;
	cout<<"2d Array 1 :"<<endl;
	obj1.show();
	cout<<"2d Array 2:"<<endl;
	obj2.show();
	cout<<"-----------------"<<endl;
	cout<<"Result of Overloaded + operator (Array1+Array2) : "<<endl;
	obj3=(obj1+obj2);
	obj3.show();
	cout<<"-----------------"<<endl;
	cout<<"Result of Overloaded - operator (Array1-Array2): "<<endl;
	obj3=(obj1-obj2);
	obj3.show();
	cout<<"-----------------"<<endl;
	cout<<"Result of Overloaded * operator (Array1*Array2): "<<endl;
	obj3=(obj1*obj2);
	obj3.show();
	cout<<"-----------------"<<endl;
	cout<<"Enter Scalar multiple to multiply Array 1 with:"<<endl;
	int n;
	cin>>n;
	cout<<"Result of Overloaded * operator scalar multiple (Array1*int): "<<endl;
	obj3=obj1*n;
	obj3.show();
	cout<<"-----------------"<<endl;
	cout<<"Result of Copy Constructor Array4(Array1) : "<<endl;
	Array2D obj4(obj1);
	obj4.show();	
	cout<<"-----------------"<<endl;
}
