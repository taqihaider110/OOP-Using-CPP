#include <iostream>
using namespace std;
struct Node {
	int data;
	struct Node *left, *right;
};
Node* newNode(int data) {
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
void printInorder(struct Node* node) {
	if (node == NULL) {
		return;
	}
	printInorder(node->left);
	cout << node->data << " ";
	printInorder(node->right);
}
void printPREorder(struct Node* node) {
	if (node == NULL) {
		return;
	}
	cout << node->data << " ";
	printPREorder(node->left);
	printPREorder(node->right);
}
void printPOSTorder(struct Node* node) {
	if (node == NULL) {
		return;
	}
	printPOSTorder(node->left);
	printPOSTorder(node->right);
	cout << node->data << " ";
}
Node* Insert(Node* root, int value) {
	if (!root) {
		return newNode(value);
	}
	cout<<"Do you want to insert to the left(L) or right(R) of "<<root->data<<" ?\nAnything else will default to LEFT"<<endl;
	char opt;
	cin>>opt;
	if (opt=='R'||opt=='r') {
		root->right = Insert(root->right, value);
	} else {
		root->left = Insert(root->left, value);
	}

	return root;
}

int main() {
	int x;
	struct Node* root = NULL;
	while(x>=0) {
		cout<<"Enter positive integer to put in tree, anything < 0 will end inserting phase of program"<<endl;
		cin>>x;
		while(!cin) {
			fflush(stdin);
			cin.clear();
			cout<<"Error,try again"<<endl;
			cin>>x;
		}
		if(x>=0) {
			root = Insert(root,x);
		}
	}

//	root->left = newNode(2);
//	root->right = newNode(3);
//	root->left->left = newNode(4);
//	root->left->right = newNode(5);

	int n;
	cout<<"What type of traversal you want to do?\n 1:In order 2:Pre order 3:Post order"<<endl;
	cin>>n;
	while(!cin) {
		fflush(stdin);
		cin.clear();
		cout<<"Error,try again"<<endl;
		cin>>n;
	}
	if(n==1) {
		cout << "\nInorder traversal of binary tree is \n";
		printInorder(root);
	} else if(n==2) {
		cout << "\nPREorder traversal of binary tree is \n";
		printPREorder(root);
	} else {
		cout << "\nPOSTorder traversal of binary tree is \n";
		printPOSTorder(root);
	}
	cin>>n;
	return 0;
}