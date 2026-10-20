#include <iostream>
using namespace std;

class Singleton {
    private: 
    static Singleton* instance;
    Singleton() {
        cout << "Hello This is constructor" << endl;
    }

    public: 
    static Singleton* getInstance() {
        if(instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};
Singleton* Singleton::instance = nullptr;

int main () {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    if (s1 == s2) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
}