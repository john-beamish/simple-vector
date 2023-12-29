# simple-vector
COP 3330 Spring 2023 Assignment 6 Simple Vector

Educational Objectives: 
After completing this assignment the student should have the following knowledge, ability, and skills:

Distinguish between a function template and a concrete function: definition, implementation, and file structure conventions
Demonstrate correct notation and syntax for defining and implementing a function template
State the rules compilers use to instantiate a function template
Test a function template for correct syntax
Test a function template for correct behavior
Test a function template for generically
Test the "+" operator overload to add two vectors together.  
You may use the vector or list standard template libraries if you wish.  
 

Operational Objectives: 
Given the simplevector.h definition below, modify the file to implement the template.   NOTE: all of the code needs to go into the same file for reasons we will discuss.   

#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>                  // Needed for bad-alloc exception
#include <cstdlib>              // Needed for the exit function
using namespace std;
// ***************************************************************
// * Template Assignment simplevector.h                          *
// * Description:  Contains the basic definition of the          *
// * SimpleVector Template class.  The method names and          *
// * signatures must not be modified. You will add your          *
// * Method implementation to the end of this file where         *
// * indicated.                                                  *
// * Author: Dr. David Gaitros                                   *
// * Last Modified:  March 7th, 2021.                            *
// ***************************************************************
template <class T>
class SimpleVector {
const int DEFAULTVECTORSIZE=100; 
private:
        T *aptr;         // To point to the allocated array
        int arraysize;         // Number of elements in the array
        void memError();     // Handles memory allocation errors
        void subError();     // Handles subscripts out of range
public:
        // Default constructor - Already written, 
        SimpleVector();

        // Constructor declaration
        SimpleVector(int);

        // Copy Constructor declaration
        SimpleVector(const SimpleVector &);

        // Destructor - check to see if the size > zero.
        ~SimpleVector();

        // Accessor to return the array size
        int size() const { return arraysize; }

        // Accessor to return a specific element
        T getElementAt(int sub);

        // Overload [] operator declaration
        T &operator[](const int &);
                 // Overload = operator and implementation
                SimpleVector<T> & operator = (SimpleVector & s) 
               {    Place. your code here.                             }

// ***************************************************************
// * Add your method implementation here.                        *
// ***************************************************************

#endif //SIMPLEVECTOR_H

simplevector.h file:  simplevector-1.h Download simplevector-1.h 

Private and Public Item Descriptions:
- T * aptr;    - This is the dynamically allocated array.  This is set when the constructor is called and does not change in size. 

- int arraysize  - Holds the number of elements allocated to T* aptr. 

- void MemError() -  Handles errors of memory allocation.  If you are not able to allocate the memory you should issue an error message and stop the program. 

- void subError(); -  Handles subscripts out of range.  If an attempt is made to go out of bounds an error message should be issued.  

- SimpleVector()  - Default constructor...Allocate DEFAULTVECTORSIZE number of elements. 

SimpleVector(int);  - One parameter constructor - Allocate the number of elements passed inSimpleVector(const SimpleVector &);

~SimpleVector();  - Destructor 


int size() const { return arraysize; }. - No need to alter. 


T getElementAt(int sub);  - Returns element at location sub.

T &operator[](const int &); - Overloads the [] operator .   Gives both read and write access to the element at that location. 

SimpleVector<T> & operator = (SimpleVector & s)   Performs a deep copy of the vector that is passed in.  If the object on the left exists, delete it.   Create a new object of the size of the vector passed in on the parameter "s" and copy the contents into the new one.  
