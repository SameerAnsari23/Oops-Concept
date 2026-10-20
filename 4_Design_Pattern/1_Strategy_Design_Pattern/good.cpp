#include <iostream>
using namespace std;

class FlyBehavior {
public:
    virtual void fly() = 0;
    virtual ~FlyBehavior() {}
};

class NormalFlying : public FlyBehavior {
public:
    void fly() override {
        cout << "Duck is flying normally" << endl;
    }
};

class NoFlying : public FlyBehavior {
public:
    void fly() override {
        cout << "Duck cannot fly" << endl;
    }
};

class FastFlying : public FlyBehavior {
public:
    void fly() override {
        cout << "Duck is flying very fast" << endl;
    }
};

class Duck {
private:
    FlyBehavior* flyBehavior;

public:
    Duck(FlyBehavior* flyBehavior) {
        this->flyBehavior = flyBehavior;
    }

    void fly() {
        flyBehavior->fly();
    }
};

int main() {

    NormalFlying normal;
    NoFlying noFly;
    FastFlying fast;

    Duck duck1(&normal);
    Duck duck2(&noFly);
    Duck duck3(&fast);

    duck1.fly();
    duck2.fly();
    duck3.fly();

    return 0;
}