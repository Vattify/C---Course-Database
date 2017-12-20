// Kira Boettcher - 12/19/2017
// Instructor.h

#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <iostream>
using namespace std;

class Instructor{
public:
// ~~~~~~~~~~~~~~~~~ Constructors ~~~~~~~~~~~~~~~~~

/* Default Constructor that sets:
Name = Name, Department = Department */
  Instructor();
/* User Defined Constructor that sets:
Name, and Department*/
  Instructor(string n, string d);

// ~~~~~~~~~~~~~~~~~ Mutators ~~~~~~~~~~~~~~~~~

// Instructor mutator that sets up both name and department;
  void setInstructor(string n, string d);

// ~~~~~~~~~~~~~~~~~ Accessors ~~~~~~~~~~~~~~~~~

// Retrieves Instructor's name
  string getName();
// Retrieves Instructor's department
  string getDepartment();

// ~~~~~~~~~~~~~~~~~ Extra & Outputs ~~~~~~~~~~~~~~~~~

// Simple Output For Testing
  void output();

private:
  friend class Course;
// Instructor members: string name and department
  string name;
  string department;
};
#endif
