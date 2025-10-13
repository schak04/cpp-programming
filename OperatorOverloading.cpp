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

#include <bits/stdc++.h>

using namespace std;
// Implement the class Box
// l,b,h are integers representing the dimensions of the box

// The class should have the following functions :

// Constructors:
// Box();
// Box(int,int,int);
// Box(Box);

// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

// Overload operator < as specified
// bool operator<(Box& b)

// Overload operator << as specified
// ostream& operator<<(ostream& out, Box& B)

class Box
{
private:
    int l, b, h;

public:
    Box(int length = 0, int breadth = 0, int height = 0)
    {
        l = length;
        b = breadth;
        h = height;
    }
    Box(const Box &B)
    {
        l = B.l;
        b = B.b;
        h = B.h;
    }
    int getLength() const { return this->l; };
    int getBreadth() const { return this->b; };
    int getHeight() const { return this->h; };
    long long CalculateVolume() const
    {
        return static_cast<long long>(l) * b * h;
    }
    bool operator<(const Box &o) const
    {
        if (l < o.l)
            return true;
        if (l == o.l && b < o.b)
            return true;
        if (l == o.l && b == o.b && h < o.h)
            return true;
        else
            return false;
    }
    friend ostream &operator<<(ostream &out, const Box &B)
    {
        out << B.l << " " << B.b << " " << B.h;
        return out;
    }
};

void check2()
{
    int n;
    cin >> n;
    Box temp;
    for (int i = 0; i < n; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            cout << temp << endl;
        }
        if (type == 2)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        if (type == 3)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp)
            {
                cout << "Lesser\n";
            }
            else
            {
                cout << "Greater\n";
            }
        }
        if (type == 4)
        {
            cout << temp.CalculateVolume() << endl;
        }
        if (type == 5)
        {
            Box NewBox(temp);
            cout << NewBox << endl;
        }
    }
}

int main()
{
    check2();
}