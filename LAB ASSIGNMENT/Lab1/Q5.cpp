#include<iostream>
using namespace std;
void surface_area_of_sphere(int r1,float area){
    area=4*3.142*r1*r1;
    cout<<"The Surface Area of sphere is "<<area<<endl;
}
void volume_of_sphere(int r2,float volume){
    volume=4/3*3.142*r2*r2*r2;
    cout<<"The Volume of sphere is "<<volume<<endl;
}
int main(){
    int Area_sphere,Volume_sphere,r1,r2;
    cout<<"Enter the radius of Surface Area of sphere "<<endl;
    cin>>r1;
    cout<<"Enter the radius of Volume of sphere "<<endl;
    cin>>r2;
    surface_area_of_sphere(r1,Area_sphere);
    volume_of_sphere(r2,Volume_sphere);
    return 0;
}