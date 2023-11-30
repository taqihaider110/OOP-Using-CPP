#include<iostream>
using namespace std;

string dictionary[]={"hello","rehan","maha","taqi","class","university","section","data","structure","algorithm","sir",
					"madam","word","sentence","biryani","cold","drink","village","book","library","bookshelf","campus",
					"charger","phone","cable","computer","laptop","television",
					"money","alot","large","amount","small","vocabulary","pneumonoultramicroscopicsilicovolcaniosis","goodbye","CGPA","GPA"};

	
string unsorted[38];

void sortdictionary(){   //Sorting due to anagram detection logic
	
	cout<<"DICTIONARY:  Word => SortedWord"<<endl;
	cout<<"__________________________________________"<<endl;
	for(int i=0;i<38;i++){
		unsorted[i]=dictionary[i];
	}
	
	for(int i=0;i<38;i++){ // for array
		//for bubble sort
		int count=0;
		while(dictionary[i][count]!='\0'){
			count++;
		}
		
		for(int j=0;j<count-1;j++){
			for(int k=0;k<count-1-j;k++){
				if(dictionary[i][k]>dictionary[i][k+1]){
					char temp = dictionary[i][k];
					dictionary[i][k] = dictionary[i][k+1];
					dictionary[i][k+1] = temp;
				}
			}
		}
	}
	
	for(int i=0;i<38;i++){
		cout<<unsorted[i]<<" => "<<dictionary[i]<<endl;   //printing to check array.
	}
	cout<<endl<<endl<<endl;
	
}


class node {
	public:
		char data;
		node* next;
		node(char value) {
			data=value;
			next=NULL;
		}
		node(char value,node* nxt) {
			data=value;
			next=nxt;
		}
};


class SLL {  //SLL = Singly Linked List
	node* head=NULL;
	public:
		void insertAttail(char value) {  
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
		void insertAtPos(int posvalue,char value) {
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
		void insertAthead(char value) {
			node* n=new node(value);
			n->next=head;
			head=n;
		}
		void deletion(char value) {
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
		
		string sortlist(){ //Sorting by data not value
			node* temp=head;
			while(temp->next!=NULL){
				node* temp2=head;
				while(temp2->next!=NULL){
					if(temp2->data>temp2->next->data){
						char tempchar = temp2->data;
						temp2->data = temp2->next->data;
						temp2->next->data = tempchar;
					}
					temp2=temp2->next;
				}
				temp=temp->next;
			}
			
			string check="";
			temp=head;
			while(temp->next!=NULL){
				check+=temp->data;
				temp=temp->next;	
			}
			check+=temp->data;
			return check;
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
		
		void FormWord() {
        
        string sortedWord = sortlist();
        	for (int i = 0; i < 38; i++) {
        	    if (sortedWord == dictionary[i]) {
        	        cout << "Found matching word in dictionary: " << unsorted[i] << endl;
        	        formWord(unsorted[i]);
        	        return;
        	    }
        	}
        	cout << "No matching word found in dictionary." << endl;
    	}

    void formWord(string targetWord) {
        node* newHead = NULL;

        for (char ch : targetWord) {   //For each character in targetword  "Computer"
            node* temp = head;
            node* prev = NULL;
            while (temp != NULL && temp->data != ch) { //finding a character that goes into the position
                prev = temp;
                temp = temp->next;
            }

            if (temp == NULL) {   //if char not found then invalid
                cout << "Error: Cannot form the word." << endl;
                return;
            }

            if (prev == NULL) { //checks if character is in 1st position or not
                head = temp->next;
            } else {
                prev->next = temp->next;  //link skips temp
            }
            temp->next = newHead;  //placed at head
            newHead = temp;
        }
        head = newHead;  //Generates word but in reverse due to head logic
        reverse();   //fixes the reversed word generated by formword.
    }		
};


int main(){
	sortdictionary();
	cout<<"------------------------------------------"<<endl;
	cout<<"DICTIONARY above this point\n";
	cout<<"------------------------------------------\n"<<endl;
	SLL word;
	char input=' ';
	while(input!='@'){
		cout<<"Enter character to put in linked list [Enter '@' to end input phase] \n(CASE SENSITIVE! use lower case): ";
		cin>>input;
		if(input!='@'){
			word.insertAttail(input);
		}
	}
	word.display();
	cout<<endl<<"Checking if word can be formed.\n\n"<<endl;
	cout<<endl;
	word.FormWord();
	cout<<endl;
	word.display();
	
}


    