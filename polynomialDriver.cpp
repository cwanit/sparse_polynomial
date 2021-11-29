#include "polynomial.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    //  Testing Default Constructor

    cout << "============================================================" << endl;
    cout << "\tTesting Default Constructor" << endl;
    cout << "============================================================" << endl;
    Polynomial p1;
    cout << "p1 = " << p1 << endl;
    cout << endl;

    //  Testing changeCoefficient mutator
    cout << "============================================================" << endl;
    cout << "\tTesting changeCoefficient and ostream overload" << endl;
    cout << "============================================================" << endl;
    p1.changeCoefficient(1, 1);    // implicit convert coef to double. Should not print coef.
    p1.changeCoefficient(4, 5);    // implicit convert coef to double. Should print coef
    p1.changeCoefficient(2.2, 2);  // shold print coef
    p1.changeCoefficient(-3.8, 3); // test negative coef

    //  Testing printing operator overload
    cout << "p1 = " << p1 << endl;
    cout << endl;

    //  Testing degree getter
    cout << "The highest degree in polynomial p1 is: " << p1.degree() << endl; // should be 4
    //  Testing coefficient getter
    cout << "The coefficient of the 3rd degree is: " << p1.coefficient(3) << endl; // should be -3.8
    cout << endl;

    cout << "trying to change a term that doesn't exist, should not change:" << endl;
    p1.changeCoefficient(0, 10); // should do nothing
    cout << "\tp1 = " << p1 << endl;
    cout << endl;

    cout << "trying to delete term with power of 2:" << endl;
    p1.changeCoefficient(0, 2); // should delete power 2
    cout << "\tp1 = " << p1 << endl;
    cout << endl;

    cout << "trying to add term with power of 2:" << endl;
    p1.changeCoefficient(25.3, 2); // should add coef of power 2
    cout << "\tp1 = " << p1 << endl;
    cout << endl;

    cout << "trying to add a term at the end:" << endl;
    p1.changeCoefficient(6.1, 0); // should add a term at the end
    cout << "\tp1 = " << p1 << endl;
    cout << endl;

    cout << "trying to change a term at the end:" << endl;
    p1.changeCoefficient(5.2, 0); // should change a term at the end
    cout << "\tp1 = " << p1 << endl;
    cout << endl;

    cout << "============================================================" << endl;
    cout << "\tTesting copy constructor" << endl;
    cout << "============================================================" << endl;
    cout << "Polynomial p2(p1); p2 should equal p1:" << endl;
    Polynomial p2(p1);
    cout << "\tp1 = " << p1 << endl;
    cout << "\tp2 = " << p2 << endl;
    cout << endl;

    /**
     * equality test cases
     * 1.) different size (p3)
     * 2.) same size, same exact terms (p2)
     * 3.) same size, same power, different coeff (p4)
     * 4.) same size, same coeff, different power (p5)
     */
    cout << "============================================================" << endl;
    cout << "\tTesting boolean comparison operators" << endl;
    cout << "============================================================" << endl;
    Polynomial p3, p4(p1), p5(p1);
    p3.changeCoefficient(3.2, 5);
    p3.changeCoefficient(3, 4);
    p3.changeCoefficient(3.0, 0);

    p4.changeCoefficient(2, 2); // same power different coeff

    p5.changeCoefficient(0, 5);
    p5.changeCoefficient(4, 4);

    cout << "\tp1 = " << p1 << endl;
    cout << "\tp2 = " << p2 << endl;
    cout << "\tp3 = " << p3 << endl;
    cout << "\tp4 = " << p4 << endl;
    cout << "\tp5 = " << p5 << endl;
    cout << endl;
    cout << "case1\tp1 is not equal to p3: " << (p1 != p3 ? "true" : "false") << endl;
    cout << "\tp1 is equal to p3: " << (p1 == p3 ? "true" : "false") << endl;

    cout << "case2\tp1 is not equal to p2: " << (p1 != p2 ? "true" : "false") << endl;
    cout << "\tp1 is equal to p2: " << (p1 == p2 ? "true" : "false") << endl;

    cout << "case3\tp1 is not equal to p4: " << (p1 != p4 ? "true" : "false") << endl;
    cout << "\tp1 is equal to p4: " << (p1 == p4 ? "true" : "false") << endl;

    cout << "case4\tp1 is not equal to p5: " << (p1 != p5 ? "true" : "false") << endl;
    cout << "\tp1 is equal to p5: " << (p1 == p5 ? "true" : "false") << endl;
    cout << endl;

    cout << "============================================================" << endl;
    cout << "\tTesting assignment operator" << endl;
    cout << "============================================================" << endl;
    Polynomial p6, p7;
    cout << "before:" << endl;
    cout << "\tp3 = " << p3 << endl;
    cout << "\tp6 = " << p6 << endl;
    p6 = p3;
    cout << "after p6 = p3: " << endl;
    cout << "\tp3 = " << p3 << endl;
    cout << "\tp6 = " << p6 << endl;
    cout << endl;

    /**
     * + Test
     * 1.) different size (p3)
     * 2.) same size, same exact terms (p2)
     * 3.) same size, same power, different coeff (p4)
     * 4.) same size, same coeff, different power (p5)
     */
    cout << "============================================================" << endl;
    cout << "\tTesting arithmatic + operator" << endl;
    cout << "============================================================" << endl;
    cout << "\tp1 = " << p1 << endl;
    cout << "\tp2 = " << p2 << endl;
    cout << "\tp3 = " << p3 << endl;
    cout << "\tp4 = " << p4 << endl;
    cout << "\tp5 = " << p5 << endl;
    cout << endl;

    p7 = p1 + p3;
    cout << "case1\tp1 + p3 = " << p7 << endl;

    p7 = p1 + p2;
    cout << "case2\tp1 + p2 = " << p7 << endl;

    p7 = p1 + p4;
    cout << "case3\tp1 + p4 = " << p7 << endl;

    p7 = p1 + p5;
    cout << "case4\tp1 + p5 = " << p7 << endl;

    cout << endl;

    /**
     * - Test
     * 1.) different size (p3)
     * 2.) same size, same exact terms (p2)
     * 3.) same size, same power, different coeff (p4)
     * 4.) same size, same coeff, different power (p5)
     */
    cout << "============================================================" << endl;
    cout << "\tTesting arithmatic - operator" << endl;
    cout << "============================================================" << endl;
    cout << "\tp1 = " << p1 << endl;
    cout << "\tp2 = " << p2 << endl;
    cout << "\tp3 = " << p3 << endl;
    cout << "\tp4 = " << p4 << endl;
    cout << "\tp5 = " << p5 << endl;
    cout << endl;

    p7 = p1 - p3;
    cout << "case1\tp1 - p3 = " << p7 << endl;

    p7 = p1 - p2;
    cout << "case2\tp1 - p2 = " << p7 << endl;

    p7 = p1 - p4;
    cout << "case3\tp1 - p4 = " << p7 << endl;

    p7 = p1 - p5;
    cout << "case4\tp1 - p5 = " << p7 << endl;

    cout << endl;
}
