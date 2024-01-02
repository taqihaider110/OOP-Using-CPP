# include <iostream>
# include <cstdlib>
using namespace std;
struct nod {
	int info;
	struct nod *l;
	struct nod *r;
}*r;
class BST {
	public://functions declaration
		void search(nod *, int);
		void find(int, nod **, nod **);
		void insert(nod *, nod *);
		void del(int);
		void casea(nod *,nod *);
		void caseb(nod *,nod *);
		void casec(nod *,nod *);
		void show(nod *, int);
		BST() {
			r = NULL;
		}
};
void BST::find(int i, nod **par, nod **loc) {           //function called to find an int i from BST, given 2 node pointer pointers par (parent of i) and loc (location of i) to be assigned
	nod *ptr, *ptrsave;
	if (r == NULL) {
		*loc = NULL;			//sets parent and location to NULL if BST's root (r) is NULL and returns.
		*par = NULL;
		return;
	}
	if (i == r->info) {			//if root contains i, then set loc as root, and it has no parent hence par is NULL
		*loc = r;
		*par = NULL;
		return;
	}
	if (i < r->info)
		ptr = r->l;				//searches i by traversing tree according to comparison, choose first subtree left or right
	else
		ptr = r->r;
	ptrsave = r;
	while (ptr != NULL) {		//loops until end of BST reached	
		if (i == ptr->info) {	//if i found at position (ptr) then parent is stored in par and loc is stored as position (ptr)
			*loc = ptr;
			*par = ptrsave;
			return;
		}
		ptrsave = ptr;			//else position(ptr) is assigned to other variable for next iteration
		if (i < ptr->info)		//choose left/right child by comparison
			ptr = ptr->l;
		else
			ptr = ptr->r;
	}
	*loc = NULL;				//if end of BST reached without finding i the loc set to NULL and par set tp last node visited
	*par = ptrsave;
}
//FIND finds the location of an Integer i and stores its location in a node* value called loc, and also gives its parent's location in node* called par.



void BST::search(nod*root,int data) {		//search function called to find integer data from a specified root in parameter
	int depth = 0;				//depth variable to count how 'deep' a value is from root
	nod *temp = new nod;		//temp root value for traversing
	temp = root;				//initialize temp from root for traversal
	while(temp != NULL) {
		depth++;				//every layer checked is shown as increment in depth
		if(temp->info == data) {	//if data at current layer is wwhat we need to find then output the depth or layer from root it was found
			cout<<"\nData found at depth: "<<depth<<endl;
			return;
		} else if(temp->info > data)	//otherwise continue traversal based on comparisons
			temp = temp->l;
		else
			temp = temp->r;
	}
	cout<<"\n Data not found"<<endl;	//if bst traversed without finding then output data not found/
	return;
}
//search basically find the layers in which data to be found exists, and outputs it upon encountering it.

//Find gives the nlocation of the value to be found and its parent's location
//Search gives the layer of a value to be searched from a starting root node.

void BST::insert(nod *tree, nod *newnode) {
	if (r == NULL) {
		r = new nod;
		r->info = newnode->info;
		r->l= NULL;
		r->r= NULL;
		cout<<"Root Node is Added"<<endl;
		return;
	}
	if (tree->info == newnode->info) {
		cout<<"Element already in the tree"<<endl;
		return;
	}
	if (tree->info > newnode->info) {
		if (tree->l != NULL)
			insert(tree->l, newnode);
		else {
			tree->l= newnode;
			(tree->l)->l = NULL;
			(tree->l)->r= NULL;
			cout<<"Node Added To Left"<<endl;
			return;
		}
	} else {
		if (tree->r != NULL)
			insert(tree->r, newnode)
			else {
				tree->r = newnode;
				(tree->r)->l= NULL;
				(tree->r)->r = NULL;
				cout<<"Node Added To Right"<<endl;
				return;
			}
	}
}
void BST::del(int i) {
	nod *par, *loc;
	if (r == NULL) {
		cout<<"Tree empty"<<endl;
		return;
	}
	find(i, &par, &loc);
	if (loc == NULL) {
		cout<<"Item not present in tree"<<endl;
		return;
	}
	if (loc->l == NULL && loc->r == NULL) {
		casea(par, loc);
		cout<<"item deleted"<<endl;
	}
	if (loc->l!= NULL && loc->r == NULL) {
		caseb(par, loc);
		cout<<"item deleted"<<endl;
	}
	if (loc->l== NULL && loc->r != NULL) {
		caseb(par, loc);
		cout<<"item deleted"<<endl;
	}
	if (loc->l != NULL && loc->r != NULL) {
		casec(par, loc);
		cout<<"item deleted"<<endl;
	}
	free(loc);
}
void BST::casea(nod *par, nod *loc) {
	if (par == NULL) {
		r= NULL;
	} else {
		if (loc == par->l)
			par->l = NULL;
		else
			par->r = NULL;
	}
}
void BST::caseb(nod *par, nod *loc) {
	nod *child;
	if (loc->l!= NULL)
		child = loc->l;
	else
		child = loc->r;
	if (par == NULL)
		r = child;
	else {
		if (loc == par->l)
			par->l = child;
		else
			par->r = child;
	}
}
void BST::casec(nod *par, nod *loc) {
	nod *ptr, *ptrsave, *suc, *parsuc;
	ptrsave = loc;
	ptr = loc->r;
	while (ptr->l!= NULL) {
		ptrsave = ptr;
		ptr = ptr->l;
	}
	suc = ptr;
	parsuc = ptrsave;
	if (suc->l == NULL && suc->r == NULL)
		casea(parsuc, suc);
	else caseb(parsuc, suc);
	if (par == NULL)
		r = suc;
	else {
		if (loc == par->l)
			par->l = suc;
		else
			par->r= suc;
	}
	suc->l = loc->l;
	suc->r= loc->r;
}
//print the tree
void BST::show(nod *ptr, int level) {
	int i;
	if (ptr != NULL) {
		show(ptr->r, level+1);
		cout<<endl;
		if (ptr == r)
			cout<<"Root->: ";
		else {
			for (i = 0; i < level; i++)
				cout<<" ";
		}
		cout<<ptr->info;
		show(ptr->l, level+1);
	}
}

int main() {
	int c, n,item;
	BST bst;
	nod *t;
	while (1) {
		cout<<"1.Insert Element "<<endl;
		cout<<"2.Delete Element "<<endl;
		cout<<"3.Search Element"<<endl;
		cout<<"4.Display the tree"<<endl;
		cout<<"5.Quit"<<endl;
		cout<<"Enter your choice : ";
		cin>>c;
		switch(c) {
			case 1:
				t = new nod;
				cout<<"Enter the number to be inserted: ";
				cin>>t->info;
				bst.insert(r, t);
				break;

			case 2:
				if (r == NULL) {
					cout<<"Tree is empty, nothing to delete"<<endl;
					continue;
				}
				cout<<"Enter the number to be deleted: ";
				cin>>n;
				bst.del(n);
				break;
			case 3:
				cout<<"Search:"<<endl;
				cin>>item;
				bst.search(r,item);
				break;
			case 4:
				cout<<"Display BST:"<<endl;
				bst.show(r,1);
				cout<<endl;
				break;
			case 5:
				exit(1);
			default:
				cout<<"Wrong choice!"<<endl;
		}
	}
}