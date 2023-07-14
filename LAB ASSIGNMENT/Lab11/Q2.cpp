#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class DynamicStack {
private:
    vector<string> stack;

public:
    void push(const string& element) {
        stack.push_back(element);
    }

    void pop() {
        if (!isEmpty()) {
            stack.pop_back();
        }
    }

    string peek() const {
        if (!isEmpty()) {
            return stack.back();
        }
        return "";
    }

    bool isEmpty() const {
        return stack.empty();
    }

    void reverse() {
        for (string& word : stack) {
            reverse(word.begin(), word.end());
        }
    }
};

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    istringstream iss(sentence);
    string word;

    DynamicStack stack;

    while (iss >> word) {
        stack.push(word);
    }

    stack.reverse();

    cout << "Reversed sentence: ";
    while (!stack.isEmpty()) {
        cout << stack.peek() << " ";
        stack.pop();
    }
    cout << endl;

    return 0;
}
