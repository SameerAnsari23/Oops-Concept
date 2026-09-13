#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/*
---------------------------------------------------------
CLASS: Student
---------------------------------------------------------
A class is a blueprint or template for creating objects.

Example:
Class = Student (Blueprint)
Object = s1 (Real Student)

The class contains:
1. Data Members (Variables)
2. Member Functions (Methods)
3. Constructors
---------------------------------------------------------
*/

class Student {

    // --------------------------------------------------
    // PRIVATE ACCESS SPECIFIER
    // --------------------------------------------------
    // These variables cannot be accessed directly
    // from outside the class.
    // This provides DATA HIDING (Encapsulation).
    // --------------------------------------------------
private:
    int id;
    string name;
    string dept;

public:

    /*
    --------------------------------------------------
    CONSTRUCTOR
    --------------------------------------------------

    A constructor is a special function:

    1. Name is same as class name.
    2. No return type.
    3. Automatically called when object is created.
    4. Used to initialize object data.

    Example:
    Student s1(1, "Srijan", "CSE");

    This automatically calls:

    Student(1,"Srijan","CSE")
    --------------------------------------------------
    */

    // Member Initializer List
    // Faster and recommended method
    Student(int id, string name, string dept)
        : id(id), name(name), dept(dept)
    {
        cout << "\nConstructor is Running" << endl;

        cout << "Object Created Successfully" << endl;

        cout << "id    --> " << id << endl;
        cout << "name  --> " << name << endl;
        cout << "dept  --> " << dept << endl;
    }

    /*
    --------------------------------------------------
    MEMBER FUNCTION
    --------------------------------------------------
    Displays student details.
    --------------------------------------------------
    */
    void displayStudent() {

        cout << "\nStudent Details" << endl;

        // this-> refers to current object
        cout << "ID   : " << this->id << endl;
        cout << "Name : " << this->name << endl;
        cout << "Dept : " << this->dept << endl;
    }

    /*
    --------------------------------------------------
    UPDATE FUNCTION
    --------------------------------------------------
    Changes student name.
    --------------------------------------------------
    */
    void updateName(string name) {

        cout << "\nUpdating Name..." << endl;

        // this->name means class variable
        // name means function parameter
        this->name = name;

        cout << "Name Updated Successfully" << endl;

        displayStudent();
    }

};


/*
---------------------------------------------------------
MAIN FUNCTION
---------------------------------------------------------
Program execution starts from here.
---------------------------------------------------------
*/

int main() {

    /*
    --------------------------------------------------
    OBJECT CREATION
    --------------------------------------------------

    Syntax:
    ClassName ObjectName(parameters);

    Here:
    Class Name = Student
    Object Name = s1

    Memory is allocated for:
    id
    name
    dept

    Constructor automatically executes.
    --------------------------------------------------
    */

    Student s1(1, "Srijan", "CSE");

    // Display student details
    s1.displayStudent();

    // Update student name
    s1.updateName("Raju");

    return 0;
}