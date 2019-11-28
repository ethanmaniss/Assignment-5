#include <iostream>
#include "Database.h"

using namespace std;

int main(int argc, char** argv)
{
  Database* d = new Database(); // creates new database pointer object
  d->start(); // calls the start method to begin running the database
  delete d; // delete database pointer object
  return 0;
}
