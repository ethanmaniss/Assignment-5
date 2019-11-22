#include "GenStack.h"
#include <iostream>

using namespace std;
// default constructor
GenStack::GenStack()
{
    // initialization of default values
    myArray = new char[128];
    size = 128;
    top = -1; // will eventually be preincremented to equal index value of 0
}

GenStack::GenStack(int maxSize) // overloaded constructor
{
    myArray = new char[maxSize];
    size = maxSize;
    top = -1;
}

GenStack::~GenStack()
{
    // lets build some character
    // your job to research this
    // (one line of code to delete array)
    delete[] myArray;
}

void GenStack::push(char d)
{
    // need to check error/boundary check
    // this is your job
    if(isFull())
    {
        cout << "Array is full." << endl;
    }
    else
    {
        myArray[++top] = d;
    }
}

char GenStack::pop()
{
    // error checking, make sure it's not isEmpty
    if(isEmpty())
    {
        cout << "Array is empty." << endl;
    }
    else
    {
        return myArray[top--];
    }
}

char GenStack::peek()
{
    // check if it's empty
    if(isEmpty())
    {
        cout << "Array is empty." << endl;
    }
    else
    {
        return myArray[top];
    }
}

bool GenStack::isFull() // will return either true or false
{
    return (top == size - 1);
}

bool GenStack::isEmpty()
{
    return (top == -1);
}
