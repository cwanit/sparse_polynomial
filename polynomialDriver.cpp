#include "polynomial.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    //  Testing Default Constructor
    Polynomial p1;
    cout << "p1 =" << p1 << endl;

    //  Testing changeCoefficient mutator
    p1.changeCoefficient(1, 1);    // implicit convert coef to double. Should not print coef.
    p1.changeCoefficient(4, 4);    // implicit convert coef to double. Should print coef
    p1.changeCoefficient(2.2, 2);  // shold print coef
    p1.changeCoefficient(-3.8, 3); // test negative coef

    //  Testing printing operator overload
    cout << "p1 = " << p1 << endl;

    //  Testing degree getter
    cout << "The highest degree in polynomial p1 is: " << p1.degree() << endl; // should be 4

    //  Testing coefficient getter
    cout << "The coefficient of the 3rd degree is: " << p1.coefficient(3) << endl; // should be -3.8

    p1.changeCoefficient(0, 5); // should do nothing
    cout << "p1 = " << p1 << endl;
    p1.changeCoefficient(0, 3); // should delete power 3
    cout << "p1 = " << p1 << endl;
    p1.changeCoefficient(25.3, 2); // should change coef of power 2
    cout << "p1 = " << p1 << endl;
    p1.changeCoefficient(6.1, 0); // should add a term at the end
    cout << "p1 = " << p1 << endl;
    p1.changeCoefficient(5.2, 0); // should add a term at the end
    cout << "p1 = " << p1 << endl;

    Polynomial p2(p1);
    cout << "p2 = " << p2 << endl;

    Polynomial p3;
    p3.changeCoefficient(3.2, 5);
    p3.changeCoefficient(3, 4);

    p1 -= p3;
    cout << "p1 += p3 is " << p1 << endl;
}
//     //  Testing copy constructor
//     Polynomial p2 = p1;

//     //  Testing arithmatic opearation
//     p2.changeCoefficient(9.5, 2);

//     cout << "p1 = " << p1 << endl;

//     cout << "p2 = " << p2 << endl;

//     Polynomial p3 = p1 + p2; // Addition

//     cout << "<Addition Test> p3 = " << p3 << endl;

//     cout << "Subtraction Tes> p3 = " << (p3 - p2) << endl; // should be same as p1

//     //  Testing insert

//     //  Testing remove

//     //  Testing deconstructor (valgrind memory leak check)
// }

// int main()
// {
//     Polynomial p1;
//     // cout << p1 << endl;
//     p1.changeCoefficient(1, 1);
//     cout << p1 << endl;
// }