#include <iostream>
using namespace std;

// Low-level module
class MySQLRepository {
public:
    void save(string user) {
        cout << "Saving " << user << " to MySQL" << endl;
    }
};


// High-level module
class UserService {
private:
    // Direct dependency on concrete class
    MySQLRepository repository;
public:
    void saveUser(string user) {
        repository.save(user);
    }
};


int main() {
    UserService service;
    service.saveUser("Rahul");

    return 0;
}