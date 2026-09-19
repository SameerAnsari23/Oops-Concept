#include <iostream>
using namespace std;


// Base class
class Employee {
public:

    virtual int calculateSalary() = 0;

    virtual ~Employee() {}
};


// Employee who receives a bonus
class BonusEligibleEmployee : public Employee {
public:

    virtual int calculateBonus() = 0;
};


// Permanent Employee
class PermanentEmployee : public BonusEligibleEmployee {
public:

    int calculateSalary() override {
        return 200000;
    }

    int calculateBonus() override {
        return 10000;
    }
};


// Contractual Employee
class ContractualEmployee : public Employee {
public:

    int calculateSalary() override {
        return 150000;
    }
};


int main() {

    // Permanent Employee
    Employee* permanent = new PermanentEmployee();

    cout << "Permanent Employee Salary: "
         << permanent->calculateSalary() << endl;


    // Contractual Employee
    Employee* contractual = new ContractualEmployee();

    cout << "Contractual Employee Salary: "
         << contractual->calculateSalary() << endl;


    delete permanent;
    delete contractual;

    return 0;
}