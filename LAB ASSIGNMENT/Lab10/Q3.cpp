#include<iostream>
using namespace std;
template <class T>
class mycontainer{
	T element;
	public:
		mycontainer(T e){
			element=e;
			cout<<"element before increase:"<<element<<endl;
		
        }
    
		
		void increase(){
			element++;
	        cout<<"element after increasing:"<<element<<endl;
		}
};
template<>
class mycontainer <char>{
	char element;
	public:
		mycontainer(char e){
			element=e;
			cout<<"character before increase:"<<element<<endl;
		}
		void uppercase(){
			if(element>='a'&& element<='z'){
				element+='A'-'a';
				cout<<"character  after  increase:"<<element<<endl;
			}
		} 
};
int main(){
   mycontainer <int> c(19);
   c.increase();
   mycontainer <char> c1('e');
   c1.uppercase();
}
