#include<iostream>
#include<cstring>
using namespace std;

class Vehicle{
	protected:
		int carID;
		string brand,model;
	public:
		Vehicle():carID(0),brand(""),model(""){}
		Vehicle(int i,string b,string m):carID(i),brand(b),model(m){}
		virtual void rent()=0;
		virtual bool isAvailable()=0;
		virtual void makeAvailable()=0;
		friend class RentalSystem;
};

class Car:public Vehicle{
	bool availability = true;
	public:
		Car():Vehicle(){}
		Car(int i,string b,string m):Vehicle(i,b,m){}
		bool isAvailable(){
			return availability;
		}
		void makeAvailable(){
			availability=true;
		}
		void rent(){
			cout<<"CarID :"<<carID<<endl<<"Brand: "<<brand<<endl<<"Model: "<<model<<endl;
			cout<<"This Vehicle was Rented Succesfully."<<endl;
			availability=false;
		}
};

class RentalSystem{
	public:
		virtual void rentVehicle(Vehicle& obj)=0;
		virtual void returnVehicle(Vehicle& obj)=0;
};

class Customer:public RentalSystem{
	public:
		void rentVehicle(Vehicle& obj){
			if(obj.isAvailable()){
				obj.rent();
			}
			else{
				cout<<"Vehicle is already rented."<<endl;	
			}
		}
		void returnVehicle(Vehicle& obj){
			if(!obj.isAvailable()){
				cout<<"Vehicle was already returned."<<endl;
			}
			else{
				obj.makeAvailable();
				cout<<"Vehicle was succesfully returned."<<endl;
			}
		}
};

int main(){
	Vehicle* Cars[2];
	Cars[0]= new Car(100,"Toyota","VIGO");
	Cars[1]= new Car(101,"Honda","Mark-X");
	Customer Taqi_Haider;
	Taqi_Haider.rentVehicle(*Cars[0]);
	Taqi_Haider.rentVehicle(*Cars[1]);
	Taqi_Haider.rentVehicle(*Cars[0]);
	Taqi_Haider.returnVehicle(*Cars[1]);
}
