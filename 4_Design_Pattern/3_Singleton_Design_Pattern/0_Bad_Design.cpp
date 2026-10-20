#include <iostream> 
using namespace std;

/*
class Singleton {
    private: 
    Singleton() {
        cout << "Hello This is constructor" << endl;
    }
};

int main () {
    Singleton* s1 = new Singleton();
    Singleton* s2 = new Singleton();
    if (s1 == s2) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
}
*/



class Singleton {
    private: 
    Singleton() {
        cout << "Hello This is constructor" << endl;
    }

    public: 
    static Singleton* getInstance() {
        return new Singleton();
    }
};

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
