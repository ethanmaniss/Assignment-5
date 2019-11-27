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

int Person::getID()
{
  return ID;
}

string Person::toString()
{
  string s = "Name: " + name + "\n"
            + "Level: " + level + "\n";
  return s;
}

bool Person::operator==(const Person& x)
{
  return (this->getID() == x.ID);
}

bool Person::operator<=(const Person& x)
{
  return (this->getID() <= x.ID);
}

bool Person::operator>=(const Person& x)
{
  return (this->getID() >= x.ID);
}
