#include "polynomial.h"
using namespace std;

Polynomial::Polynomial()
    : size(0), head(new Term)
{
    head->coeff = 0.0;
    head->power = 0;

    // initialize to point at itself since this class assumes it will not have to
    // deal with nullptr;
    head->prev = head;
    head->next = head;
}

Polynomial::Polynomial(const Polynomial &p)
    : size(0), head(new Term)
{
    head->coeff = 0.0;
    head->power = 0;
    head->prev = head;
    head->next = head;

    if (p.size > 0) // only copy if the polynomial is not empty
    {
        Term *currentPtr = p.head->next; // pointer at the first term to copy
        while (size < p.size)
        {
            changeCoefficient(currentPtr->coeff, currentPtr->power);
            currentPtr = currentPtr->next;
        }
        currentPtr = nullptr;
    }
}

Polynomial::~Polynomial()
{
    clearAllTerms();
    // clear head
    delete head;
    head = nullptr;
}

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

// rules:
// 1. term with zero coef will not print
// 2. empty polynomial will show as zero
// 3. term with 1 coef will only show x^n
// 4. term with 1 power will only show x
ostream &operator<<(ostream &output, const Polynomial &p)
{
    if (p.size < 1) // empty polynomial print 0
    {
        output << " 0";
        return output;
    }
    else // polynomial with at least 1 terms
    {
        // print the first term
        Term *currentPtr = p.head->next;
        output << currentPtr->coeff << "x^" << currentPtr->power;

        // print the rest
        string sign = "";
        currentPtr = currentPtr->next;
        while (currentPtr->coeff != 0) // stop when loop to head again
        {
            sign = currentPtr->coeff < 0 ? " - " : " + "; // predetermine sign
            output << sign;

            if (currentPtr->coeff == 1 && currentPtr->power == 1) // 1x^1 print x
            {
                output << "x";
            }
            else if (currentPtr->power == 0) // Cx^0 print C
            {
                output << currentPtr->coeff;
            }
            else if (currentPtr->coeff == 1) // 1x^n print x^n
            {
                output << "x^" << currentPtr->power;
            }
            else if (currentPtr->power == 1) // Cx^1 print Cx
            {
                output << currentPtr->coeff << "x";
            }
            else // print Cx^n
            {
                output << abs(currentPtr->coeff) << "x^" << currentPtr->power;
            }
            currentPtr = currentPtr->next;
        }
    }
    return output;
}

// Assume list is sorted from highest degree to lowest
int Polynomial::degree() const
{
    if (size > 0)
    {
        return head->next->power;
    }
    return 0; // no other term except head
}

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

// handle 4 cases:
// 1. if no term, add new term
// 2. if power exist, change coeff
// 3. If coeff passed is 0 and power exist, then delete term
// 4. if power doesn't exist, add term with power and coeff passed

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