    #include<iostream>
using namespace std;

template <class T>
void swap(T* a,T* b){
	T temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int main(){
	int x=7,y=19;
	cout<<"x = "<<x<<endl<<"y = "<<y<<endl;
	swap<int>(&x,&y);
	cout<<"after swap"<<endl;
	cout<<"x = "<<x<<endl<<"y = "<<y<<endl;
}
