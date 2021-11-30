// --------------------------------------- PolynomialDriver.cpp ------------------------------------------------------

// Luke Wanitthananon CSS 501 A

// Creation Date: November 14, 2021

// Date of Last Modification: November 29, 2021

// --------------------------------------------------------------------------------------------------------------------

#include "polynomial.h"
#include <iostream>
using namespace std;

int main()
{
    int testCount = 1;

    //  Testing Default Constructor
    cout << "===================================================================" << endl;
    cout << "\tTest " << testCount << ": Testing Default Constructor" << endl;
    cout << "===================================================================" << endl;
    Polynomial p1, p9, p100;
    cout << "p1 = " << p1 << endl;
    cout << endl;

    //  Testing ostream
    /**
     * Testing Ostream
     * 1. empty polynomial should show as zero
     * 2. negative term should not have "+" in front of it
     * 2.1 term at the highest degree
     * 2.2 term at the lowest degree
     * 2.3 term in the middle
     * 2.4 negative coeff that's not -1
     * 3. term with 1 coef should only show x^n
     * 3.1 term at the highest degree
     * 3.2 term at the lowest degree
     * 3.3 term in the middle
     * 4. term with 1 power should only show x
     * 4.1 term at the highest degree
     * 4.2 term at the lowest degree
     * 4.3 term in the middle
     * 5. term with zero coef should not print
     */
    testCount++;
    cout << "===================================================================" << endl;
    cout << "\tTest " << testCount << ": Testing ostream overload" << endl;
    cout << "===================================================================" << endl;
    cout << "case 1.0: Empty Polynomial" << endl;
    cout << endl;
    cout << "\tp9 = " << p9 << endl;
    cout << endl;

    cout << "case 2.1: Negative at front" << endl;
    cout << endl;
    p9.changeCoefficient(-1, 0);
    cout << "\tp9 = " << p9 << endl;
    cout << endl;

    cout << "case 2.2: Negative at back" << endl;
    cout << endl;
    p9.changeCoefficient(-1, 1);
    cout << "\tp9 = " << p9 << endl;
    cout << endl;

    cout << "case 2.3: Negative in middle" << endl;
    cout << endl;
    p9.changeCoefficient(-1, 3);
    cout << "\tp9 = " << p9 << endl;
    cout << endl;

    cout << "case 2.4: Negative in middle other than -1" << endl;
    cout << endl;
    p9.changeCoefficient(-3.1, 2);
    cout << "\tp9 = " << p9 << endl;
    cout << endl;

    p9 = p100; // clear p9

    cout << "case 3.1: 1 coeff at front" << endl;
    cout << endl;
    p9.changeCoefficient(1, 0);
    cout << "\tp9 = " << p9 << endl;
    cout << endl;

    cout << "case 3.2: 1 coeff at back" << endl;
    cout << endl;
    p9.changeCoefficient(1, 1);
    cout << "\tp9 = " << p9 << endl;
    cout << endl;

    cout << "case 3.3: 1 coeff in middle" << endl;
    cout << endl;
    p9.changeCoefficient(1, 3);
    cout << "\tp9 = " << p9 << endl;
    cout << endl;

    cout << "case 3.4: positive in middle other than +1" << endl;
    cout << endl;
    p9.changeCoefficient(+3.1, 2);
    cout << "\tp9 = " << p9 << endl;
    cout << endl;

    p9 = p100; // clear p9

    cout << "case 4.1: power of 1 at front" << endl;
    cout << endl;
    p9.changeCoefficient(-2.5, 1);
    cout << "\tp9 = " << p9 << endl;
    cout << endl;

    cout << "case 4.2: power of 1 at back" << endl;
    cout << endl;
    p9.changeCoefficient(3, 5);
    cout << "\tp9 = " << p9 << endl;
    cout << endl;

    cout << "case 4.3: power of 1 in middle" << endl;
    cout << endl;
    p9.changeCoefficient(100, 0);
    cout << "\tp9 = " << p9 << endl;
    cout << endl;

    cout << "case 5.0: 5th degree is set to 0 and should not print" << endl;
    cout << endl;
    p9.changeCoefficient(0, 5);
    cout << "\tp9 = " << p9 << endl;
    cout << endl;

    //  Testing changeCoefficient mutator
    testCount++;
    cout << "===================================================================" << endl;
    cout << "\tTest " << testCount << ": Testing changeCoefficient" << endl;
    cout << "===================================================================" << endl;
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
    cout << endl;
    p1.changeCoefficient(0, 10); // should do nothing
    cout << "\tp1 = " << p1 << endl;
    cout << endl;

    cout << "trying to delete term with power of 2:" << endl;
    cout << endl;
    p1.changeCoefficient(0, 2); // should delete power 2
    cout << "\tp1 = " << p1 << endl;
    cout << endl;

    cout << "trying to add term with power of 2:" << endl;
    cout << endl;
    p1.changeCoefficient(25.3, 2); // should add coef of power 2
    cout << "\tp1 = " << p1 << endl;
    cout << endl;

    cout << "trying to add a term at the end:" << endl;
    cout << endl;
    p1.changeCoefficient(6.1, 0); // should add a term at the end
    cout << "\tp1 = " << p1 << endl;
    cout << endl;

    cout << "trying to change a term at the end:" << endl;
    cout << endl;
    p1.changeCoefficient(5.2, 0); // should change a term at the end
    cout << "\tp1 = " << p1 << endl;
    cout << endl;

    testCount++;
    cout << "===================================================================" << endl;
    cout << "\tTest " << testCount << ": Testing copy constructor" << endl;
    cout << "===================================================================" << endl;
    cout << "Polynomial p2(p1); p2 should equal p1:" << endl;
    cout << endl;
    Polynomial p2(p1);
    cout << "\tp1 = " << p1 << endl;
    cout << "\tp2 = " << p2 << endl;
    p1.changeCoefficient(-1, 10); // changing p1 should not change p2
    cout << endl;
    cout << "Ran p1.changeCoefficient(-1, 10). p2 should not change:" << endl;
    cout << endl;
    cout << "\tp1 = " << p1 << endl;
    cout << "\tp2 = " << p2 << endl;
    p1.changeCoefficient(0, 10); // changing p1 back for other tests
    cout << endl;

    /**
     * equality test cases
     * 1.) different size (p3)
     * 2.) same size, same exact terms (p2)
     * 3.) same size, same power, different coeff (p4)
     * 4.) same size, same coeff, different power (p5)
     */
    testCount++;
    cout << "===================================================================" << endl;
    cout << "\tTest " << testCount << ": Testing boolean comparison operators" << endl;
    cout << "===================================================================" << endl;
    Polynomial p3, p4(p1), p5(p1);

    // different size polynomial
    p3.changeCoefficient(3.2, 5);
    p3.changeCoefficient(3, 4);
    p3.changeCoefficient(3.0, 0);

    // same size, same power, different coeff
    p4.changeCoefficient(2, 2);

    // same size, same coeff, different power
    p5.changeCoefficient(0, 5);
    p5.changeCoefficient(4, 4);

    cout << "\tp1 = " << p1 << endl;
    cout << "\tp2 = " << p2 << endl;
    cout << "\tp3 = " << p3 << endl;
    cout << "\tp4 = " << p4 << endl;
    cout << "\tp5 = " << p5 << endl;
    cout << endl;
    cout << "case 1\tp1 is not equal to p3: " << (p1 != p3 ? "true" : "false") << endl;
    cout << "\tp1 is equal to p3: " << (p1 == p3 ? "true" : "false") << endl;
    cout << endl;

    cout << "case 2\tp1 is not equal to p2: " << (p1 != p2 ? "true" : "false") << endl;
    cout << "\tp1 is equal to p2: " << (p1 == p2 ? "true" : "false") << endl;
    cout << endl;

    cout << "case 3\tp1 is not equal to p4: " << (p1 != p4 ? "true" : "false") << endl;
    cout << "\tp1 is equal to p4: " << (p1 == p4 ? "true" : "false") << endl;
    cout << endl;

    cout << "case 4\tp1 is not equal to p5: " << (p1 != p5 ? "true" : "false") << endl;
    cout << "\tp1 is equal to p5: " << (p1 == p5 ? "true" : "false") << endl;
    cout << endl;

    testCount++;
    cout << "===================================================================" << endl;
    cout << "\tTest " << testCount << ": Testing assignment operator" << endl;
    cout << "===================================================================" << endl;
    Polynomial p6, p7;
    cout << "before:" << endl;
    cout << "\tp3 = " << p3 << endl;
    cout << "\tp6 = " << p6 << endl;
    cout << endl;
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
    testCount++;
    cout << "===================================================================" << endl;
    cout << "\tTest " << testCount << ": Testing arithmatic + operator and +=" << endl;
    cout << "===================================================================" << endl;
    cout << "\tp1 = " << p1 << endl;
    cout << "\tp2 = " << p2 << endl;
    cout << "\tp3 = " << p3 << endl;
    cout << "\tp4 = " << p4 << endl;
    cout << "\tp5 = " << p5 << endl;
    cout << endl;

    p7 = p1 + p3;
    cout << "case 1\tp1 + p3 = " << p7 << endl;

    p7 = p1 + p2;
    cout << "case 2\tp1 + p2 = " << p7 << endl;

    p7 = p1 + p4;
    cout << "case 3\tp1 + p4 = " << p7 << endl;

    p7 = p1 + p5;
    cout << "case 4\tp1 + p5 = " << p7 << endl;

    cout << endl;

    /**
     * - Test
     * 1.) different size (p3)
     * 2.) same size, same exact terms (p2)
     * 3.) same size, same power, different coeff (p4)
     * 4.) same size, same coeff, different power (p5)
     */
    testCount++;
    cout << "===================================================================" << endl;
    cout << "\tTest " << testCount << ": Testing arithmatic - operator" << endl;
    cout << "===================================================================" << endl;
    cout << "\tp1 = " << p1 << endl;
    cout << "\tp2 = " << p2 << endl;
    cout << "\tp3 = " << p3 << endl;
    cout << "\tp4 = " << p4 << endl;
    cout << "\tp5 = " << p5 << endl;
    cout << endl;

    p7 = p1 - p3;
    cout << "case 1\tp1 - p3 = " << p7 << endl;

    p7 = p1 - p2;
    cout << "case 2\tp1 - p2 = " << p7 << endl;

    p7 = p1 - p4;
    cout << "case 3\tp1 - p4 = " << p7 << endl;

    p7 = p1 - p5;
    cout << "case 4\tp1 - p5 = " << p7 << endl;

    cout << endl;
}
