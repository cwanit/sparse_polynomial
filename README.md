# Sparse Polynomial
Polynomial object holds sparse polynomial using a doubly-linked circular list with a dummy head
* nullptr is not used in the link chain in default head, only link to itself
* Each term in polynomial is stored as double coefficient and its degree power
* Arithmatic operations with primitive number type (non-polynomial object) is not capable
