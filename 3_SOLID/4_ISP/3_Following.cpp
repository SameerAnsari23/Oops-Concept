#include <iostream>
using namespace std;

// ==========================================
// Workable Interface
// ==========================================
class Workable {
public:
    virtual void work() = 0;
    virtual ~Workable() {}
};


// ==========================================
// Eatable Interface
// ==========================================
class Eatable {
public:
    virtual void eat() = 0;
    virtual ~Eatable() {}
};


// ==========================================
// Human
// ==========================================
// Human can both work and eat.
// Therefore, Human implements both interfaces.
class Human : public Workable,  public Eatable {
public:
    void work() override {
        cout << "Human working" << endl;
    }
    void eat() override {
        cout << "Human eating" << endl;
    }
};


// ==========================================
// Robot
// ==========================================
// Robot can work but does not eat.
//
// Therefore, Robot only implements Workable.
// It is NOT forced to implement Eatable.
class Robot : public Workable {
public:
    void work() override {
        cout << "Robot working" << endl;
    }
};

// ==========================================
// Main
// ==========================================
int main() {
    Human human;
    human.work();
    human.eat();

    cout << endl;

    Robot robot;
    robot.work();

    return 0;
}