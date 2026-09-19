#include <iostream>
using namespace std;


// Interface 1
class IDrive {
public:
    virtual void drive() = 0;

    virtual ~IDrive() {}
};


// Interface 2
class IFly {
public:
    virtual void fly() = 0;

    virtual ~IFly() {}
};


// Car implements only IDrive
class Car : public IDrive {
public:
    void drive() override {
        cout << "Drive car" << endl;
    }
};


// FlyingCar implements both interfaces
class FlyingCar : public IDrive, public IFly {
public:
    void drive() override {
        cout << "Drive car" << endl;
    }

    void fly() override {
        cout << "Fly car" << endl;
    }
};


int main() {
    Car car;
    car.drive();

    FlyingCar flyingCar;
    flyingCar.drive();
    flyingCar.fly();

    return 0;
}