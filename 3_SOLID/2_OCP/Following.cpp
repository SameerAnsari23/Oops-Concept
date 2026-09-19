#include <iostream>
using namespace std;

// Abstraction
class Payment {
public:
    virtual void pay(double amount) = 0;
    virtual ~Payment() {}
};

// Extension 1
class CreditCardPayment : public Payment {
public:
    void pay(double amount) override {
        cout << "Credit Card payment: ₹" << amount << endl;
    }
};

// Extension 2
class UPIPayment : public Payment {
public:
    void pay(double amount) override {
        cout << "UPI payment: ₹" << amount << endl;
    }
};

// Extension 3
class PayPalPayment : public Payment {
public:
    void pay(double amount) override {
        cout << "PayPal payment: ₹" << amount << endl;
    }
};

// Existing class
class PaymentProcessor {
public:
    void process(Payment& payment, double amount) {
        payment.pay(amount);
    }
};


int main() {
    PaymentProcessor processor;
    CreditCardPayment creditCard;
    UPIPayment upi;
    PayPalPayment paypal;

    processor.process(creditCard, 1000);
    processor.process(upi, 2000);
    processor.process(paypal, 3000);

    return 0;
}