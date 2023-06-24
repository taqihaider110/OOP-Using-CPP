#include <iostream>
using namespace std;
 class check {
    int value;
 
public:
    // Constructor function is using here!
    check(int a = 0)
    {
        value = a;
    }
    int getValue() const
    {
        return value;
    }
    
    void setValue(int b) {
        value = b;
    }
};
 
// Code for the Driver...
int main()
{
    check c1(19);
    cout << c1.getValue() << endl;
     
    // const keyword object
      const check c_const(20);
    cout << c_const.getValue() << endl;
   
    c1.setValue(12);
     
    cout << c1.getValue() << endl;
 
}
