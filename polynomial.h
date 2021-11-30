// ------------------------------------------------ Polynomial.cpp ------------------------------------------------------

// Luke Wanitthananon CSS 501 A

// Creation Date: November 14, 2021

// Date of Last Modification: November 29, 2021

// Modified from:  A Polynomial class (CSS342) by Munehiro Fukuda

// --------------------------------------------------------------------------------------------------------------------

// Purpose

// Polynomiall object holds sparse polynomial using a doubly-linked circular list with a dummy head

// --------------------------------------------------------------------------------------------------------------------

// Implementation and assumptions

//  --  nullptr is not used in the link chain in default head, only link to itself
//  --  each term in polynomial is stored as double coefficient and its degree power
//  --  Arithmatic operations with non-polynomial is not applicable i.e. no p1 + 2

// --------------------------------------------------------------------------------------------------------------------

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
#include <string>
#include <cmath> // for absolute value when printing coeff
using namespace std;

struct Term
{               // a term on the sparse polynomial
  double coeff; // the coefficient of each term
  int power;    // the degree of each term
  Term *prev;   // a pointer to the previous higher term
  Term *next;   // a pointer to the next lower term
};

class Polynomial
{
  // Overloaded <<: prints Cn * x^n + Cn-1 * X^n-1 + ... C1 * X + C0
  friend ostream &operator<<(ostream &output, const Polynomial &p);
  // Constructor: the default is a 0-degree polynomial with 0.0 coefficient
public:
  // Member functions
  Polynomial();
  Polynomial(const Polynomial &p);
  ~Polynomial();
  int degree() const; // returns the degree of a polynomial
  double coefficient(const int power) const;
  // returns the coefficient of the x^power term.
  bool changeCoefficient(const double newCoefficient, const int power);
  // replaces the coefficient of the x^power term as well as add and remove terms

  // Arithmetic operators
  Polynomial operator+(const Polynomial &p) const; // LHS + RHS
  Polynomial operator-(const Polynomial &p) const; // LHS - RHS

  // Boolean comparison operators
  bool operator==(const Polynomial &p) const; // LHS == RHS
  bool operator!=(const Polynomial &p) const; // LHS != RHS

  // Assignment operators
  Polynomial &operator=(const Polynomial &p);  // Assign another polynomial to itself
  Polynomial &operator+=(const Polynomial &p); // Add another polynomial to itself
  Polynomial &operator-=(const Polynomial &p); // Subtract another polynomial to itself

private:
  int size;   // # terms in the sparse polynomial
  Term *head; // a pointer to the doubly-linked circular list of sparse polynomial

  // helper methods
  // insert a term before the position passed
  bool insert(Term *posAfterInsert, const double newCoefficient, const int power);
  // remove a term at the position passed
  bool remove(Term *posToRemove);
  // remove all terms except dummy head
  bool clearAllTerms();
  // create new terms in current link chain and copy values from another polynomial
  bool copyAnotherPolynomial(const Polynomial &p);
  // initialize dummy head to default value
  bool init();
  // find and return the location of term before the power passed
  Term *getPositionBefore(const int power) const;
};

#endif
