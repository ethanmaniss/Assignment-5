#include <iostream>
#include <string>

// base class for student and faculty classes
class Person
{
    private:
        int ID;
        string name;
        string level;

    public:


};

// student is a derived class
class Student: public Person
{
    private:
        string major;
        double GPA;
        int advisor;
};

// faculty is a derived class
class Faculty: public Person
{
    private:
        string department;

};
