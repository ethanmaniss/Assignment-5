#include <iostream>
#include "Person.h"

using namespace std;

Person::Person()
{
  ID = 0;
  name = "";
  level = "";
}

Person::Person(int ID, string n, string l)
{
  this->ID = ID;
  name = n;
  level = l;
}

Person::~Person()
{

}
