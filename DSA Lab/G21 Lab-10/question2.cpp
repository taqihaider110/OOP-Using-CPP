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
//		void search(nod *, int);
		void findNsearch(int, nod **, nod **);
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
void BST::findNsearch(int i, nod **par, nod **loc) {           	//function called to find an int i from BST, given 2 node pointer pointers par (parent of i) and loc (location of i) to be assigned
																//Search functionality merged into findNsearch, search now counts from root of entire tree instead of specified subtree
	
	int depth = 0;		//depth counter from search
	nod *ptr, *ptrsave;

	if (r == NULL) {
		*loc = NULL;			//sets parent and location to NULL if BST's root (r) is NULL and returns.
		*par = NULL;
		cout<<"\n Data not found because BST is empty"<<endl;
		return;
	}
	depth++;	//first layer
	if (i == r->info) {			//if root contains i, then set loc as root, and it has no parent hence par is NULL
		*loc = r;
		*par = NULL;
		cout<<"\nData found at depth: "<<depth<<endl;
		return;
	}
	if (i < r->info)
		ptr = r->l;				//searches i by traversing tree according to comparison, choose first subtree left or right
	else
		ptr = r->r;
	ptrsave = r;
	while (ptr != NULL) {		//loops until end of BST reached
		depth++;				//increment of depth per each layer traversed
		if (i == ptr->info) {	//if i found at position (ptr) then parent is stored in par and loc is stored as position (ptr)
			*loc = ptr;
			*par = ptrsave;
			nod*t = *par;
			cout<<"Location of "<<i<<" : "<<*loc<<endl;					//siaplaying loc and par to show find functionality works.
			cout<<"Parent of "<<i<<" : "<<t->info<<" @ "<<*par<<endl;
			cout<<"\nData found at depth: "<<depth<<endl;				//showing depth to show search functionality works.
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
	cout<<"\n Data not found, end of BST reached"<<endl;
}

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
			insert(tree->r, newnode);
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
	findNsearch(i, &par, &loc);
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
		if (ptr != r) {
			for (i = 0; i < level; i++)
				cout<<" ";
		}
		cout<<ptr->info;
		if (ptr==r)
			cout<<"\t<-Root";
		show(ptr->l, level+1);
	}
}

int main() {
	int c, n,item;
	BST bst;
	nod *t;
	nod *a;
	nod *b;
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
				cout<<"Find and Search:"<<endl;
				cin>>item;
				bst.findNsearch(item,&a,&b);
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