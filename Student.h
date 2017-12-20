// Kira Boettcher - 12/19/2017
// Student.h

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

// Including reference to the Course class for setting up a student's grade capacity for a class.
#include "Course.h"

// Declaring mutual referenced class to prevent compilation confusion & error.
class Course;

class Student{
public:

// ~~~~~~~~~~~~~~~~~ Constructors ~~~~~~~~~~~~~~~~~

/* Default Constructor that sets:
First = First, Last = Last */
  Student();
/* User Defined Constructor that sets:
First, Last, and Dynamic Array, and its values to -1 if not yet defined*/
  Student(string f, string l);

// ~~~~~~~~~~~~~~~~~ Mutators ~~~~~~~~~~~~~~~~~

// Name mutator (sets first and last name)
  void setName(string f, string l);
// Capacity mutator (sets grade capcity based on specific course numgrade member)
  void setCapacity(Course c);
// Grade mutator (sets grade according to index given)
  void setGradeByIndex(int i, int g);
// Grade mutator #2 (adds a grade if space is available)
  void addGrade(int g);
// Grade remover (removes grade by index)
  void removeGrade(int i);

// ~~~~~~~~~~~~~~~~~ Accessors ~~~~~~~~~~~~~~~~~

// Retrieves first name
  string getFirst() const;
// Retrieves last name
  string getLast() const;
// Creates full name string
  string fullname() const;
// Retrieves grade by index given
  void getGradeByIndex(int i);
// Retrieves capacity
  int getCap();

// ~~~~~~~~~~~~~~~~~ Big Three ~~~~~~~~~~~~~~~~~

// Copy Constructor
  Student(const Student& e);
// Destructor
  ~Student();
// Assignment Operator Overload
  Student& operator=(const Student& e);

// ~~~~~~~~~~~~~~~~~ Extra & Outputs ~~~~~~~~~~~~~~~~~

// Function that handles and checks if index is within capacity
  bool capacityValidation(int i);
// Function that validates test grades
  bool gradeValidation(int g);
// Function that counts the amount of Exams a Student has taken
  int numExams();
// Calculates and Outputs Student GPA
  int GPA();
// Outputs grades in numbered format
  void outputgrades();
// Output student's name, grades, and overal GPA;
  void output();

private:

  friend class Course;
// Number of Grades capacity to be dictated by numgrades from course.
  int cap{10};
// Student members: string first and last, & pointer integer to an dynamic array of grades.
  string first;
  string last;
  int *grade;
};
#endif
