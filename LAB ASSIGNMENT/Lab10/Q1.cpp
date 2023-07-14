#include<iostream>
using namespace std;

template<class T>
class templatee{
	public:
	T a,b;
		templatee(T a1,T b1){
			a=a1;
			b=b1;
		}
		
		
		void add(){
			T sum;
			sum=a+b;
			cout<<"sum is:"<<sum<<endl;
		}
        void subtract(){
			T subt;
			subt=a-b;
			cout<<"subtraction is:"<<subt<<endl;
		}
	    void divide(){
			T div;
			div=a/b;
			cout<<"division is:"<<div<<endl;
		}
		void multiply(){
			T mult;
			mult=a*b;
			cout<<"multiplication is:"<<mult<<endl;
		}		
};
int main(){
	templatee<int> t1(4,5);
	cout<<"integer datatype operations using templates:"<<endl;
	t1.add();
	t1.subtract();
	t1.divide();
	t1.multiply();
	templatee<float> t2(4.2,5.9);
		cout<<"float datatype operations using templates:"<<endl;
	t2.add();
	t2.divide();
	t2.multiply();
	t2.subtract();
}
