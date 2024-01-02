#include <iostream>
#include <cmath>
using namespace std;
class Vector
{
private:
    double x;
    double y;

public:
    Vector(double a, double b)
    {
        x = a;
        y = b;
    }
    Vector operator+(Vector &next)
    {
        return Vector(x + next.x, y + next.y);
    }

    Vector operator-(Vector &next)
    {
        return Vector(x - next.x, y - next.y);
    }

    Vector operator*(double scalar)
    {
        return Vector(x * scalar, y * scalar);
    }

    Vector operator/(double scalar)
    {
        return Vector(x / scalar, y / scalar);
    }
    double magnitude()
    {
        double mag = sqrt(x * x + y * y);
        return mag;
    }

    void print()
    {
        cout << "(" << x << ", " << y << ")";
    }
};
int main()
{
    Vector v1(1, 5);
    Vector v2(2, 10);

    Vector v3 = v1 + v2;
    cout << "v1 + v2 = ";
    v3.print();
    cout << endl;

    Vector v4 = v1 - v2;
    cout << "v1 - v2 = ";
    v4.print();
    cout << endl;

    Vector v5 = v1 * 3;
    cout << "v1 * 2 = ";
    v5.print();
    cout << endl;

    Vector v6 = v2 / 5;
    cout << "v2 / 2 = ";
    v6.print();
    cout << endl;

    cout << "Magnitude of v1: " << v1.magnitude() << endl;
    cout << "Magnitude of v2: " << v2.magnitude() << endl;
}