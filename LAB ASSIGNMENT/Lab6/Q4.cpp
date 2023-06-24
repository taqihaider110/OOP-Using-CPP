#include<iostream>
using namespace std;

class Person{
	string name,occupation;
	public:
		Person():name("PRSN"),occupation("Unemployed"){}
		Person(string n,string o):name(n),occupation(o){}
		virtual void Draw(){
			cout<<"A person can draw in many ways"<<endl;
		}
};

class Artist:public Person{
	public:
		Artist():Person("ART","Artist"){}
		virtual void Draw(){
			cout<<"An artist can draw with a paintbrush"<<endl;
		}
};

class Gunman:public Person{
	public:
		Gunman():Person("GMN","gunman"){}
		virtual void Draw(){
			cout<<"A gunman draws a gun to shoot"<<endl;
		}
};

int main(){
    Person* arr[3];
    arr[0] = new Person;
    arr[1] = new Artist;
    arr[2] = new Gunman;
    for (int i = 0; i < 3; i++) {
        arr[i]->Draw();
    }
    return 0;
}
