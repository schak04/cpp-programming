/*
================================= INHERITANCE IN C++ ===================================

Inheritance is a fundamental OOP concept that allows a class (derived/child) to inherit
properties and behaviors from another class (base/parent). This enables code reuse and
establishes an "is-a" relationship between classes.

This file demonstrates:
- Basic inheritance with access specifiers (public, protected, private)
- Multiple inheritance
- Ambiguity resolution
- Diamond problem and virtual base classes
- Function overriding
- Constructor/destructor execution order

Each block below is self-contained. Uncomment the relevant section in `main()` to test.

==========================================================================================
*/

#include <iostream>
#include <string>
using namespace std;

/* ========================================================================================
   BASIC INHERITANCE - Access Specifiers
   ========================================================================================
   
   Access specifiers control member visibility:
   - private:   Only accessible within the class
   - protected: Accessible within class and derived classes
   - public:    Accessible everywhere
   
   Inheritance modes affect how base class members are inherited:
   - public inheritance:    public→public, protected→protected, private→inaccessible
   - protected inheritance: public→protected, protected→protected, private→inaccessible
   - private inheritance:   public→private, protected→private, private→inaccessible
*/

void basicInheritanceExample() {
    class Student {
    private:
        int rollno;
    protected:
        string section;  // Accessible in derived classes
    public:
        void get_rollno() {
            cout << "Enter the roll number: ";
            cin >> rollno;
        }
        void show_rollno() {
            cout << "Roll Number: " << rollno << endl;
        }
    };

    class Result : public Student {  // public inheritance
    private:
        float fees;
    public:
        void get_data() {
            get_rollno();  // Can call base class public methods
            cout << "Enter fees: ";
            cin >> fees;
            cout << "Enter section: ";
            cin >> section;  // Can access protected member
        }
        void display() {
            show_rollno();
            cout << "Fees: " << fees << endl;
            cout << "Section: " << section << endl;
        }
    };

    Result obj1;
    obj1.get_data();
    obj1.display();
    obj1.get_rollno();   // OK - public method
    obj1.show_rollno();  // OK - public method
    // obj1.section = "K23TQ";  // ERROR - protected member not accessible outside class hierarchy
}

void accessSpecifierExample() {
    class Base {
        int a = 10;        // private - not accessible in derived class
    protected:
        int b = 20;        // protected - accessible in derived class
    public:
        int c = 30;        // public - accessible everywhere
    };

    class Child : public Base {
    public:
        void show() {
            // cout << a << endl;  // ERROR - 'a' is private in Base
            cout << "Protected member b: " << b << endl;  // OK - protected accessible
            cout << "Public member c: " << c << endl;     // OK - public accessible
        }
    };

    Child c;
    cout << "Public member c from main: " << c.c << endl;  // OK - public
    c.show();
}

/* ========================================================================================
   MULTIPLE INHERITANCE
   ========================================================================================
   
   A derived class can inherit from multiple base classes simultaneously.
   This allows combining features from different classes.
*/

void multipleInheritanceExample() {
    class M {
    protected:
        int m;
    public:
        void get_m(int x) {
            m = x;
        }
    };

    class N {
    protected:
        int n;
    public:
        void get_n(int y) {
            n = y;
        }
    };

    class P : public M, public N {  // Inherits from both M and N
    public:
        void display() {
            cout << "m = " << m << endl;
            cout << "n = " << n << endl;
            cout << "m * n = " << m * n << endl;
        }
    };

    P p;
    p.get_m(10);
    p.get_n(20);
    p.display();
}

/* ========================================================================================
   AMBIGUITY RESOLUTION
   ========================================================================================
   
   When multiple base classes have members with the same name, ambiguity occurs.
   Resolve using scope resolution operator (::) to specify which base class member to use.
*/

void ambiguityResolutionExample() {
    class A {
    public:
        void show() {
            cout << "I am class A" << endl;
        }
    };

    class B {
    public:
        void show() {
            cout << "I am class B" << endl;
        }
    };

    class C : public A, public B {
        // Both A and B have show() - ambiguity!
    };

    C obj;
    obj.A::show();  // Explicitly call A's show()
    obj.B::show();  // Explicitly call B's show()
    // obj.show();  // ERROR - ambiguous, compiler doesn't know which one
}

/* ========================================================================================
   DIAMOND PROBLEM & VIRTUAL BASE CLASSES
   ========================================================================================
   
   Diamond Problem: When a class inherits from two classes that both inherit from
   the same base class, the derived class ends up with duplicate copies of the base.
   
   Solution: Use virtual inheritance to ensure only one copy of the base class exists.
*/

void diamondProblemExample() {
    class A {
    public:
        virtual void show() {
            cout << "I am class A" << endl;
        }
    };

    class B : virtual public A {};  // Virtual inheritance
    class C : virtual public A {};  // Virtual inheritance
    class D : public B, public C {};  // D inherits from both B and C

    D obj;
    obj.show();  // Works! Only one copy of A exists due to virtual inheritance
}

void virtualBaseClassExample() {
    class A {
    public:
        A() {
            cout << "Constructor of A" << endl;
        }
        void display() {
            cout << "Display A" << endl;
        }
    };

    class B : virtual public A {  // Virtual inheritance prevents duplicate A
    public:
        B() {
            cout << "Constructor of B" << endl;
        }
    };

    class C : virtual public A {  // Virtual inheritance prevents duplicate A
    public:
        C() {
            cout << "Constructor of C" << endl;
        }
    };

    class D : public B, public C {
    public:
        D() {
            cout << "Constructor of D" << endl;
        }
    };

    D d;         // Creating an instance of D
    d.display(); // Calling display function from A (no ambiguity)
}

void virtualBaseClassPracticalExample() {
    class Base {
    protected:
        int x;
    public:
        void get_dataB() {
            cout << "Enter value of x: ";
            cin >> x;
        }
    };

    class Derived1 : public virtual Base {  // Virtual inheritance
    protected:
        int y;
    public:
        void get_dataDB1() {
            cout << "Enter value of y: ";
            cin >> y;
        }
    };

    class Derived2 : public virtual Base {  // Virtual inheritance
    protected:
        int z;
    public:
        void get_dataDB2() {
            cout << "Enter value of z: ";
            cin >> z;
        }
    };

    class Final : public Derived1, public Derived2 {
    public:
        void sum() {
            int result = x + y + z;  // x is shared from Base (no duplication)
            cout << "Result: " << result << endl;
        }
    };

    Final obj;
    obj.get_dataB();
    obj.get_dataDB1();
    obj.get_dataDB2();
    obj.sum();
}

/* ========================================================================================
   FUNCTION OVERRIDING
   ========================================================================================
   
   When a derived class defines a function with the same signature as a base class
   function, it "overrides" the base class function. Use scope resolution to access
   the base class version.
*/

void functionOverridingExample() {
    class A {
    public:
        void show() {
            cout << "I am A" << endl;
        }
    };

    class B : public A {
    public:
        void show() {  // Overrides A::show()
            cout << "I am B" << endl;
        }
    };

    B obj;
    obj.show();        // Calls B::show() - derived class version
    obj.A::show();     // Calls A::show() - base class version using scope resolution
}

/* ========================================================================================
   CONSTRUCTOR & DESTRUCTOR EXECUTION ORDER
   ========================================================================================
   
   Important rules:
   1. Base class constructors execute before derived class constructors
   2. Destructors execute in reverse order (derived → base)
   3. Virtual base classes are constructed first (before non-virtual bases)
   4. If base has parameterized constructor, derived must explicitly call it
   5. Order: Virtual bases → Non-virtual bases (in declaration order) → Derived class
*/

void constructorDestructorOrder1() {
    // Simple inheritance - base constructor called first
    class A {
    public:
        A(int a) {
            cout << "Constructor of A with value: " << a << endl;
        }
        ~A() {
            cout << "Destructor of A" << endl;
        }
    };

    class B : public A {
    public:
        B(int b) : A(b) {  // Must explicitly call base constructor
            cout << "Constructor of B with value: " << b << endl;
        }
        ~B() {
            cout << "Destructor of B" << endl;
        }
    };

    B obj(10);
    // Output order:
    // Constructor of A with value: 10
    // Constructor of B with value: 10
    // Destructor of B
    // Destructor of A
}

void constructorDestructorOrder2() {
    // Virtual base class is constructed first
    class A {
    public:
        A() {
            cout << "Constructor of A" << endl;
        }
        ~A() {
            cout << "Destructor of A" << endl;
        }
    };

    class B {
    public:
        B() {
            cout << "Constructor of B" << endl;
        }
        ~B() {
            cout << "Destructor of B" << endl;
        }
    };

    class C : public A, virtual public B {  // B is virtual, so constructed first
    public:
        C() {
            cout << "Constructor of C" << endl;
        }
        ~C() {
            cout << "Destructor of C" << endl;
        }
    };

    C obj;
    // Output order:
    // Constructor of B (virtual base - first)
    // Constructor of A (non-virtual base)
    // Constructor of C (derived)
    // Destructor of C (reverse order)
    // Destructor of A
    // Destructor of B
}

void constructorDestructorOrder3() {
    // Multi-level inheritance with parameterized constructors
    class A {
        int x, y;
    public:
        A(int r, int s) : x(r), y(s) {
            cout << "Base class A constructor called with values: " << x << " " << y << endl;
        }
        ~A() {
            cout << "Base class A destructor called" << endl;
        }
    };

    class B : public A {
        int l, m;
    public:
        B(int p, int q, int r, int s) : A(r, s), l(p), m(q) {
            cout << "Derived class B constructor called with values: " << l << " " << m << endl;
        }
        ~B() {
            cout << "Derived class B destructor called" << endl;
        }
    };

    class C : public B {
        int n, m;
    public:
        C(int u, int v, int p, int q, int r, int s) : B(p, q, r, s), n(u), m(v) {
            cout << "Derived class C constructor called with values: " << n << " " << m << endl;
        }
        ~C() {
            cout << "Derived class C destructor called" << endl;
        }
    };

    C obj(1, 2, 3, 4, 5, 6);
    // Output order:
    // Base class A constructor called with values: 5 6
    // Derived class B constructor called with values: 3 4
    // Derived class C constructor called with values: 1 2
    // Derived class C destructor called
    // Derived class B destructor called
    // Base class A destructor called
}

/* ========================================================================================
   MAIN FUNCTION
   ========================================================================================
*/

int main() {
    // Uncomment the example you want to run:

    // basicInheritanceExample();
    // accessSpecifierExample();
    // multipleInheritanceExample();
    // ambiguityResolutionExample();
    // diamondProblemExample();
    // virtualBaseClassExample();
    // virtualBaseClassPracticalExample();
    // functionOverridingExample();
    // constructorDestructorOrder1();
    // constructorDestructorOrder2();
    // constructorDestructorOrder3();

    return 0;
}
