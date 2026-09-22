#include <iostream>
using namespace std;


// ==========================================
// Large Interface
// ==========================================
class Machine {
public:
    virtual void print() = 0;
    virtual void scan() = 0;
    virtual void fax() = 0;
    virtual void staple() = 0;

    virtual ~Machine() {}
};


// ==========================================
// Simple Printer
// ==========================================
class SimplePrinter : public Machine {
public:
    void print() override {
        cout << "Printing..." << endl;
    }
    void scan() override {
        // Not supported
        cout << "Scanning not supported." << endl;
    }
    void fax() override {
        // Not supported
        cout << "Faxing not supported." << endl;
    }
    void staple() override {
        // Not supported
        cout << "Stapling not supported." << endl;
    }
};


// ==========================================
// Multi-Function Printer
// ==========================================
class MultiFunctionPrinter : public Machine {
public:
    void print() override {
        cout << "Printing..." << endl;
    }
    void scan() override {
        cout << "Scanning..." << endl;
    }
    void fax() override {
        cout << "Faxing..." << endl;
    }
    void staple() override {
        cout << "Stapling..." << endl;
    }
};


// ==========================================
// Main Function
// ==========================================
int main() {

    // Simple printer
    SimplePrinter simplePrinter;

    simplePrinter.print();
    simplePrinter.scan();
    simplePrinter.fax();
    simplePrinter.staple();


    cout << endl;


    // Multi-function printer
    MultiFunctionPrinter multiPrinter;

    multiPrinter.print();
    multiPrinter.scan();
    multiPrinter.fax();
    multiPrinter.staple();


    return 0;
}