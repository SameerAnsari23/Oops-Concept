#include <iostream>
using namespace std;

class PaymentProcessor {
public:
    void processPayment(string type, double amount) {
        if (type == "credit_card") {
            cout << "Processing Credit Card payment: ₹" << amount << endl;
        }
        else if (type == "debit_card") {
            cout << "Processing Debit Card payment: ₹" << amount << endl;
        }
        else if (type == "upi") {
            cout << "Processing UPI payment: ₹" << amount << endl;
        }
    }
};

int main() {
    PaymentProcessor processor;

    processor.processPayment("credit_card", 1000);

    return 0;
}