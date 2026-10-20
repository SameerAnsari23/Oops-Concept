#include <iostream>
using namespace std;

class Duck {
public:
    virtual void fly() = 0;

    virtual void swim() {
        cout << "Duck is swimming" << endl;
    }
};

class NormalDuck : public Duck {
public:
    void fly() override {
        cout << "Normal Duck is flying" << endl;
    }
};

class RubberDuck : public Duck {
public:
    void fly() override {
        cout << "Rubber Duck cannot fly" << endl;
    }
};

int main() {

    NormalDuck normalDuck;
    RubberDuck rubberDuck;

    cout << "Normal Duck:" << endl;
    normalDuck.fly();
    normalDuck.swim();

    cout << "\nRubber Duck:" << endl;
    rubberDuck.fly();
    rubberDuck.swim();

    return 0;
}