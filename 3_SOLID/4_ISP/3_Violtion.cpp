#include <iostream>
using namespace std;

// ==========================================
// Work Interface
// ==========================================
class Workable {
public:
    virtual void work() = 0;
    virtual ~Workable() {}
};


// ==========================================
// Eat Interface
// ==========================================
class Eatable {
public:
    virtual void eat() = 0;
    virtual ~Eatable() {}
};


// ==========================================
// Human
// ==========================================
class Human : public Workable, public Eatable {
public:
    void work() override {
        cout << "Human is working." << endl;
    }

    void eat() override {
        cout << "Human is eating." << endl;
    }
};


// ==========================================
// Robot
// ==========================================
// Robot only needs Workable.
// It is NOT forced to implement eat().
class Robot : public Workable {
public:

    void work() override {
        cout << "Robot is working." << endl;
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