#include <iostream>
using namespace std;

#include "Queue.h"
#include "Queue.cpp"



int main() {
	Queue<int> *q =new Queue<int>();
	if(q->IsEmpty())
		cout<<"Queue is currently empty"<<endl;
	q->Put(1);
	q->Put(2);
	q->Put(3);
	while (!q->IsEmpty()) {
		int value=q->Get();
		cout<<value<<endl;
	}
	return 0;
}