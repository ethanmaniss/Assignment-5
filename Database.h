#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include "STree.h"
#include "FTree.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;

class Database
{
    private:
    STree* studentTree;
    FTree* facultyTree;

    public:
      Database();
      ~Database();

      void start(); // database will start running
      void getCommand(); // gets user input commands

      void printSInfo(); // info for student
      void printFInfo(); // info for faculty member
      void printSAInfo(); // info for student's advisor
      void printFAInfo(); // info for faculty's advisee
      void print(int ID, bool t); // print info based on only id number

      void addStudent();
      void addFaculty();

      void exit();

      void deleteStudent();
      void deleteFaculty();

      void changeAd();
      void removeAd();
};
#endif
