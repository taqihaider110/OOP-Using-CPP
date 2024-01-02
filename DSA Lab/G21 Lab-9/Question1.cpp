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
	if (node == NULL)
		return;
	printInorder(node->left);
	cout << node->data << " ";
	printInorder(node->right);
}
void printPREorder(struct Node* node) {
	if (node == NULL)
		return;
	cout << node->data << " ";
	printPREorder(node->left);
	printPREorder(node->right);
}
void printPOSTorder(struct Node* node) {
	if (node == NULL)
		return;
	printPOSTorder(node->left);
	printPOSTorder(node->right);
	cout << node->data << " ";
}
int main() {
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	cout << "\nPREorder traversal of binary tree is \n";
	printPREorder(root);
	return 0;
}