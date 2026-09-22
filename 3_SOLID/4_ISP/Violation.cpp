#include <iostream>
using namespace std;

// Large Interface
class IVehicle {
public:
    virtual void drive() = 0;
    virtual void fly() = 0;

    virtual ~IVehicle() {}
};


// Car is forced to implement BOTH functions
class Car : public IVehicle {
public:
    void drive() override {
        cout << "Drive car" << endl;
    }

    void fly() override {
        // Car cannot fly
        cout << "Car cannot fly" << endl;
    }
};


// FlyingCar actually needs both functions
class FlyingCar : public IVehicle {
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
    car.fly();


    FlyingCar flyingCar;
    flyingCar.drive();
    flyingCar.fly();

    return 0;
}