#include <iostream>
#include <stdexcept>
using namespace std;


// ==========================================
// Base / Parent Class
// ==========================================
class Employee {
public:
    virtual int calculateSalary() {
        return 100000;
    }

    virtual int calculateBonus() {
        return 10000;
    }

    virtual ~Employee() {}
};


// ==========================================
// Derived / Child Class
// ==========================================
class PermanentEmployee : public Employee {
public:
    int calculateSalary() override {
        return 200000;
    }

    int calculateBonus() override {
        return 10000;
    }
};

// ==========================================
// Derived / Child Class
// ==========================================
class ContractualEmployee : public Employee {
public:
    int calculateSalary() override {
        return 150000;
    }

    int calculateBonus() override {
        // Contractual employees do not have a bonus
        throw runtime_error("CalculateBonus is not implemented");
    }
};

// ==========================================
// Main Function
// ==========================================
int main() {
    // Base class object
    Employee employee;

    // Derived class objects
    PermanentEmployee pEmployee;
    ContractualEmployee cEmployee;

    // Employee
    cout << employee.calculateSalary() << endl;             // 100000
    cout << employee.calculateBonus() << endl;              // 10000

    // Permanent Employee
    cout << pEmployee.calculateSalary() << endl;            // 200000
    cout << pEmployee.calculateBonus() << endl;             // 10000

    // Contractual Employee
    cout << cEmployee.calculateSalary() << endl;            // 150000

    cout << cEmployee.calculateBonus() << endl;
    // ERROR / Exception
    try {
        cout << cEmployee.calculateBonus() << endl;
    }
    catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }


    return 0;
}