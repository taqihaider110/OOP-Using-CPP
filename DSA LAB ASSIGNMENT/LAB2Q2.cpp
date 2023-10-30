#include<iostream>
using namespace std;

class Person{
        string FirstName;
        string LastName;
        int BirthYear;
        int BirthMonth;
        int BirthDate;

    public:

        Person(string f="Random",string l="Person",int by=0,int bm=0,int bd=0):FirstName(f),LastName(l),BirthYear(by),BirthMonth(bm),BirthDate(bd){}
        Person(int by,int bm, int bd):BirthYear(by),BirthMonth(bm),BirthDate(bd){}
        void display(){
            cout<<FirstName<<endl<<LastName<<endl<<BirthYear<<"/"<<BirthMonth<<"/"<<BirthDate<<endl<<endl;
        }
        int getBY(){
            return BirthYear;
        }
        int getBM(){
            return BirthMonth;
        }
        int getBD(){
            return BirthDate;
        }
        void setBY(int by){
            BirthYear=by;
        }
        void setBM(int bm){
            BirthMonth=bm;
        }
        void setBD(int bd){
            BirthDate=bd;
        }

};

int main(){
    int n,temp;
    cout<<"Enter number of persons:"<<endl;
    cin>>n;
    Person people[n];
    for(int i=0;i<n;i++){
        cout<<"Enter birthyear"<<endl;
        cin>>temp;
		people[i].setBY(temp);
        cout<<"Enter birthmonth"<<endl;
        cin>>temp;
		people[i].setBM(temp);
        cout<<"Enter birthdate"<<endl;
        cin>>temp;
		people[i].setBD(temp);
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        people[i].display();
    }

    int i,j,min_index;
    for(i=0;i<n-1;i++){
        min_index = i;
        for(j=i+1;j<n;j++){
            if((people[j].getBY()<people[min_index].getBY()) ||
            ((people[j].getBM()<people[min_index].getBM())&&(people[j].getBY()==people[min_index].getBY())) || 
            ((people[j].getBD()<people[min_index].getBD())&&(people[j].getBM()==people[min_index].getBM())&&(people[j].getBY()==people[min_index].getBY())))
            {
                min_index=j;
            }    
        }
        if(min_index!=i){
            Person temp;
            temp=people[min_index];
            people[min_index]=people[i];
            people[i]=temp;
        }
    }

    cout<<endl;
    for(int i=0;i<n;i++){
        people[i].display();
    }
}