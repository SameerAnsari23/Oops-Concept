


#include<iostream>
#include<bits/stdc++.h>

using namespace std;


/*
=========================================================
                    ENCAPSULATION
=========================================================

Encapsulation means:

    "Wrapping data and the functions that operate on
     that data together inside a class."

More importantly, encapsulation allows us to CONTROL
how the data can be accessed or modified.

Example:

Customer has:

    Data:
        balance

    Functions:
        showBalance()
        addBalance()

We don't want anyone to directly modify balance.

Therefore:

        balance -> PRIVATE

and we provide controlled access through:

        showBalance()
        addBalance()

This is Encapsulation.
*/


class Customer {

    /*
    =====================================================
                    PRIVATE DATA
    =====================================================

    private members cannot be accessed directly from
    outside the class.

    This protects the balance from unwanted changes.
    */

    private:

        int balance;


    /*
    =====================================================
                    PUBLIC FUNCTIONS
    =====================================================

    These functions can be called from outside the class.

    They provide controlled access to private data.
    */

    public:


        /*
        =================================================
                    CONSTRUCTOR
        =================================================

        Constructor initializes the balance.

        We initialize balance to 0 when a Customer
        object is created.
        */

        Customer() {

            balance = 0;

            cout << "Customer object created." << endl;
            cout << "Initial Balance: " << balance << endl;
            cout << endl;
        }


        /*
        =================================================
                    SHOW BALANCE
        =================================================

        This function allows us to READ the private
        balance.

        We cannot do:

            customer.balance

        because balance is private.

        Instead we use:

            customer.showBalance()
        */

        int showBalance() {

            return balance;
        }


        /*
        =================================================
                    ADD BALANCE
        =================================================

        This function allows us to MODIFY the private
        balance.

        Instead of directly changing balance from main(),
        we provide a controlled function.

        Example:

            customer.addBalance(500);

        This will increase the existing balance by 500.
        */

        int addBalance(int amount) {

            balance += amount;

            return balance;
        }
};



int main() {


    /*
    =====================================================
                    OBJECT CREATION
    =====================================================

    Customer is the class.

    c1 is the object.

    When this line executes:

        Customer c1;

    the constructor automatically runs.
    */

    Customer c1;


    /*
    =====================================================
                    ACCESSING BALANCE
    =====================================================

    We cannot directly access balance:

        c1.balance = 500;

    This would give a compilation error because
    balance is PRIVATE.

    Instead, we use the public function:

        addBalance()
    */

    cout << "Adding Rs. 500..." << endl;

    c1.addBalance(500);


    /*
    Now we can see the balance using the public
    showBalance() function.
    */

    cout << "Current Balance: "
         << c1.showBalance()
         << endl;

    cout << endl;


    /*
    =====================================================
                ADDING MORE MONEY
    =====================================================
    */

    cout << "Adding Rs. 1000..." << endl;

    c1.addBalance(1000);


    cout << "Current Balance: "
         << c1.showBalance()
         << endl;


    return 0;
}