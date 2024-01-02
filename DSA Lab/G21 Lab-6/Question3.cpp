#include<iostream>
using namespace std;
class QueueWithArray { // A class to represent a queue
	private:
		int head=-1, tail=-1, size;
		unsigned curr_items; //assuming curr_items is the number of items currently in queue.
		int* array;
	public:
		QueueWithArray(int s) { // constructor
			array = new int[s];
			size=s;
			for(int i=0;i<size;i++){
				array[i]=0;
			}
			curr_items=0;
		}
		void insert(int j) {
			if(!isFull()){
				array[++tail%size]=j;
				if(isEmpty()){
					head=0;
				}
				curr_items++;
				cout<<"Value inserted successfully\n";
			}
			else{
				cout<<"Array is Full, returning..."<<endl;
			}
		}
		int remove() {
			if(!isEmpty()){
				int	 temp=array[head];
				head++;
				head = head%size;
					curr_items--;
				return temp;
				cout<<"Value removed successfully\n";
			}
			else{
				cout<<"Empty Array, returning..."<<endl;
			}
		}
		int peek() { //equivalent to accessing first element
			return array[head];
		}
		bool isEmpty() {
			return curr_items==0;
		}
		bool isFull() {
			return curr_items==size;
		}
		int Size() {
			return size;
		}
		
		void display(){
			if(!isEmpty()){
				cout<<"[HEAD]\t";
				for(int i=0;i<curr_items;i++){
					cout<<array[(head+i)%size]<<"\t";
				}
				cout<<"[TAIL]\nCurrent Items in Queue: "<<curr_items<<endl;
			}
			else{
				cout<<"Queue is Empty\n";	
			}
		}
};

int main(){
	cout<<"Enter Size of Array to Implement Queue: ";
	int s;
	cin>>s;
	while(s<=0){
		cout<<"Invalid size, please try again: ";
		cin>>s;
	}
	cout<<"\n Creating Queue of size "<<s<<" : \n";
	QueueWithArray MyQueue(s);
	do{
		cout<<"\nWhat would you like to do with the Queue?\n1. Enqueue\t2.Dequeue\t3.Peek\t4.Display\n99.EXIT\n[Anything Else Defaults to Display]\n";
		cin>>s;
		if(s==1){
			cout<<"Enter Value to Insert: ";
			cin>>s;
			MyQueue.insert(s);
			s=1;
		}
		else if(s==2){
			MyQueue.remove();
		}
		else if(s==3){
			cout<<"Value Currently at Head : "<<MyQueue.peek()<<endl;
		}
		else if(s==4){
			MyQueue.display();	
		}
	}while(s!=99);
}