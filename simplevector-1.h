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
// * Method implimentation to the end of this file where         *
// * indicated.                                                  *
// * Author: Dr. David Gaitros                                   *
// * Last Modified:  March 7th, 2021.                            *
// ***************************************************************
template <class T>
class SimpleVector {
const int DEFAULTVECTORSIZE=100; 
private:
    T *aptr; 		// To point to the allocated array
    int arraysize; 		// Number of elements in the array
    void memError(); 	// Handles memory allocation errors
    void subError(); 	// Handles subscripts out of range
public:
    // Default constructor - Already written, 
    SimpleVector() {aptr = 0; arraysize = 0;
    }

    // Constructor declaration
    SimpleVector(int);  //????????? WHY IS IT JUST (int) WITHOUT A VARIABLE AFTER????????

    // Copy Constructor declaration
    SimpleVector(const SimpleVector &);

    // Destructor - check to see if the size > zero.
    ~SimpleVector();

    // Accessor to return the array size
    int size() const { return arraysize; }

    // Accessor to return a specific element
    T getElementAt(int sub);

    // Overload [] operator declaration
    T &operator[](const int &); //return aptr[n]

    // Overload = operator declaration
    SimpleVector<T> operator = (SimpleVector<T> & s) { //{ PLACE YOUR CODE HERE FOR THE ASSIGNMENT OPERATOR OVERLOAD } 
            
        if (arraysize != 0) {
            delete [] aptr;                 // delete array if it's not empty
        }    
        aptr = new int * [s.arraysize];     // create new array, it's size is arraysize of the parameter array
        arraysize = s.arraysize;            // assign the arraysize with the parameter's arraysize 
        for (int i = 0; i < arraysize; i++) {
            aptr[i] = s.aptr[i];            // populate the array
        }
        return * this;
    } 
        
};
#endif
// ***************************************************************
// * Add your method implementation here.                        *
// ***************************************************************

// Constructor for SimpleVector Class
template <class T>
SimpleVector<T>::SimpleVector(int s) {
        
    if (s < 1) arraysize = 1;
    else arraysize = s;
    try {
        aptr = new T [arraysize];  //If this statement fails, go to catch
    }
    catch (bad_alloc) {
        memError(); 
        subError();
    }
    
    //initialize array to zeros.
    for (int index = 0; index < arraysize; index++) {
        aptr[index] = 0;
    }
}

// Copy Constructor declaration
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector & x) {
    aptr = new T[x.arraysize];
    arraysize = x.arraysize;
    for (int i = 0; i < arraysize; i++) {
        aptr[i] = x.aptr[i];
    }
}

// Destructor - check to see if the size > zero.
template <class T>
SimpleVector<T>::~SimpleVector() {
    if (arraysize <= 0) {
        delete aptr;
    }
}

// Accessor to return a specific element
template <class T>
T SimpleVector<T>::getElementAt(int sub) {
    return aptr[sub];
}

// Overload [] operator declaration
template <class T>
T & SimpleVector<T>::operator[](const int & x) {
    return aptr[x];
}

template <class T>
void SimpleVector<T>::subError() {
    
    cout << "Error: subscript out of range." << endl;
    exit (EXIT_FAILURE);
}

template <class T>
void SimpleVector<T>::memError() {
     
    cout << "Error: cannot allocate memory." << endl;
    exit (EXIT_FAILURE);
}

