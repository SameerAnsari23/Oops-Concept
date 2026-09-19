#include<iostream>
#include<bits/stdc++.h>

using namespace std;


/*
=========================================================
                    INHERITANCE
=========================================================

Inheritance is an OOP concept where one class can
acquire the properties and functions of another class.

The existing class is called:

        Parent / Base / Super class

The new class is called:

        Child / Derived / Sub class


Example:

        Customer
           |
           ↓
      PremiumCustomer


PremiumCustomer will inherit the properties and
functions of Customer.
*/


/*
=========================================================
                    BASE CLASS
=========================================================
*/

class Customer {

    /*
    =====================================================
                    PROTECTED DATA
    =====================================================

    protected members:

    - Can be accessed inside this class.
    - Can also be accessed inside derived classes.
    - Cannot be directly accessed from main().

    We use protected here so that the child class
    PremiumCustomer can access balance.
    */

    protected:

        int balance;


    public:


        /*
        =================================================
                    CONSTRUCTOR
        =================================================
        */

        Customer() {

            balance = 0;

            cout << "Customer Constructor Called"
                 << endl;
        }


        /*
        =================================================
                    ADD BALANCE
        =================================================
        */

        void addBalance(int amount) {

            balance += amount;

            cout << "Amount Added: "
                 << amount
                 << endl;
        }


        /*
        =================================================
                    SHOW BALANCE
        =================================================
        */

        void showBalance() {

            cout << "Balance: "
                 << balance
                 << endl;
        }
};


/*
=========================================================
                DERIVED / CHILD CLASS
=========================================================

PremiumCustomer inherits Customer.

Syntax:

        class Child : public Parent

Here:

        Child  = PremiumCustomer
        Parent = Customer
*/

class PremiumCustomer : public Customer {


    public:


        /*
        =================================================
                    PREMIUM FUNCTION
        =================================================

        This function belongs to PremiumCustomer.

        It does NOT belong to Customer.

        Therefore, this is additional functionality
        provided by the child class.
        */

        void showPremiumBenefits() {

            cout << "Premium Customer Benefits:"
                 << endl;

            cout << "- Free Delivery" << endl;
            cout << "- Extra Discounts" << endl;
            cout << "- Priority Support" << endl;

        }


        /*
        =================================================
                    USE INHERITED DATA
        =================================================

        balance belongs to Customer.

        But because balance is protected,
        PremiumCustomer can access it.

        This is one of the benefits of inheritance.
        */

        void showPremiumBalance() {

            cout << "Premium Customer Balance: "
                 << balance
                 << endl;
        }
};



int main() {


    /*
    =====================================================
                    BASE CLASS OBJECT
    =====================================================

    Creating a normal Customer object.

    Customer = Base class
    c1       = Object
    */

    Customer c1;


    c1.addBalance(500);

    c1.showBalance();

    cout << endl;


    /*
    =====================================================
                DERIVED CLASS OBJECT
    =====================================================

    Creating PremiumCustomer object.

    PremiumCustomer inherits from Customer.

    Therefore, the PremiumCustomer object can use
    functions inherited from Customer.
    */

    PremiumCustomer p1;


    /*
    =====================================================
                INHERITED FUNCTION
    =====================================================

    addBalance() belongs to Customer.

    But PremiumCustomer inherited it.

    Therefore, we can call:

        p1.addBalance()

    even though addBalance() is not written again
    inside PremiumCustomer.
    */

    p1.addBalance(1000);


    /*
    showBalance() is also inherited from Customer.
    */

    p1.showBalance();


    /*
    =====================================================
                CHILD CLASS FUNCTION
    =====================================================

    showPremiumBenefits() belongs specifically to
    PremiumCustomer.
    */

    p1.showPremiumBenefits();


    /*
    PremiumCustomer can also access its inherited
    balance through its own function.
    */

    p1.showPremiumBalance();


    return 0;
}