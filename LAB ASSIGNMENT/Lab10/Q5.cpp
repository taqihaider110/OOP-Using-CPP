#include <iostream>

using namespace std;

template<class T>    ///REUSING THE QUEUE MADE FOR Q5, but slightly changed for printing functions etc
class AbstractDynamicArray {
public:
  virtual bool isFull() const = 0;
  virtual bool isEmpty() const = 0;
  virtual int size() const = 0;
  virtual T& operator[](int index) = 0;
  virtual ~AbstractDynamicArray() {}
};

template<class T>
class DynamicQueue : public AbstractDynamicArray<T> {
private:
  T* arr;
  int capacity;
  int frontIndex;
  int rearIndex;
  int count;

public:
  DynamicQueue(int capacity) : capacity(capacity), frontIndex(0), rearIndex(-1), count(0) {
    arr = new T[capacity];
  }

  ~DynamicQueue() {
    delete[] arr;
  }

  bool isFull() const override {
    return (count == capacity);
  }

  bool isEmpty() const override {
    return (count == 0);
  }

  int size() const override {
    return count;
  }

  T& operator[](int index) override {
    if (index < 0 || index >= count) {
      throw out_of_range("Invalid index");
    }
    return arr[(frontIndex + index) % capacity];
  }

  T& getFront() {
    if (isEmpty()) {
      throw logic_error("Queue is empty");
    }
    return arr[frontIndex];
  }

  T& getRear() {
    if (isEmpty()) {
      throw logic_error("Queue is empty");
    }
    return arr[rearIndex];
  }

  void enqueue(const T& element) {
    if (isFull()) {
      resize();
    }
    rearIndex = (rearIndex + 1) % capacity;
    arr[rearIndex] = element;
    count++;
    cout << "Job enqueued: " << element << endl;
  }

  void dequeue() {
    if (isEmpty()) {
      throw logic_error("Queue is empty");
    }
    T element = arr[frontIndex];
    frontIndex = (frontIndex + 1) % capacity;
    count--;
    cout << "Printing job: " << element << endl;
    cout << "Job completed: " << element << endl;
  }

  void resize() {
    int newCapacity = capacity * 2;

    T* newArray = new T[newCapacity];
    for (int i = 0; i < count; i++) {
      newArray[i] = arr[(frontIndex + i) % capacity];
    }

    delete[] arr;
    arr = newArray;
    frontIndex = 0;
    rearIndex = count - 1;
    capacity = newCapacity;
  }
};

class PrintShop {
private:
  DynamicQueue<string> jobQueue;

public:
  PrintShop(int capacity) : jobQueue(capacity) {}

  void enqueueJob(const string& job) {
    jobQueue.enqueue(job);
  }

  void processJobs() {
    while (!jobQueue.isEmpty()) {
      jobQueue.dequeue();

      if (!jobQueue.isEmpty()) {
        cout << "Printing next job" << endl << endl;
      }
    }

    cout << "All print jobs completed." << endl;
  }
};

int main() {
  PrintShop printShop(5);

  printShop.enqueueJob("OOP manual print");
  printShop.enqueueJob("LDST rubrics");
  printShop.enqueueJob("FE booklet");
  printShop.enqueueJob("Random photocopy");
  printShop.enqueueJob("Picture Print");
  cout<<endl<<endl;
  printShop.processJobs();

  return 0;
}

