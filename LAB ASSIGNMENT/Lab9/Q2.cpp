#include <iostream>
using namespace std;
class Store {
protected:
    double totalBill;

public:
    Store(double bill) : totalBill(bill) {}
    virtual double calculateFinalBill() = 0;
};
class ImtiazStore : public Store {
public:
    ImtiazStore(double bill) : Store(bill) {}

    double calculateFinalBill(){
        double discount = totalBill * 0.07;
        double finalBill = totalBill - discount;
        return finalBill;
    }
};
class BinHashimStore : public Store {
public:
    BinHashimStore(double bill) : Store(bill) {}

    double calculateFinalBill() {
        double discount = totalBill * 0.05;
        double finalBill = totalBill - discount;
        return finalBill;
    }
};

int main() {
    double totalBill;

    cout << "Enter the total bill amount: ";
    cin >> totalBill;

    Store* imtiazStore = new ImtiazStore(totalBill);
    Store* binHashimStore = new BinHashimStore(totalBill);

    double imtiazFinalBill = imtiazStore->calculateFinalBill();
    double binHashimFinalBill = binHashimStore->calculateFinalBill();

    cout << "Final bill after discount at Imtiaz Store: " << imtiazFinalBill << endl;
    cout << "Final bill after discount at Bin Hashim Store: " << binHashimFinalBill << endl;

    delete imtiazStore;
    delete binHashimStore;

    return 0;
}
