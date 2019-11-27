#include <iostream>
#include "Database.h"

using namespace std;

int main(int argc, char** argv)
{
  Database* d = new Database();
  d->start();
  delete d;
  return 0;
}
