#include<iostream>
#include<bits/stdc++.h>

using namespace std;


/*
=========================================================
                    POLYMORPHISM
=========================================================

Polymorphism means:

        "One interface, multiple forms."

Poly = Many
Morph = Forms

In OOP, polymorphism allows the SAME function call
to behave differently depending on the object.

Example:

        Customer
            |
            ├── RegularCustomer
            |
            └── PremiumCustomer

Both customers can have:

        showBenefits()

But the behavior can be different.

RegularCustomer:

        Regular Customer Benefits

PremiumCustomer:

        Premium Customer Benefits


=========================================================
                TYPES OF POLYMORPHISM
=========================================================

1. Compile-Time Polymorphism
   - Function Overloading
   - Operator Overloading

2. Runtime Polymorphism
   - Function Overriding
   - virtual functions

Today we are demonstrating:

        RUNTIME POLYMORPHISM
*/


/*
=========================================================
                    BASE CLASS
=========================================================
*/

class Customer {

    public:

        /*
        =================================================
                    VIRTUAL FUNCTION
        =================================================

        virtual tells C++:

        "If a child class overrides this function,
         call the child's version when the object is
         actually a child object."

        This is the key to runtime polymorphism.
        */

        virtual void showBenefits() {

            cout << "Customer Benefits"
                 << endl;

        }


        /*
        =================================================
                    VIRTUAL DESTRUCTOR
        =================================================

        When using inheritance and virtual functions,
        it is good practice to have a virtual destructor
        in the base class.
        */

        virtual ~Customer() {
        } Company facility company facility
};


/*
=========================================================
                CHILD CLASS 1
=========================================================
*/

class RegularCustomer : public Customer {

    public:

        /*
        =================================================
                    FUNCTION OVERRIDING
        =================================================

        The child class provides its own implementation
        of showBenefits().

        The function has the same name and signature
        as the parent function.
        */

        void showBenefits() override {

            cout << "Regular Customer Benefits:"
                 << endl;

            cout << "- Standard Delivery" << endl;
            cout << "- Regular Discounts" << endl;

        }
};


/*
=========================================================
                CHILD CLASS 2
=========================================================
*/

class PremiumCustomer : public Customer {

    public:

        /*
        =================================================
                    FUNCTION OVERRIDING
        =================================================

        PremiumCustomer also provides its own version
        of showBenefits().
        */

        void showBenefits() override {

            cout << "Premium Customer Benefits:"
                 << endl;

            cout << "- Free Delivery" << endl;
            cout << "- Extra Discounts" << endl;
            cout << "- Priority Support" << endl;

        }
};



int main() {


    /*
    =====================================================
                CREATING OBJECTS
    =====================================================
    */

    RegularCustomer regular;

    PremiumCustomer premium;


    /*
    =====================================================
                NORMAL FUNCTION CALL
    =====================================================

    Here we directly call the functions using objects.

    RegularCustomer object
        ↓
    RegularCustomer::showBenefits()
    */

    cout << "Regular Customer:" << endl;

    regular.showBenefits();

    cout << endl;


    /*
    PremiumCustomer object
        ↓
    PremiumCustomer::showBenefits()
    */

    cout << "Premium Customer:" << endl;

    premium.showBenefits();

    cout << endl;


    /*
    =====================================================
                RUNTIME POLYMORPHISM
    =====================================================

    Now comes the important part.

    We create a BASE CLASS POINTER:

            Customer* customer;

    A Customer pointer can point to an object of
    Customer or any class derived from Customer.
    */


    Customer* customer;


    /*
    -----------------------------------------------------
                POINT TO REGULAR CUSTOMER
    -----------------------------------------------------
    */

    customer = &regular;


    /*
    Even though:

            customer

    is a Customer*,

    the actual object is:

            RegularCustomer

    Because showBenefits() is virtual, C++ calls:

            RegularCustomer::showBenefits()
    */

    cout << "Using Customer Pointer:"
         << endl;

    customer->showBenefits();

    cout << endl;


    /*
    -----------------------------------------------------
                POINT TO PREMIUM CUSTOMER
    -----------------------------------------------------

    Now the SAME pointer points to a different object.
    */

    customer = &premium;


    /*
    The pointer is still:

            Customer*

    But the actual object is:

            PremiumCustomer

    Therefore C++ calls:

            PremiumCustomer::showBenefits()
    */

    customer->showBenefits();


    return 0;
}