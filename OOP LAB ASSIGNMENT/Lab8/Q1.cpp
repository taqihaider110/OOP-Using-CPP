#include <iostream>
using namespace std;
class Vehicle
{
protected:
    string typeOfCar;
    string make;
    string model;
    string color;
    int year;
    float milesDriven;

public:
    Vehicle() {}
    Vehicle(const string &typeOfCar, const string &make, const string &model, const string &color,
            int year, float milesDriven)
    {
        this->typeOfCar = typeOfCar;
        this->make = make;
        this->model = model;
        this->color = color;
        this->year = year;
        this->milesDriven = milesDriven;
    }
};
class GasVehicle : virtual public Vehicle
{
protected:
    float fuelTankSize;

public:
    GasVehicle(const string &typeOfCar, const string &make, const string &model, const string &color, int year, float milesDriven, float fuelTankSize)
        : Vehicle(typeOfCar, make, model, color, year, milesDriven)
    {
        this->fuelTankSize = fuelTankSize;
    }
};
class ElectricVehicle : virtual public Vehicle
{
protected:
    float energyStorage;

public:
    ElectricVehicle(const string &typeOfCar, const string &make, const string &model, const string &color, int year, float milesDriven, float energyStorage) : Vehicle(typeOfCar, make, model, color, year, milesDriven)
    {
        this->energyStorage = energyStorage;
    }
};
class HighPerformance : public GasVehicle
{
protected:
    float horsePower;
    float topSpeed;

public:
    HighPerformance(float horsePower, float topSpeed, const string &typeOfCar, const string &make, const string &model, const string &color, int year, float milesDriven, float fuelTankSize) : GasVehicle(typeOfCar, make, model, color, year, milesDriven, fuelTankSize)
    {
        this->horsePower = horsePower;
        this->topSpeed = topSpeed;
    }
};
class HeavyVehicle : public GasVehicle, public ElectricVehicle
{
protected:
    double maxWeight;
    int numOfWheels;
    int length;

public:
    HeavyVehicle(double maxWeight, int numOfWheels, int length, const string &typeOfCar, const string &make, const string &model, const string &color, int year, float milesDriven, float fuelTankSize,
                 float energyStorage)
        : GasVehicle(typeOfCar, make, model, color, year, milesDriven, fuelTankSize),
          ElectricVehicle(typeOfCar, make, model, color, year, milesDriven, energyStorage),
          Vehicle(typeOfCar, make, model, color, year, milesDriven)
    {
        this->maxWeight = maxWeight;
        this->numOfWheels = numOfWheels;
        this->length = length;
    }
};
class SportsCar : public HighPerformance
{
public:
    string gearbox;
    string driveSystem;
    SportsCar(const string &gearbox, const string &driveSystem, float horsePower, float topSpeed,
              const string &typeOfCar, const string &make, const string &model, const string &color, int year, float milesDriven, float fuelTankSize)
        : HighPerformance(horsePower, topSpeed, typeOfCar, make, model, color, year,
                          milesDriven, fuelTankSize),
          Vehicle(typeOfCar, make, model, color, year, milesDriven)
    {
        this->gearbox = gearbox;
        this->driveSystem = driveSystem;
    }
};
class ConstructionTruck : public HeavyVehicle
{
public:
    string cargo;
    ConstructionTruck(const string &cargo, double maxWeight, int numOfWheels, int length, const string &typeOfCar, const string &make, const string &model, const string &color, int year, float milesDriven, float fuelTankSize, float energyStorage)
        : HeavyVehicle(maxWeight, numOfWheels, length, typeOfCar, make, model, color, year,
                       milesDriven, fuelTankSize, energyStorage),
          Vehicle(typeOfCar, make, model, color, year, milesDriven)
    {
        this->cargo = cargo;
    }
};
class Bus : public HeavyVehicle
{
protected:
    int numOfSeats;

public:
    Bus(int numOfSeats, double maxWeight, int numOfWheels, int length, const string &typeOfCar,
        const string &make, const string &model, const string &color, int year, float milesDriven, float fuelTankSize, float energyStorage)
        : HeavyVehicle(maxWeight, numOfWheels, length, typeOfCar, make, model, color, year,
                       milesDriven, fuelTankSize, energyStorage),
          Vehicle(typeOfCar, make, model, color, year, milesDriven)
    {
        this->numOfSeats = numOfSeats;
    }
    void displayBusDetails()
    {
        cout << "Type of Vehicle: " << typeOfCar << endl
             << "Make: " << make << endl
             << "Model: " << model << endl
             << "Color: " << color << endl
             << "Year: " << year << endl
             << "Miles Driven: " << milesDriven << endl
             << "Fuel Tank Size: " << fuelTankSize << endl
             << "Energy Storage: " << energyStorage << endl
             << "Max Weight: " << maxWeight << endl
             << "Number of Wheels: " << numOfWheels << endl
             << "Number of Seats: " << numOfSeats << endl;
    }
};
int main()
{
    Bus bus(48, 300, 8, 23, "BUS", "Carbon Fibre", "KHAN-BABA", "Purple", 2024, 1500, 65, 10);
    bus.displayBusDetails();
    return 0;
}
