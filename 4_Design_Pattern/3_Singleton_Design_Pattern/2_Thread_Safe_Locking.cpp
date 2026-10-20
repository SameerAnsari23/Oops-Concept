#include<iostream>
#include <mutex>

using namespace std;

class Singleton {
private:
    static Singleton* instance;
    static mutex mtx;

    Singleton() { 
        cout << "Singleton Constructor Called!" << endl; 
    }
 
public:
    static Singleton* getInstance() {
        lock_guard<mutex> lock(mtx); // Lock for thread safety
        if (instance == nullptr) {
            instance = new Singleton();
        }
         return instance;
    }
};
 
// Initialize static members
Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    if (s1 == s2) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
}