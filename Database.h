#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include "BST.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;

class Database
{
    private:
    BST<Student*>* studentTree;
    BST<Faculty*>* facultyTree;

    public:
      Database();
      ~Database();

      void start();
      void getCommand();
      void exit();

      void addPerson(&Person p);
      void deletePerson(&Person p);
      void addFaculty(&Person f);
      void deleteFaculty(&Person f);

};
#endif
