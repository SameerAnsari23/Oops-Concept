#include <iostream>
#include <string>
using namespace std;

/*
    FACTORY DESIGN PATTERN
    -----------------------
    Problem:
    The client should not be responsible for creating
    concrete Payment objects.

    We have:
        Payment
          |
          |-- UPIPayment
          |-- CardPayment
          |-- WalletPayment

    PaymentFactory is responsible for object creation.
*/


// ============================================================
// STEP 1: PRODUCT INTERFACE
// ============================================================

class Payment {
public:

    virtual void pay(double amount) = 0;

    virtual ~Payment() {}
};


// ============================================================
// STEP 2: CONCRETE PRODUCTS
// ============================================================

class UPIPayment : public Payment {

public:

    void pay(double amount) override {

        cout << "Paid Rs. " << amount
             << " using UPI" << endl;
    }
};


class CardPayment : public Payment {

public:

    void pay(double amount) override {

        cout << "Paid Rs. " << amount
             << " using Credit Card" << endl;
    }
};


class WalletPayment : public Payment {

public:

    void pay(double amount) override {

        cout << "Paid Rs. " << amount
             << " using Wallet" << endl;
    }
};


// ============================================================
// STEP 3: FACTORY
// ============================================================

class PaymentFactory {

public:

    static Payment* createPayment(string type) {

        if (type == "upi") {

            return new UPIPayment();
        }

        else if (type == "card") {

            return new CardPayment();
        }

        else if (type == "wallet") {

            return new WalletPayment();
        }

        return nullptr;
    }
};


// ============================================================
// STEP 4: CLIENT
// ============================================================

int main() {

    cout << "===== FACTORY PATTERN =====\n\n";


    // Client does NOT create:
    //
    // new UPIPayment();
    // new CardPayment();
    // new WalletPayment();


    Payment* payment1 =
        PaymentFactory::createPayment("upi");
    // payment1 object hai payment ka but kyunki uppayment inherited hai payment class se toh access kr sakt ahia 
    payment1->pay(500);


    Payment* payment2 =
        PaymentFactory::createPayment("card");

    payment2->pay(1000);


    Payment* payment3 =
        PaymentFactory::createPayment("wallet");

    payment3->pay(750);


    delete payment1;
    delete payment2;
    delete payment3;


    return 0;
}