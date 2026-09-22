#include <iostream>
using namespace std;


// ==========================================
// Small Interface: Printer
// ==========================================
class Printer {

public:

    virtual void print() = 0;

    virtual ~Printer() {}
};


// ==========================================
// Small Interface: Scanner
// ==========================================
class Scanner {

public:

    virtual void scan() = 0;

    virtual ~Scanner() {}
};


// ==========================================
// Simple Printer
// ==========================================
// SimplePrinter only needs printing functionality.
// It does NOT need to implement scan().
class SimplePrinter : public Printer {

public:

    void print() override {

        cout << "Printing document..."
             << endl;
    }
};


// ==========================================
// Multi-Function Printer
// ==========================================
// This printer can both print and scan.
//
// Therefore, it implements both interfaces.
class MultiFunctionPrinter : public Printer, public Scanner {

public:

    void print() override {

        cout << "Printing document..."
             << endl;
    }


    void scan() override {

        cout << "Scanning document..."
             << endl;
    }
};


// ==========================================
// Main Function
// ==========================================
int main() {

    // Simple printer
    SimplePrinter simplePrinter;

    simplePrinter.print();


    cout << endl;


    // Multi-function printer
    MultiFunctionPrinter multiPrinter;

    multiPrinter.print();
    multiPrinter.scan();


    return 0;
}