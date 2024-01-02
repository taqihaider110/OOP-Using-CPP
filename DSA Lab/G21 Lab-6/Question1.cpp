#include<iostream>
using namespace std;
class Queue { // A class to represent a queue
	private:
		int front=-1, rear=-1, size;
		unsigned capacity; //assuming capacity is the number of items currently in queue.
		int* array;
	public:
		Queue(int siz) { // constructor
			array = new int[siz];
			size=siz;
			for(int i=0;i<size;i++){
				array[i]=0;
			}
			capacity=0;
		}
		void insert(int j) {
			if(!isFull()){
				array[++rear%size]=j;
				if(isEmpty()){
					front=0;
				}
				capacity++;
				cout<<"Value inserted successfully\n";
			}
			else{
				cout<<"Array is Full, returning..."<<endl;
			}
		}
		int remove() {
			if(!isEmpty()){
				int	 temp=array[front];
				front++;
				front = front%size;
					capacity--;
				return temp;
				cout<<"Value removed successfully\n";
			}
			else{
				cout<<"Empty Array, returning..."<<endl;
			}
		}
		int peek() { //equivalent to accessing first element
			return array[front];
		}
		bool isEmpty() {
			return capacity==0;
		}
		bool isFull() {
			return capacity==size;
		}
		int Size() {
			return size;
		}
		
		void display(){
			if(!isEmpty()){
				cout<<"[FRONT]\t";
				for(int i=0;i<capacity;i++){
					cout<<array[(front+i)%size]<<"\t";
				}
				cout<<"[REAR]\nNumber of Items in Queue: "<<capacity<<endl;
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
	Queue q(s);
	do{
		cout<<"\nWhat would you like to do with the Queue?\n1. Enqueue\t2.Dequeue\t3.Peek\t4.Display\n99.EXIT\n[Anything Else Defaults to Display]\n";
		cin>>s;
		if(s==1){
			cout<<"Enter Value to Insert: ";
			cin>>s;
			q.insert(s);
			s=1;
		}
		else if(s==2){
			q.remove();
		}
		else if(s==3){
			cout<<"Value Currently at front : "<<q.peek()<<endl;
		}
		else if(s==4){
			q.display();	
		}
	}while(s!=99);
}