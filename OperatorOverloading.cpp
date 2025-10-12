#include <iostream>
#include <conio.h>
using namespace std;

/*
For suffix, we need to provide the data type in the parameter for it to work.
*/

// class abc {
//     int x, y, z;
//     public:
//     abc(int a, int b, int c):x(a), y(b), z(c) {}
//     void operator - () {
//         x = -x;
//         y = -y;
//         z = -z;
//     }
//     void display() {
//         cout<<x<<" "<<y<<" "<<z<<endl;
//     }
// };

// int main(){
//     abc s(10, -20, 30);
//     cout<<"Before operator overloading: ";
//     s.display();
//     -s;    // calling the operator function
//     cout<<"After operator overloading: ";
//     s.display();
//     return 0;
// }


// class sum {
//     public:
//     int b, a;
//     sum() {
//         b = 50;
//     }
//     void set_data() {
//         cout<<"Enter a: ";
//         cin>>a;
//     }
//     int operator+(sum s1) {
//         return (a+s1.b);
//     }
// };

// int main() {
//     int d;
//     sum s, t;
//     s.set_data();
//     d = s+t;
//     cout<<"Sum = "<<d<<endl;
//     return 0;
// }


// class Complex {
//     public:
//     int r, i;
//     Complex(int a = 0, int b = 0) : r(a), i(b) {}
//     Complex operator+(Complex &c) {
//         Complex temp;
//         temp.r = r + c.r;
//         temp.i = i + c.i;
//         return temp;
//     }
//     void display() {
//         cout<<r<<" + "<<i<<"i"<<endl;
//     }
// };

// int main() {
//     Complex c1(10, 20), c2(20, 30), c3;
//     c3 = c1 + c2;   
//     c3.display();
//     return 0;
// }


// class Complex {
// public:
//     int r, i;

//     Complex(int a, int b) : r(a), i(b) {}

//     friend Complex operator+(Complex c1, Complex c2);

//     void display() {
//         cout << r << " + " << i << "i" << endl;
//     }
// };

// Complex operator+(Complex c1, Complex c2) {
//     Complex temp(0, 0);
//     temp.r = c1.r + c2.r;
//     temp.i = c1.i + c2.i;
//     return temp;
// }

// int main() {
//     Complex c1(10, 20), c2(20, 30), c3(0, 0);
//     c3 = c1 + c2;
//     c3.display();
//     return 0;
// }

/* C++ only allows overloading where the left operand is the class type if it’s a member */

// #include <iostream>
// using namespace std;

// class Box {
// private:
//     int l, b, h; // length, breadth, height

// public:
//     // Constructor
//     Box(int length = 0, int breadth = 0, int height = 0)
//         : l(length), b(breadth), h(height) {}

//     // Overload '<' operator
//     bool operator<(const Box& other) const {
//         if (l < other.l)
//             return true;
//         if (l == other.l && b < other.b)
//             return true;
//         if (l == other.l && b == other.b && h < other.h)
//             return true;
//         return false;
//     }

//     // Overload '<<' operator
//     friend ostream& operator<<(ostream& out, const Box& B) {
//         out << B.l << " " << B.b << " " << B.h;
//         return out;
//     }
// };

// int main() {
//     Box A(2, 3, 4);
//     Box B(2, 3, 5);
//     Box C(3, 1, 1);

//     cout << "Box A: " << A << endl;
//     cout << "Box B: " << B << endl;
//     cout << "Box C: " << C << endl;

//     cout << boolalpha; // print true/false instead of 1/0
//     cout << "\nA < B: " << (A < B) << endl; // true
//     cout << "B < A: " << (B < A) << endl; // false
//     cout << "A < C: " << (A < C) << endl; // true (since 2 < 3)

//     return 0;
// }