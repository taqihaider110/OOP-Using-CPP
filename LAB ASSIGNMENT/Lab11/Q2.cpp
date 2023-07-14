#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Stack
{
    vector<char> arr;

public:
    void push(char a)
    {
        arr.push_back(a);
    }
    char pop()
    {
        char temp = *arr.rbegin();
        arr.pop_back();
        return temp;
    }
    char peek()
    {
        return *arr.rbegin();
    }
    void reverse()
    {
        vector<char> temp;
        vector<char> word;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] != ' ')
            {
                word.push_back(arr[i]);
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

        // Reverse the last word
        while (!word.empty())
        {
            temp.push_back(word.back());
            word.pop_back();
        }

        arr = temp;
    }
    void print()
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i];
        }
        cout << endl;
    }
};

int main()
{
    Stack stack;
    char arr[50];
    cout << "Enter sentence: ";
    cin.getline(arr, 50);
    for (int i = 0; i < strlen(arr); i++)
    {
        stack.push(arr[i]);
    }
    stack.print();
    stack.reverse();
    stack.print();
    stack.reverse();
    stack.print();
    return 0;
}