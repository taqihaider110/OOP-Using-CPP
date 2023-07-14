#include<iostream>
#include<cstdlib>
using namespace std;
template<class T>
class DynamicArray{
protected:
 T* Array;
 int cap;
 int size;
public:
 DynamicArray(int c = 10){
 cap = c;
 size = 0;
 Array = new T[cap];
 }
 int getArraySize()const{
 return size;
}
int getArrayCapacity()const{
 return cap;
 }
bool isEmpty( )const{
return size == 0;
}
virtual void resize() = 0;
virtual ~DynamicArray(){
delete[] Array;
}
};
template <typename T>
class DynamicQueue : public DynamicArray<T>{
private:
 int front;
 int rear;
public:
 DynamicQueue(int c = 10):DynamicArray<T>(c){
 front=-1;
rear=-1;
}
 bool isFull() const {
return this->size == this->cap;
}
void resize(){
 T* temp = new T[this->cap * 2];
 for (int i = 0; i < this->size; i++) {
 temp[i] = this->Array[(this->front + i) % this->cap];
 }
 delete[] this->Array;
 this->Array = temp;
 this->front = 0;
 this->rear = this->size - 1;
 this->cap *= 2;
 }
 T Front() const {
 if (this->isEmpty()) {
 cout << "Queue is empty." << endl;
 exit(1);
 }
 return this->Array[this->front];
 }
 T Rear() const {
 if (DynamicArray<T>::isEmpty()) {
 cout << "Queue is empty." << endl;
 exit(1);
 }
 return this->Array[rear];
 }
 void enqueue(const T& val){
 if (isFull()) {
 resize();
 }
 rear = (rear + 1) % this->cap;
 this->Array[rear] = val;
 if (front == -1) {
 front = rear;
 }
 this->size++;
 }
 void dequeue() {
 if (this->isEmpty()) {
 cout << "Cannot Dequeue as Queue is empty." << endl;
 return;
 }
 if (front == rear) {
 front = -1;
 rear = -1;
 } else {
 front = (front + 1) % this->cap;
 }
 this->size--;
 }

 ~DynamicQueue(){}
};
int main() {
 DynamicQueue<int> A(5);
 A.enqueue(17);
 cout << "size of the Queue is: " << A.getArraySize() << endl;
 cout << "Front element of the Queue is : " << A.Front() << endl;
 A.enqueue(69);
 A.enqueue(36);
 A.enqueue(42);
 A.enqueue(17);
 cout << "size of the Queue adding more elements : " << A.getArraySize() <<
endl;
 cout << "All elements: " << endl;
 while (!A.isEmpty()) {
 cout << A.Front();
 A.dequeue();
 cout << " ";
 }
 cout << endl;

 cout << "size after dequeue: " << A.getArraySize() << endl;
 cout << "Accessing the elements: "<< endl;
 cout << "Front element after dequeue: " << A.Front() << endl;
 return 0;
}
