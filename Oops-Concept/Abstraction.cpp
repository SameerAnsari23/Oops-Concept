#include<iostream>
#include<bits/stdc++.h>

using namespace std;


/*
=========================================================
                    ABSTRACTION
=========================================================

Abstraction means:

    "Showing only the essential details and hiding
     the implementation details."

Real-world example:

    When we use an ATM:

        We see:
            - Withdraw Money
            - Deposit Money
            - Check Balance

        We DON'T need to know:
            - How the bank server works
            - How the transaction is processed
            - How the database is updated


In C++, abstraction can be achieved using:

    1. Abstract Classes
    2. Pure Virtual Functions


=========================================================
                ABSTRACT CLASS
=========================================================

A class containing at least one PURE VIRTUAL FUNCTION
is called an ABSTRACT CLASS.

An abstract class cannot be used to create objects.

Example:

    Customer c1;   ❌ NOT ALLOWED

But we can create objects of classes that inherit
from Customer.

    RegularCustomer r1;   ✅
    PremiumCustomer p1;   ✅
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
                PURE VIRTUAL FUNCTION
        =================================================

        Syntax:

            virtual returnType function() = 0;

        Here:

            virtual
                ↓
            Enables runtime polymorphism

            = 0
                ↓
            Makes this function PURE VIRTUAL

        We are saying:

            "Every type of Customer MUST have a
             showBenefits() function.

             But Customer itself does not decide
             how it should work."

        The implementation will be provided by
        the child classes.
        */

        virtual void showBenefits() = 0;


        /*
        =================================================
                    COMMON FUNCTION
        =================================================

        This function has an implementation.

        Every child class can directly use it.
        */

        void showCustomerMessage() {

            cout << "Welcome Customer!" << endl;
        }


        /*
        =================================================
                    VIRTUAL DESTRUCTOR
        =================================================

        Good practice when working with inheritance
        and polymorphism.
        */

        virtual ~Customer() {
        }
};



/*
=========================================================
                REGULAR CUSTOMER
=========================================================
*/

class RegularCustomer : public Customer {

    public:


        /*
        =================================================
                IMPLEMENTATION OF ABSTRACT FUNCTION
        =================================================

        Customer said:

            Every Customer must implement
            showBenefits()

        RegularCustomer provides its implementation.
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
                PREMIUM CUSTOMER
=========================================================
*/

class PremiumCustomer : public Customer {

    public:


        /*
        =================================================
                IMPLEMENTATION OF ABSTRACT FUNCTION
        =================================================

        PremiumCustomer provides its own implementation
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
            ABSTRACT CLASS OBJECT
    =====================================================

    We CANNOT create an object of Customer.

        Customer c1;

    This will give a compilation error.

    Why?

    Because Customer contains a pure virtual function:

        virtual void showBenefits() = 0;

    Customer is therefore an ABSTRACT CLASS.
    */


    // Customer c1;     // ❌ ERROR


    /*
    =====================================================
                CHILD CLASS OBJECT
    =====================================================

    We CAN create objects of child classes because
    they provide implementations of showBenefits().
    */

    RegularCustomer regular;

    PremiumCustomer premium;


    /*
    =====================================================
                USING REGULAR CUSTOMER
    =====================================================
    */

    cout << "Regular Customer:" << endl;

    regular.showCustomerMessage();

    regular.showBenefits();

    cout << endl;


    /*
    =====================================================
                USING PREMIUM CUSTOMER
    =====================================================
    */

    cout << "Premium Customer:" << endl;

    premium.showCustomerMessage();

    premium.showBenefits();


    return 0;
}