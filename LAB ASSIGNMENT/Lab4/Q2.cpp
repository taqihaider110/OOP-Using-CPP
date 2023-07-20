#include <iostream>
using namespace std;
class DynamicArray{
	private:
		int* array;
		int arraysize;
	public:
		DynamicArray(int arraysize){
			this->arraysize=arraysize;
			array =new int(arraysize);
			for(int i=0;i<arraysize;i++){
				array[i]=0;
			}
		}
		void add(int value){	
			int i=0;
			int* temp=new int[arraysize + 1];
			for(i=0;i<arraysize;i++){
				temp[i]=array[i];
			}
			temp[i]=value;
			delete[] array;
			arraysize++;
			array=temp;
		}
		int size(){
			return arraysize;
		}
};
int main(){
	DynamicArray obj1(3);
	int value;
	int number;
	cout<<"ENTER NUMBER OF VALUES YOU WANT TO ADD ";
	cin>>number;
	int i=0;
	for(i=0;i<number;i++){
		cout<<"ENTER A VALUE ";
		cin>>value;
		obj1.add(value);
		cout<<"CURRENTLY ARRAY SIZE IS: "<<obj1.size()<<endl;
	}
}
