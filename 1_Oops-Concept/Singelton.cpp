#include <iostream>
#include <string>
using namespace std;

/*
    SINGLETON DESIGN PATTERN
    ------------------------
    Problem:
    We want exactly ONE Logger object
    throughout the application.

    Requirements:
        1. Only one object should exist.
        2. Everyone should access that same object.
*/


// ============================================================
// SINGLETON CLASS
// ============================================================

class Logger {

private:

    // --------------------------------------------------------
    // STEP 1: PRIVATE CONSTRUCTOR
    // --------------------------------------------------------
    // Outside code cannot create Logger objects directly.

    Logger() {

        cout << "Logger Object Created!" << endl;
    }


public:

    // --------------------------------------------------------
    // STEP 2: PREVENT COPYING
    // --------------------------------------------------------

    Logger(const Logger&) = delete;

    Logger& operator=(const Logger&) = delete;


    // --------------------------------------------------------
    // STEP 3: GLOBAL ACCESS POINT
    // --------------------------------------------------------

    static Logger& getInstance() {

        // Created only once.
        static Logger instance;

        return instance;
    }


    // --------------------------------------------------------
    // LOGGER FUNCTION
    // --------------------------------------------------------

    void log(string message) {

        cout << "[LOG] "
             << message
             << endl;
    }
};


// ============================================================
// CLIENT
// ============================================================

int main() {

    cout << "===== SINGLETON PATTERN =====\n\n";


    // --------------------------------------------------------
    // First access
    // --------------------------------------------------------

    Logger& logger1 =
        Logger::getInstance();

    logger1.log("Application Started");


    // --------------------------------------------------------
    // Second access
    // --------------------------------------------------------

    Logger& logger2 =
        Logger::getInstance();

    logger2.log("User Logged In");


    // --------------------------------------------------------
    // Third access
    // --------------------------------------------------------

    Logger& logger3 =
        Logger::getInstance();

    logger3.log("Payment Successful");


    // --------------------------------------------------------
    // CHECK WHETHER ALL ARE THE SAME OBJECT
    // --------------------------------------------------------

    cout << "\nChecking addresses:\n";

    cout << "logger1 : "
         << &logger1 << endl;

    cout << "logger2 : "
         << &logger2 << endl;

    cout << "logger3 : "
         << &logger3 << endl;


    if (&logger1 == &logger2 &&
        &logger2 == &logger3) {

        cout << "\nAll three references point "
             << "to the SAME object." << endl;
    }


    return 0;
}