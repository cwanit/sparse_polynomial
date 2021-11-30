// ------------------------------------------------ Polynomial.cpp ------------------------------------------------------

// Luke Wanitthananon CSS 501 A

// Creation Date: November 14, 2021

// Date of Last Modification: November 29, 2021

// --------------------------------------------------------------------------------------------------------------------

#include "polynomial.h"
using namespace std;

/**
 * @brief A default constructor for Polynomial object which
 * initialize size to zero and head term to zero
 */
Polynomial::Polynomial()
    : size(0), head(new Term)
{
    init(); // initialize default value for head
}

/**
 * @brief A copy constructor for Polynomaial object which provides
 * a deep copy of another polynomial.
 * @param p A Polynomial to copy from.
 * @post This Polynomial contains the exact same terms as p.
 */
Polynomial::Polynomial(const Polynomial &p)
    : size(0), head(new Term)
{
    init(); // initialize default value for head

    if (p.size > 0) // only copy if the polynomial is not empty
    {
        copyAnotherPolynomial(p);
    }
}

/**
 * @brief Destroy the Polynomial object
 * @post All terms are removed from heap
 */
Polynomial::~Polynomial()
{
    clearAllTerms();
    // clear head
    delete head;
    head = nullptr;
}

// pre: head is declared
/**
 * @brief Initialize the dummy head of the Polynomial
 * to default value
 * @return true when successfully executed
 * @post dummy head term is set to all zero and point at itself
 */
bool Polynomial::init()
{
    head->coeff = 0.0;
    head->power = 0;
    head->prev = head;
    head->next = head;
    return true;
}

/**
 * @brief Create new terms in heap, attach the new terms to this
 * dummy head, and copy the values over from another Polynomial p
 *
 * @param p A Polynomial to copy from
 * @return true when successfully executed
 * @pre dummy head is declared and initialized
 * @post dummy head is attached with a new chain of terms copied from p
 */
bool Polynomial::copyAnotherPolynomial(const Polynomial &p)
{

    Term *currentPtr = p.head->next; // pointer at the first term to copy
    while (size < p.size)
    {
        changeCoefficient(currentPtr->coeff, currentPtr->power);
        currentPtr = currentPtr->next;
    }
    currentPtr = nullptr;
    return true;
}

/**
 * @brief Remove all terms in Polynomial except for the dummy head
 *
 * @return true when successfully executed
 * @post Polynomial object is removed of all terms except for dummy head
 */

bool Polynomial::clearAllTerms()
{
    Term *currentPtr = head->next; // set to first term

    // remove all terms
    while (size > 0)
    {
        currentPtr = currentPtr->next; // step to the next term in chain
        remove(currentPtr->prev);      // remove the previous term in chain
    }                                  // at the end of loop currentPtr should be back to head

    currentPtr = nullptr;
    return true;
}

/**
 * @brief Addition of Polynomials: current object + parameter
 *
 * @param p Another Polynomial to add to current object
 * @return A new Polynomial as result of addition
 */
Polynomial Polynomial::operator+(const Polynomial &p) const
{
    Polynomial result = *this; // make a copy of myself
    result += p;               // use += to add to the copy
    return result;
}

/**
 * @brief Subtraction of Polynomials: current object - parameter
 *
 * @param p Another Polynomial to subtract from current object
 * @return A new Polynomial as result of subtraction
 */
Polynomial Polynomial::operator-(const Polynomial &p) const
{
    Polynomial result = *this; // make a copy of myself
    result -= p;               // use -= to subtract from the copy
    return result;
}

/**
 * @brief Equality comparison between two Polynomial obejcts
 *
 * @param p Another Polynomial to compare with this one
 * @return true if both objects are the same size and contain
 * the exact same terms, otherwise false.
 */
bool Polynomial::operator==(const Polynomial &p) const
{
    if (p.size != size) // not equal if size is not the same
    {
        return false;
    }
    else // step thru each term, if either coef or power is not the same return false
    {
        Term *anotherPolyPtr = p.head->next; // point to the first term in p
        Term *currentPtr = head->next;       // point to the first time in this polynomial
        while (currentPtr != head)
        {
            if ((currentPtr->coeff != anotherPolyPtr->coeff) ||
                (currentPtr->power != anotherPolyPtr->power))
            {
                return false;
            }
            anotherPolyPtr = anotherPolyPtr->next;
            currentPtr = currentPtr->next;
        }
        anotherPolyPtr = nullptr;
        currentPtr = nullptr;
    }
    return true; // if pass both tests then they are equal
}

/**
 * @brief Inequality comparison between two Polynomial obejcts
 *
 * @param p Another Polynomial to compare with this one
 * @return false if both objects are the same size and contain
 * the exact same terms, otherwise true.
 */
bool Polynomial::operator!=(const Polynomial &p) const
{
    return !(*this == p);
}

/**
 * @brief Assignment operator. Provide a deep copy by removing
 * all the terms in the object and attach a new terms chain
 * copied from p. This method does nothing if the Polynomial
 * assigned is equal to this current Polynomial
 *
 * @param p Another Polynomial to copy from
 * @post This Polynomial object contains the exact same terms
 * as Polynomial p assigned.
 */
Polynomial &Polynomial::operator=(const Polynomial &p)
{
    if (*this != p)
    {
        clearAllTerms();          // clear the current chain
        copyAnotherPolynomial(p); // replace the current chain with items copied from p
    }
    return *this;
}

/**
 * @brief Overloaded operator +=: current object = current object + parameter.
 * Addition of coefficient is performed only when the power match.
 * If power doesn't exist, a new term will be created for that power.
 *
 * @param p  A Polynomial to add to current Polynomial.
 * @post Coefficient in each term of Polynomial p is added to coefficient in
 * current object.
 */
Polynomial &Polynomial::operator+=(const Polynomial &p)
{
    if (p.size > 0)
    {
        Term *anotherPolyPtr = p.head->next; // point to the first term of p
        double currentCoeff = 0.0;
        while (anotherPolyPtr != p.head)
        {
            currentCoeff = coefficient(anotherPolyPtr->power); // find current coefficient

            // add coefficient from p
            changeCoefficient(currentCoeff + anotherPolyPtr->coeff, anotherPolyPtr->power);
            anotherPolyPtr = anotherPolyPtr->next;
        }
        anotherPolyPtr = nullptr;
    }
    return *this;
}

/**
 * @brief Overloaded operator -=: current object = current object - parameter.
 * Addition of coefficient is performed only when the power match.
 * If power doesn't exist, a new term will be created for that power.
 *
 * @param p  A Polynomial to subtract from current Polynomial.
 * @post Coefficient in each term of Polynomial p is subtracted from
 * coefficient in current object.
 */
Polynomial &Polynomial::operator-=(const Polynomial &p)
{
    if (p.size > 0)
    {
        Term *anotherPolyPtr = p.head->next; // point to the first term of p
        double currentCoeff = 0.0;
        while (anotherPolyPtr != p.head)
        {
            currentCoeff = coefficient(anotherPolyPtr->power); // find current coefficient

            // add coefficient from p
            changeCoefficient(currentCoeff - anotherPolyPtr->coeff, anotherPolyPtr->power);
            anotherPolyPtr = anotherPolyPtr->next;
        }
        anotherPolyPtr = nullptr;
    }
    return *this;
}

// rules:
// 1. term with zero coef will not print
// 2. empty polynomial will show as zero
// 3. term with 1 coef will only show x^n
// 4. term with 1 power will only show x
// 5. Special case for -1 coeff in the first term
// 6. Special case for power zero in the first term

/**
 * @brief Print Polynomial object in this format:
 * Cnx^n + Cn-1x^n-1 + ... C1x + C0 using the following rules:
 * 1. Empty polynomial should show as zero.
 * 2. Negative term should not have "+" in front of it.
 * 3. term with 1 coef should only show x^n.
 * 4. term with 1 power should only show x.
 * 5. positive first term should not have "+" in front.
 * 6. negative first term should not have padded space after "-".
 * @param output std::ostream object for printing output
 * @param p A Polynomial object to print
 */
ostream &operator<<(ostream &output, const Polynomial &p)
{
    if (p.size < 1) // print 0 for empty polynomial
    {
        output << "0";
        return output;
    }
    else // polynomial with at least 1 terms
    {
        Term *currentPtr = p.head->next;
        string sign = ""; // for predetermined signs

        while (currentPtr->coeff != 0) // stop when loop to head
        {
            // Decide which sign to show.
            // First term is more special since it doesn't show "+"
            // and has no padded space
            if (currentPtr == p.head->next) // predetermine sign for first term
            {
                sign = currentPtr->coeff < 0 ? "-" : "";
            }
            else // predetermine sign for the rest of the terms
            {
                sign = currentPtr->coeff < 0 ? " - " : " + ";
            }
            output << sign;

            // main printing logic
            if (abs(currentPtr->coeff) == 1 && currentPtr->power == 1) // 1x^1 print x
            {
                output << "x";
            }
            else if (currentPtr->power == 0) // Cx^0 print C
            {
                output << abs(currentPtr->coeff);
            }
            else if (abs(currentPtr->coeff) == 1) // 1x^n print x^n
            {
                output << "x^" << currentPtr->power;
            }
            else if (currentPtr->power == 1) // Cx^1 print Cx
            {
                output << abs(currentPtr->coeff) << "x";
            }
            else // print Cx^n
            {
                output << abs(currentPtr->coeff) << "x^" << currentPtr->power;
            }
            currentPtr = currentPtr->next; // go to next term
        }
        currentPtr = nullptr;
    }
    return output;
}

/**
 * @brief Getter for the highest degree in this object.
 *
 * @return An int power of the highest degree in this object
 * @pre This object is sorted from the largest power to lowest
 */
int Polynomial::degree() const
{
    if (size > 0)
    {
        return head->next->power;
    }
    return 0; // no other term except head
}

/**
 * @brief Getter for the coeffient of the term at the power
 * passed in the parameter.
 *
 * @param power An integer degree of the term to get coefficient
 * @return A double coefficient at that term
 */
double Polynomial::coefficient(const int power) const
{
    if (size > 0)
    {
        Term *currentPtr = getPositionBefore(power);
        if (currentPtr->next->power == power)
        {
            return currentPtr->next->coeff;
        }
    }
    return 0.0; // no other term or term with power passed does not exist
}

/**
 * @brief Handle 4 cases;
 * 1. if no term, add new term
 * 2. if power exist, change coeff
 * 3. If coeff passed is 0 and power exist, then delete term
 * 4. if power doesn't exist, add term with power and coeff passed
 * @param newCoefficient A double value to be assigned as coefficient
 * in the term to be changed
 * @param power An interger degree where the term is to be changed
 * @return true when executed
 */
bool Polynomial::changeCoefficient(const double newCoefficient, const int power)
{
    if (size == 0) // case 1
    {
        insert(head->next, newCoefficient, power);
        return true;
    }

    Term *currentPtr = getPositionBefore(power);

    if (currentPtr->next == head && newCoefficient != 0) // special case where added term has power 0
    {
        insert(currentPtr->next, newCoefficient, power);
    }
    else if (currentPtr->next->power == power && newCoefficient != 0) // case 2
    {
        currentPtr->next->coeff = newCoefficient;
    }
    else if (currentPtr->next->power == power && newCoefficient == 0) // case 3
    {
        remove(currentPtr->next);
    }
    else if (newCoefficient != 0) // case 4
    {
        insert(currentPtr->next, newCoefficient, power);
    }

    currentPtr = nullptr;
    return true;
}

/**
 * @brief Remove a single term at the position passed
 * and reduce size of Polynomial
 *
 * @param posToRemove A pointer to the location of term to be removed
 * @return true when executed
 * @post Term at posToRemove is removed from current object
 */
bool Polynomial::remove(Term *posToRemove)
{

    posToRemove->prev->next = posToRemove->next; // link previous term to next
    posToRemove->next->prev = posToRemove->prev; // link next term to previous

    // unlink the term to be removed from previous and next
    posToRemove->next = nullptr;
    posToRemove->prev = nullptr;

    delete posToRemove;    // delete the term to be removed;
    posToRemove = nullptr; // set current pointer to null;

    size--; // decrement the term count

    return true;
}

/**
 * @brief Insert a term into current object and increment size
 * of Polynomial.
 *
 * @param posAfterInsert A Term pointer to the term after the insertion
 * @param newCoefficient A double value to be assigned as coefficient
 * in the term to be inserted.
 * @param power An interger degree of the term to be inserted.
 * @return true when executed
 * @post a new term with power and coefficient passed is inserted into
 * the current object.
 */
bool Polynomial::insert(Term *posAfterInsert, const double newCoefficient, const int power)
{
    // create new term
    Term *currentPtr = new Term;
    currentPtr->coeff = newCoefficient;
    currentPtr->power = power;

    // link new node to node before and after
    currentPtr->next = posAfterInsert;       // point next to node ahead
    currentPtr->prev = posAfterInsert->prev; // point prev to node before

    // change node after link to new node
    posAfterInsert->prev = currentPtr;

    // change node before link to new node
    currentPtr->prev->next = currentPtr;

    currentPtr = nullptr;

    size++; // increment the term count

    return true;
}

/**
 * @brief Find and return a pointer to the location of term
 * that has the power next higher than the power passed in
 * parameter
 *
 * @param power A integer power to search for
 * @return A pointer to the term immediately before the term
 * with power passed in parameter
 */
Term *Polynomial::getPositionBefore(const int power) const
{
    Term *currentPtr = head->next; // point to the first node

    // power is sorted from largest to smallest.
    // stop searching when current power is <= target power
    while (currentPtr->power > power)
    {
        currentPtr = currentPtr->next;
    }
    return currentPtr->prev; // return the position before
}