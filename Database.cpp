#include <iostream>
#include "Database.h"
#include <string>

using namespace std;

Database::Database()
{
  studentTree = new STree(); // holds student objects
  facultyTree = new FTree(); // holds faculty objects
}

Database::~Database()
{
  delete studentTree;
  delete facultyTree;
}

void Database::start() // finds binary files for trees
{
  getCommand(); // runs this method to start up the database
}

void Database::getCommand()
{
    string command = "";
    int c = 0; // integer corresponding to command number
    bool isOn = true;
    while(isOn) // will keep prompting user for commands until they choose to exit
    {
      cout << endl << "Please enter number corresponding to command (enter 14 to exit)\n" << endl
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
        c = stoi(command); // string command is converted to integer
      }
      catch(invalid_argument const &e)
      {
        cout << "Error: invalid argument" << endl << endl;
        getCommand(); // will try again
        return;
      }
      catch(out_of_range const &e)
      {
        cout << "Error: argument out of range" << endl << endl;
        getCommand(); // will try again
        return;
      }

      switch(c)
      {
        case 1: // print all students' information
          studentTree->printTree();
          break;

        case 2: // print all faculty's information
          facultyTree->printTree();
          break;

        case 3: // display student information
          printSInfo();
          break;

        case 4: // display faculty information
          printFInfo();
          break;

        case 5: // display student's advisor information
          printSAInfo();
          break;

        case 6: // display faculty's advisee information
          printFAInfo();
          break;

        case 7: // add a new student
          addStudent();
          break;

        case 8: // delete a student
          deleteStudent();
          break;

        case 9: // add new faculty
          addFaculty();
          break;

        case 10: // delete faculty
          deleteFaculty();
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

void Database::printSInfo()
{
  string r = "";
  int i = 0;

  cout << "Enter ID of desired student" << endl;
  cin >> r;

  try
  {
    i = stoi(r); // converts user input student id from string to integer
  }
  catch(invalid_argument const &e)
  {
    cout << "Error: invalid argument" << endl << endl;
    return;
  }
  catch(out_of_range const &e)
  {
    cout << "Error: argument out of range" << endl << endl;
    return;
  }

  if (i < 100000 || i > 999999) // ID is invalid
  {
    cout << "Error: given ID is invalid" << endl;
    return;
  }

  print(i, true); // prints out student info if id is valid
}

void Database::printFInfo()
{
  string r = "";
  int i = 0;

  cout << "Enter ID of desired faculty" << endl;
  cin >> r;

  try
  {
    i = stoi(r); // converts user input faculty id from string to integer
  }
  catch(invalid_argument const &e)
  {
    cout << "Error: invalid argument" << endl << endl;
    return;
  }
  catch(out_of_range const &e)
  {
    cout << endl << "Error: argument out of range" << endl << endl;
    return;
  }

  if (i < 100000 || i > 999999) // ID is invalid
  {
    cout << "Error: given ID is invalid" << endl;
    return;
  }

  print(i, false); // prints out faculty info if id is valid
}

void Database::printSAInfo() // prints student's advisor's information
{
  string r = "";
  int i = 0; // student id
  int a = 0; // advisor id

  cout << "Enter student's ID" << endl;
  cin >> r;

  try
  {
    i = stoi(r);
  }
  catch(invalid_argument const &e)
  {
    cout << "Error: invalid argument" << endl << endl;
    return;
  }
  catch(out_of_range const &e)
  {
    cout << endl << "Error: argument out of range" << endl << endl;
    return;
  }
  if (i < 100000 || i > 999999)
  {
    cout << "Error: given ID is invalid" << endl;
    return;
  }

  if(studentTree->contains(i))
  {
    TreeNode<Student*>* node = studentTree->search(i);
    a = node->key->getAdvisor();
    print(a, false);
  }
  else
  {
    cout << "Error: Given ID does not exist" << endl;
    return;
  }
}

void Database::printFAInfo()
{
  string r = "";
  int i = 0; // faculty id

  cout << "Enter faculty's ID" << endl;
  cin >> r;

  try
  {
    i = stoi(r);
  }
  catch(invalid_argument const &e)
  {
    cout << "Error: invalid argument" << endl << endl;
    return;
  }
  catch(out_of_range const &e)
  {
    cout << endl << "Error: argument out of range" << endl << endl;
    return;
  }
  if (i < 100000 || i > 999999)
  {
    cout << "Error: given ID is invalid" << endl;
    return;
  }

  if(facultyTree->contains(i))
  {
    TreeNode<Faculty*>* node = facultyTree->search(i);
  }
  else
  {
    cout << "Error: Given ID does not exist" << endl;
    return;
  }
}

void Database::print(int ID, bool t) // prints specific student or faculty info, bool true = student
{
  if(t)
  {
    if(studentTree->contains(ID))
    {
      TreeNode<Student*>* node = studentTree->search(ID);
      cout << node->key->toString() << endl;
    }
    else
    {
      cout << "Error: Student ID does not exist" << endl;
    }
  }
  else
  {
    if(facultyTree->contains(ID))
    {
      TreeNode<Faculty*>* node = facultyTree->search(ID);
      cout << node->key->toString() << endl;
    }
    else
    {
      cout << "Error: Faculty ID does not exist" << endl;
    }
  }
}

void Database::addStudent()
{
  string n = ""; // name
  string l = ""; // level
  string m = ""; // major
  string ad = "";
  int a = 0; // advisor
  int ID = 0;
  double g = 0.0; // GPA


  cout << "Enter the name of new student: " << endl;
  cin >> n;

  cout << "Enter " << n << "'s year (Freshman, Sophomore, Junior, Senior): " << endl;
  cin >> l;

  cout << "Enter the major of " << n << ": " << endl;
  cin >> m;

  cout << "Enter student's advisor's ID" << endl;
  cin >> ad;
  try
  {
    a = stoi(ad); // id converted from string to integer
  }
  catch(invalid_argument const &e)
  {
    cout << "Error: invalid argument" << endl << endl;
    return;
  }
  catch(out_of_range const &e)
  {
    cout << "Error: argument out of range" << endl << endl;
    return;
  }
  if(a < 100000 || a > 999999)
  {
    cout << "Error: Invalid ID was given" << endl << endl;
    return;
  }
  else if(!facultyTree->contains(a))
  {
    cout << "Error: Faculty advisor does not exist" << endl << endl;
  }

  cout << "Enter student's GPA" << endl;
  cin >> ad;
  try
  {
    g = stod(ad); // converts gpa variable from string to double
  }
  catch(invalid_argument const &e)
  {
    cout << "Error: invalid argument" << endl << endl;
    return;
  }
  catch(out_of_range const &e)
  {
    cout << "Error: argument out of range" << endl << endl;
    return;
  }

  cout << "Enter ID of student (must be 6 numbers)" << endl;
  cin >> ad;
  try
  {
    ID = stoi(ad);
  }
  catch(invalid_argument const &e)
  {
    cout << "Error: invalid argument" << endl << endl;
    return;
  }
  catch(out_of_range const &e)
  {
    cout << "Error: argument out of range" << endl << endl;
    return;
  }
  if (ID < 100000 || ID > 999999) // id not long enough or too long
  {
    cout << "Error: invalid ID" << endl << endl;
    return;
  }
  else if (studentTree->contains(ID)) // id already exists
  {
    cout << "Error: ID already exists" << endl << endl;
    return;
  }

  // all student info found
  Student* s = new Student(ID, n, l, g, m, a); // generate new student object
  studentTree->insert(s); // adds a new student object to the tree
}

void Database::addFaculty()
{
  string n = ""; // name
  string l = ""; // level
  string d = ""; // department;
  string r = "";
  int ID = 0;

  cout << "Enter the name of new faculty member: " << endl;
  cin >> n;

  cout << "Enter the department of " << n << endl;
  cin >> d;

  cout << "Enter " << n << "'s position: " << endl;
  cin >> l;

  cout << "Enter ID of faculty member (must be 6 digit number)" << endl;
  cin >> r;
  try
  {
    ID = stoi(r);
  }
  catch(invalid_argument const &e)
  {
    cout << "Error: invalid argument" << endl << endl;
    return;
  }
  catch(out_of_range const &e)
  {
    cout << "Error: argument out of range" << endl << endl;
    return;
  }
  if (ID < 100000 || ID > 999999) // id not long enough or too long
  {
    cout << "Error: invalid ID" << endl << endl;
    return;
  }
  else if (facultyTree->contains(ID))
  {
    cout << "Error: ID already exists" << endl << endl;
    return;
  }

  // randomly generate new faculty id
  Faculty* f = new Faculty(ID, n, l , d); // generate new faculty object
  facultyTree->insert(f); // adds new faculty object to the tree
}

void Database::exit() // saves data of trees and exits
{
  cout << "Goodbye!" << endl;
}

void Database::deleteStudent()
{
  string r = "";
  int i = 0; // student id number
  cout << "Enter student's ID number: " << endl;
  cin >> r;
  try
  {
    i = stoi(r); // student id is converted from string to integer
  }
  catch(invalid_argument const &e)
  {
    cout << "Error: invalid argument" << endl << endl;
    return;
  }
  catch(out_of_range const &e)
  {
    cout << "Error: argument out of range" << endl << endl;
    return;
  }
  if (i < 100000 || i > 999999) // id not long enough or too long
  {
    cout << "Error: invalid ID" << endl << endl;
    return;
  }
  if(studentTree->contains(i))
  {
    TreeNode<Student*>* node = studentTree->search(i);

  }
}

void Database::deleteFaculty()
{
  string r = "";
  int i = 0; // faculty id number
  cout << "Enter faculty's ID number: " << endl;
  cin >> r;
  try
  {
    i = stoi(r); // converts faculty id from string to integer
  }
  catch(invalid_argument const &e)
  {
    cout << "Error: invalid argument" << endl << endl;
    return;
  }
  catch(out_of_range const &e)
  {
    cout << "Error: argument out of range" << endl << endl;
    return;
  }
  if (i < 100000 || i > 999999) // id not long enough or too long
  {
    cout << "Error: invalid ID" << endl << endl;
    return;
  }
  if(facultyTree->contains(i))
  {
    TreeNode<Faculty*>* node = facultyTree->search(i);

  }
}

void Database::changeAd() // change student's advisor
{
  string r = "";
  int i = 0; // student id number
  cout << "Enter student's ID number: " << endl;
  cin >> r;
  try
  {
    i = stoi(r);
  }
  catch(invalid_argument const &e)
  {
    cout << "Error: invalid argument" << endl << endl;
    return;
  }
  catch(out_of_range const &e)
  {
    cout << "Error: argument out of range" << endl << endl;
    return;
  }
  if (i < 100000 || i > 999999) // id not long enough or too long
  {
    cout << "Error: invalid ID" << endl << endl;
    return;
  }
  if(studentTree->contains(i))
  {
    TreeNode<Student*>* stu = studentTree->search(i);

    string res = "";
    int fi = 0; // faculty id number

    cout << "Enter faculty's ID number: " << endl;
    cin >> res;
    try
    {
      fi = stoi(res);
    }
    catch(invalid_argument const &e)
    {
      cout << "Error: invalid argument" << endl << endl;
      return;
    }
    catch(out_of_range const &e)
    {
      cout << "Error: argument out of range" << endl << endl;
      return;
    }
    if (fi < 100000 || fi > 999999) // id not long enough or too long
    {
      cout << "Error: invalid ID" << endl << endl;
      return;
    }
    if(facultyTree->contains(fi))
    {
      TreeNode<Faculty*>* fac = facultyTree->search(fi);
      stu->key->setAdvisor(fi);
      fac->key->addAdvisee(i);
    }
  }
  else
  {
    cout << "Error: ID does not exist" << endl << endl;
  }
}

void Database::removeAd() // remove advisee
{
  string r = "";
  int i = 0; // faculty id number
  cout << "Enter faculty's ID number: " << endl;
  cin >> r;
  try
  {
    i = stoi(r);
  }
  catch(invalid_argument const &e)
  {
    cout << "Error: invalid argument" << endl << endl;
    return;
  }
  catch(out_of_range const &e)
  {
    cout << "Error: argument out of range" << endl << endl;
    return;
  }
  if (i < 100000 || i > 999999) // id not long enough or too long
  {
    cout << "Error: invalid ID" << endl << endl;
    return;
  }
  if(facultyTree->contains(i))
  {
    TreeNode<Faculty*>* node = facultyTree->search(i);

    string res = "";
    int si = 0; // student id number
    cout << "Enter student's ID number: " << endl;
    cin >> res;
    try
    {
      si = stoi(res);
    }
    catch(invalid_argument const &e)
    {
      cout << "Error: invalid argument" << endl << endl;
      return;
    }
    catch(out_of_range const &e)
    {
      cout << "Error: argument out of range" << endl << endl;
      return;
    }
    if (si < 100000 || si > 999999) // id not long enough or too long
    {
      cout << "Error: invalid ID" << endl << endl;
      return;
    }
    if(studentTree->contains(i))
    {
      TreeNode<Student*>* stu = studentTree->search(i);
    }
  }
}
