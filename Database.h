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

      void start();
      void getCommand();

      void printSInfo();
      void printFInfo();
      void printSAInfo();
      void printFAInfo();
      void print(int ID, bool t);

      void addStudent();
      void addFaculty();

      void exit();

      void deleteStudent();
      void deleteFaculty();

      void changeAd();
      void removeAd();
};
#endif
