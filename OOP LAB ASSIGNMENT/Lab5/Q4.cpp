#include <iostream>
#include <string>
using namespace std;

class Item {
protected:
    string name;
    int quantity;

public:
    Item(string name, int quantity)
        : name(name), quantity(quantity) {}

    virtual double calculatePrice() = 0;

    string getName() {
        return name;
    }

    int getQuantity() {
        return quantity;
    }
};

class BakedGoods : public Item {
public:
    BakedGoods(string name, int quantity)
        : Item(name, quantity) {}

    double calculatePrice() {
        return quantity * getPrice() * (1 - getDiscount());
    }

    virtual double getPrice() = 0;

    virtual double getDiscount() = 0;
};

class Cakes : public BakedGoods {
public:
    Cakes(string name, int quantity)
        : BakedGoods(name, quantity) {}

    double getPrice() {
        return 600;
    }

    double getDiscount() {
        return 0.1;
    }
};

class Bread : public BakedGoods {
public:
    Bread(string name, int quantity)
        : BakedGoods(name, quantity) {}

    double getPrice() {
        return 200;
    }

    double getDiscount() {
        return 0.1;
    }
};

class Drinks : public Item {
public:
    Drinks(string name, int quantity)
        : Item(name, quantity) {}

    double calculatePrice() {
        return quantity * getPrice() * (1 - getDiscount());
    }

    double getPrice() {
        return 100;
    }

    double getDiscount() {
        return 0.05;
    }
};

int main() {
    string name;
    int quantity;

    cout << "Enter the details of the items purchased:" << endl;

    cout << "Baked Goods - Cakes" << endl;
    cout << "Name: ";
    cin >> name;
    cout << "Quantity: ";
    cin >> quantity;
    Cakes cakes(name, quantity);

    cout << "Baked Goods - Bread" << endl;
    cout << "Name: ";
    cin >> name;
    cout << "Quantity: ";
    cin >> quantity;
    Bread bread(name, quantity);

    cout << "Drinks" << endl;
    cout << "Name: ";
    cin >> name;
    cout << "Quantity: ";
    cin >> quantity;
    Drinks drinks(name, quantity);

    cout << "\n--- Bill Calculation ---" << endl;
    cout << "Item\t\tQuantity\tPrice" << endl;
    cout << "---------------------------------" << endl;
    cout << cakes.getName() << "\t\t" << cakes.getQuantity() << "\t\t" << cakes.calculatePrice() << endl;
    cout << bread.getName() << "\t\t" << bread.getQuantity() << "\t\t" << bread.calculatePrice() << endl;
    cout << drinks.getName() << "\t\t" << drinks.getQuantity() << "\t\t" << drinks.calculatePrice() << endl;

    double totalBill = cakes.calculatePrice() + bread.calculatePrice() + drinks.calculatePrice();
    cout << "---------------------------------" << endl;
    cout << "Total Bill: " << totalBill << endl;

    return 0;
}
