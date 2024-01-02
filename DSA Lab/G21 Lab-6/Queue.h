#ifndef QUEUE_H
#define QUEUE_H

template<class T> class node {
	public:
		T data;
		node<T>* next;
		node(T x) {
			data=x;
			next=NULL;
		}
		node(T x, node<T>* nxt) {
			data=x;
			next=nxt;
		}
};

template<class DT> class Queue {
	private:
//include private variables according to the underlying data structure public:
		node<DT>* head=NULL;
		node<DT>* tail=NULL;
		int size;
		int curr_items=0;
	public:
//contructor Queue();
		Queue(int s=5) {
			size = s;
		}
//puts element at the rear end of the Queue if it is not full. Must be O(1) void Put(DT element);
		void Put(DT element) {
			if(!IsFull()) {
				node<DT>* n = new node<DT>(element);
				if(IsEmpty()) {
					head=n;
				}
				else{
					tail->next=n;
				}
				tail=n;
				curr_items++;
				cout<<"Value inserted successfully\n";
			} else {
				cout<<"Array is Full, returning..."<<endl;
			}
		}
//if queue not empty then delete the element at front of the Queue. Must be O(1) DT Get();
		DT Get() {
			if(!IsEmpty()) {
				DT temp=head->data;
				node<DT>* todlt=head;
				head=head->next;
				delete todlt;
				cout<<"Value removed successfully\n";
				curr_items--;
				return temp;
			} else {
				cout<<"Empty Array, returning..."<<endl;
			}
		}
//return true if the Queue is empty and false if it is not bool IsEmpty();
		bool IsEmpty() {
			return curr_items==0;
		}
//return true if the Queue is full and false if it is not bool IsFull();
		bool IsFull() {
			return curr_items==size;
		}

};

#endif

