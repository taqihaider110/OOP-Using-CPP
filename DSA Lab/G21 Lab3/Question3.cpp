#include<iostream>
using namespace std;

class node {
	public:
		int data;
		node* next;
		node(int value) {
			data=value;
			next=NULL;
		}
		node(int value,node* nxt) {
			data=value;
			next=nxt;
		}
};


class SLL {  //SLL = Singly Linked List made in task 1
		node* head=NULL;
	public:
		void insertAttail(int value) {
			node* n=new node(value);
			if(head==NULL) {  //Check if Linked List Empty.
				head=n;
				return;
			}
			node* temp=head;
			while(temp->next!=NULL) {
				temp=temp->next;
			}
			temp->next=n;
		}
		void insertAtPos(int posvalue,int value) {
			int count=0;
			node* temp=head;
			while(temp->next!=NULL&&count<posvalue-1) {
				temp=temp->next;
				count++;
			}
			node* n=new node(value,temp->next);
			temp->next=n;
		}
		void display() {
			node* temp=head;
			cout<<"[HEAD] ";
			while(temp!=NULL) {
				cout<<temp->data<<"| "<<temp->next<<" -> ";
				temp=temp->next;
			}
			cout<<"NULL [TAIL]"<<endl;
		}
		void insertAthead(int value) {
			node* n=new node(value);
			n->next=head;
			head=n;
		}
		void deletion(int value) {
			if(head==NULL) {
				return;
			}
			node* temp=head;
			while(temp->next->data!=value ) {
				temp=temp->next;
			}
			node* todelete=temp->next;
			temp->next=temp->next->next;

			delete todelete;
		}
		void deleteAthead() {
			if(head==NULL) {
				return;
			}
			node* todelete=head;
			head=head->next;
			delete todelete;
		}
		void deleteAtPos(int posvalue) {
			if(head==NULL) {
				return;
			}
			int count=0;
			node* temp=head;
			while(temp->next!=NULL && count<posvalue-1) {
				temp=temp->next;
			}
			node* todelete=temp->next;
			temp->next=temp->next->next;

			delete todelete;

		}
		void deleteAttail() {
			if(head==NULL) { //If linked list empty.
				return;
			}
			node* temp=head;
			if(head->next==NULL) { //If linked list has 1 item only.
				head=NULL;
				delete temp;
			}
			while(temp->next->next!=NULL) {
				temp=temp->next;
			}
			delete temp->next;
			temp->next=NULL;
		}

		void sortlist() {  //sorting by swapping values
			node* temp=head;
			while(temp->next!=NULL) {
				node* temp2=head;
				while(temp2->next!=NULL) {
					if(temp2->data>temp2->next->data) {
						char tempchar = temp2->data;
						temp2->data = temp2->next->data;
						temp2->next->data = tempchar;
					}
					temp2=temp2->next;
				}
				temp=temp->next;
			}
		}

		void reverse() {
			node* prev=NULL;
			node* after=NULL;
			while(head!=NULL) {
				after=head->next;
				head->next=prev;
				prev=head;
				head=after;
			}
			head=prev;
		}

		void duplicates() {
			int* items = new int[100]; 		// Assuming a maximum of 100 unique items
			int* itemcount = new int[100];
			int size = 0;

			node* temp = head;

			while(temp != NULL) {
				bool duplicate = false;
				for(int i = 0; i < size; i++) {
					if(temp->data == items[i]) {
						duplicate = true;
						itemcount[i]++;
						break;
					}
				}
				if(!duplicate) {
					items[size] = temp->data;
					itemcount[size] = 1;
					size++;
				}
				temp = temp->next;
			}
			cout<<"Unique Items: "<<size<<endl; 
			for(int i = 0; i < size; i++) {
				cout<<"Data: "<<items[i]<<", Count :"<<itemcount[i]<<endl;
			}

			delete[] items;
			delete[] itemcount;

		}

};

int main() {
	SLL list;
	float input=0;
	while(input!=0.5) {
		cout<<"Enter integer to put in linked list [Enter 0.5 to end input phase]: ";
		cin>>input;
		if(input!=0.5) {
			list.insertAthead((int)input);
		}
	}
	cout<<"\n\n";
	list.display();
	char option;
	cout<<"\n\n\nDo you want to...  \n'R'\tReverse the Linked List.\n'S'\tSort the Linked List.\n'D'\tFind Duplicates in Linked List?\n";
	cin>>option;
	if(option=='R'||option=='r'){
		cout<<"Reversing the Linked List."<<endl;
		list.sortlist();
		list.display();
	}
	else if(option=='S'||option=='s'){
		cout<<"Sorting the Linked List."<<endl;
		list.sortlist();
		list.display();
	}
	else if(option=='D'||option=='d'){
		cout<<"Finding Duplicates: "<<endl;
		list.duplicates();
	}
	else{
		cout<<"Invalid Input. defaulting to Sort."<<endl;
		list.sortlist();
		list.display();
	}
}