#include <iostream>
#include "Database.h"
#include <string>

using namespace std;

Database::Database()
{
  studentTree = new BST<Student*>();
  facultyTree = new BST<Faculty*>();
}

Database::~Database()
{
  delete studentTree;
  delete facultyTree;
}

void Database::start()
{
  getCommand();
}

void Database::getCommand()
{
    string command = "";
    int c = 0;
    bool isOn = true;
    while(isOn)
    {
      cout << "Please enter number corresponding to command (enter 14 to exit)\n" << endl
            << "1: Print all students' information" << endl
            << "2: Print all faculty's information" << endl
            << "3: Display student information" << endl
            << "4: Display faculty information" << endl
            << "5: Display student's advisor information" << endl
            << "6: Display faculty's advisee information" << endl
            << "7: Add a new student" << endl
            << "8: Delete a student" << endl
            << "9: Add new faculty" << endl
            << "10: Delete faculty" << endl
            << "11: Change a student's advisor" << endl
            << "12: Remove advisee from faculty" << endl
            << "13: Rollback" << endl;

      cin >> command;

      try
      {
        c = stoi(command);
      }
      catch(invalid_argument const &e)
      {
        cout << "Error: invalid argument" << endl << endl;
        getCommand();
        return;
      }
      catch(out_of_range const &e)
      {
        cout << "Error: argument out of range" << endl << endl;
        getCommand();
        return;
      }

      switch(c)
      {
        case 1: // print all students' information
          break;

        case 2: // print all faculty's information
          break;

        case 3: // display student information
          break;

        case 4: // display faculty information
          break;

        case 5: // display student's advisor information
          break;

        case 6: // display faculty's advisee information
          break;

        case 7: // add a new student
          string n; // new student's name
          cout << "Enter the name of new student: " << endl;
          cin >> n;
          string l; // new student's grade level
          cout << "Enter " << n << "'s grade level: " << endl;
          cin >> l;
          // randomly generate new student's id
          Person s = new Person(); // generate new student object
          studentTree.insert(s); // adds a new student object to the tree

          break;

        case 8: // delete a student
          break;

        case 9: // add new faculty
          string n; // new faculty name
          cout << "Enter the name of new faculty member: " << endl;
          cin >> n;
          string l; // new faculty level
          cout << "Enter " << n << "'s level: " << endl;
          cin >> l;
          // randomly generate new faculty id
          Faculty f = new Faculty(); // generate new faculty object
          facultyTree.insert(f); // adds new faculty object to the tree

          break;

        case 10: // delete faculty
          break;

        case 11: // change a student's advisor
          break;

        case 12: // remove advisee from faculty
          break;

        case 13: // rollback
          break;

        case 14: // exit
          isOn = false;
          exit();
          break;

        default:
          cout << endl << "Error: invalid argument\n" << endl;
          break;
      }
    }
}

void Database::exit() // saves data of trees and exits
{
  cout << "Goodbye!" << endl;
}

void Database::deletePerson(&Person p)
{
  studentTree.delete(p);
}

void Database::deleteFaculty(&Person f)
{
  facultyTree.delete(f);
}
