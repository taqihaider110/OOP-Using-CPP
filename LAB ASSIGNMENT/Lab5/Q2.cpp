    #include<iostream>
    #include <cstring>
    using namespace std;
    class Teacher{
        private:
        string Name;
        int Age;
        string Institute;
        public:
        Teacher(string name,int age,string institute):
            Name(name),
            Age(age),
            Institute(institute){}
        
        void set_input(){
            cout<<"Enter name:"<<endl;
            cin>>Name;
            cout<<"Enter age:"<<endl;
            cin>>Age;
            cout<<"Enter Institute:"<<endl;
            cin>>Institute;
            }
        void set_display(){
            cout<<"Following are the details of the teacher:"<<endl;
            cout<<"Name: "<<Name<<endl<<"Age: "<<Age<<endl<<"Institute: "<<Institute<<endl;
            }
    };
    class HumanitiesTeacher:public Teacher{
        public:
        string department;
        string coursename;
        string designation;
        HumanitiesTeacher(string name,int age,string institute):Teacher(name,age,institute){}
        void set_data(){
            cout<<"Enter the Department name:"<<endl;
            cin>>department;
            cout<<"Enter the Course name:"<<endl;
            cin>>coursename;
            cout<<"Enter the Designation:"<<endl;
            cin>>designation;
        }
        void display_data(){
            cout<<"Department name is "<<department<<endl;
            cout<<"Course name is "<<coursename<<endl;
            cout<<"Designation of the teacher is "<<designation<<endl;
        }
    };
    class ScienceTeacher:public Teacher{
        public:
        string department;
        string coursename;
        string designation;
        ScienceTeacher(string name,int age,string institute):Teacher(name,age,institute){}
        void set_data(){
            cout<<"Enter the Department name:"<<endl;
            cin>>department;
            cout<<"Enter the Course name:"<<endl;
            cin>>coursename;
            cout<<"Enter the Designation:"<<endl;
            cin>>designation;
        }
            void display_data(){
            cout<<"Department name is "<<department<<endl;
            cout<<"Course name is "<<coursename<<endl;
            cout<<"Designation of the teacher is "<<designation<<endl;
        }
    };
    class MathsTeacher:public Teacher{
        public:
        string department;
        string coursename;
        string designation;
        MathsTeacher(string name,int age,string institute):Teacher(name,age,institute){}
        void set_data(){
            
            cout<<"Enter the Department name:"<<endl;
            cin>>department;
            cout<<"Enter the Course name:"<<endl;
            cin>>coursename;
            cout<<"Enter the Designation:"<<endl;
            cin>>designation;
        }
            void display_data(){
            cout<<"Department name is :"<<department<<endl;
            cout<<"Course name is :"<<coursename<<endl;
            cout<<"Designation of the teacher is :"<<designation<<endl;
        }
    };
    int main(){
    cout<<"HUMANITIES TEACHER DETAILS:"<<endl;
    HumanitiesTeacher h1("name", 24, "ins");
    h1.set_input();
    h1.set_data();
    h1.set_display();
    h1.display_data();
    cout<<"----------------"<<endl;
    cout<<"SCIENCE TEACHER DETAILS:"<<endl;
    ScienceTeacher s1("name", 24, "ins");
    s1.set_input();
    s1.set_data();
    s1.set_display();
    s1.display_data();
    cout<<"----------------"<<endl;
    cout<<"MATHS TEACHER DETAILS:"<<endl;
    MathsTeacher m1("name", 24, "ins");
    m1.set_input();
    m1.set_data();
    m1.set_display();
    m1.display_data();
    cout<<"----------------"<<endl;
    }