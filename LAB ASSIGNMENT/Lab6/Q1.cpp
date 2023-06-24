#include <iostream>

using namespace std;

class Shape {
protected:
    int numberOfSides;
    double area;
public:
    Shape(int sides) {
        numberOfSides = sides;
        area = 0.0;
    }
    
    int getNumberOfSides() {
        return numberOfSides;
    }
    
    double getArea() {
        return area;
    }
    
    void setArea(double newArea) {
        area = newArea;
    }
};

class Rectangle : public Shape {
protected:
    double length;
    double width;
public:
    Rectangle(double len, double wid) : Shape(4) {
        length = len;
        width = wid;
    }
    
    void generateArea() {
        setArea(length * width);
    }
};

class Circle : public Shape {
protected:
    double radius;
public:
    Circle(double rad) : Shape(0) {
        radius = rad;
    }
    
    void generateArea() {
        setArea(3.14159 * radius * radius);
    }
};

class Triangle : public Shape {
protected:
    double height;
    double base;
public:
    Triangle(double ht, double bs) : Shape(3) {
        height = ht;
        base = bs;
    }
    
    void generateArea() {
        setArea(0.5 * height * base);
    }
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}
    
    void checkSides() {
        if (length == width)
            cout << "The square has equal sides." << endl;
        else
            cout << "The square does not have equal sides." << endl;
    }
    
    void generateArea() {
        Rectangle::generateArea();
    }
};

int main() {
    Rectangle rectangle(5.0, 3.0);
    rectangle.generateArea();
    cout << "Rectangle Area: " << rectangle.getArea() << endl;
    
    Circle circle(2.5);
    circle.generateArea();
    cout << "Circle Area: " << circle.getArea() << endl;
    
    Triangle triangle(4.0, 6.0);
    triangle.generateArea();
    cout << "Triangle Area: " << triangle.getArea() << endl;
    
    Square square(4.0);
    square.checkSides();
    square.generateArea();
    cout << "Square Area: " << square.getArea() << endl;
    
    return 0;
}
