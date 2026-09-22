#include <iostream>
using namespace std;

// Abstraction
class UserRepository {
public:
    virtual void save(string user) = 0;
    virtual ~UserRepository() {}
};


// Low-level implementation
class MySQLRepository: public UserRepository {
public:
    void save(string user) override {
        cout << "Saving " << user << " to MySQL" << endl;
    }
};


// Another implementation
class PostgreSQLRepository: public UserRepository {
public:
    void save(string user) override {
        cout << "Saving " << user << " to PostgreSQL" << endl;
    }
};


// High-level module
class UserService {
private:
    UserRepository& repository;
public:
    UserService(UserRepository& repository) : repository(repository) {}
    void saveUser(string user) {
        repository.save(user);
    }
};


int main() {
    MySQLRepository mysql;
    UserService service(mysql);
    service.saveUser("Rahul");

    return 0;
}