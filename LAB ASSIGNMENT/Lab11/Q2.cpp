#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
class Dynamic_Stack{
    vector<char> abc;
    public:
    void push(char nm){
        abc.push_back(nm);
    }
    char pop(){
        char cba = *abc.rbegin();
        abc.pop_back();
        return cba;
    }
    char peek(){
        return *abc.rbegin();
    }
    void reverse(){
        vector<char> temp;
        vector<char> word;
        for (int i = 0; i < abc.size(); i++){
            if (abc[i] != ' '){
                word.push_back(abc[i]);
            }
            else
            {
                while (!word.empty())
                {
                    temp.push_back(word.back());
                    word.pop_back();
                }
                temp.push_back(' ');
            }
        }
        while (!word.empty()){
            temp.push_back(word.back());
            word.pop_back();
        }
        abc = temp;
    }
    void print(){
        for (int i = 0; i < abc.size(); i++){
            cout << abc[i];
        }
        cout << endl;
    }
};
int main(){
    Dynamic_Stack s;
    char arr[50];
    cout << "Enter sentence: ";
    cin.getline(arr, 50);
    for (int i = 0; i < strlen(arr); i++)
    {
        s.push(arr[i]);
    }
    // s.print();
    cout<<"Sentence After Reverse:";
    s.reverse();
    s.print();
    s.reverse();
    cout<<"Sentence After Reverse Again:";
    s.print();
    return 0;
}