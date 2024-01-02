#include<iostream>
using namespace std;
class weapons{
    public:
    void weapons_description(){
        cout<<"This is the classification of the weapon:"<<endl;
    }
};
class Hotweapons:public weapons{
        public:
            void hot_weapons_description(){
                cout<<"This is hot weapons which uses gunpowder, or explode."<<endl;
            }
};
class Bombs:public weapons{
    public:
        void bombs_description(){
            cout<<"This is a Bomb that blows up!."<<endl;
        }
};
class NuclearBombs:public weapons{
    public:
        void Nuclear_bombs_description(){
            cout<<"This is a Nuclear bomb that blows up!, and use nuclear fission and fusion."<<endl;
        }
};
int main(){
    Hotweapons b1;
    b1.weapons_description();
    b1.hot_weapons_description();
    Bombs c3;
    c3.weapons_description();
    c3.bombs_description();
    NuclearBombs d4;
    d4.weapons_description();
    d4.Nuclear_bombs_description();
    return 0;
}