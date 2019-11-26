#include <iostream>
#include "Database.h"

using namespace std;

Database::Database()
{
  studentTree = new BST<Student>();
  facultyTree = new BST<Faculty>();
}
