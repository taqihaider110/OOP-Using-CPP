#include<iostream>
#include<fstream>
using namespace std;

class Participant {
    string ID;
    string name;
    float score;
public:
    Participant(string id = "", string n = "", float a = 0) : ID(id), name(n), score(a) {}

    void input() {
        ofstream ob;
        ob.open("participant.txt", ios::app);
        if (ob.is_open()) {
            ob << ID << endl;
            ob << name << endl;
            ob << score << endl;
        }
        ob.close();
    }

    void Output() {
        string search;
        cout << "Enter ID: ";
        cin >> search;
        cin.ignore();  // Ignore the newline character
        ifstream ob1("participant.txt");
        if (ob1.is_open()) {
            string data;
            while (1) {
                getline(ob1, data);
                if (data == search) {
                    cout << "\nFound:" << endl;
                    cout << "ID: " << data << endl;
                    getline(ob1, data);
                    cout << "Name: " << data << endl;
                    getline(ob1, data);
                    cout << "Score: " << data << endl;
                    break;
                }
                if (ob1.eof()) {
                    cout << "Not Found!" << endl;
                    break;
                }
            }

        }
    }

    void Max() {
        float max;
        max = score;
        string id;
        string dataName;
        float dataScore;
        ifstream ob1("participant.txt");
        if (ob1.is_open()) {
            while (1) {
                ob1 >> id;
                ob1 >> dataName;
                ob1 >> dataScore;
                if (dataScore > max) {
                    max = dataScore;
                }
                if (ob1.eof()) {
                    break;
                }
            }
            cout << "So far, the highest score has been: " << max << endl;
        }
        else {
            cout << "Trouble opening the file." << endl;
        }
    }
};

int main() {
    Participant p1("CT-92", "Taqi Haider", 78);
    Participant p2("CT-93", "Ali Murtuza", 87);
    p1.input();
    p1.Output();
    p1.Max();

    return 0;
}
