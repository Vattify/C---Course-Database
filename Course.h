#ifndef COURSE_H
#define COURSE_H

#include <iostream>
using namespace std;

// Including references to the Instructor class and Student class
#include "Instructor.h"
#include "Student.h"

// Declaring mutual referenced class to prevent compilation confusion & error.
class Student;

class Course{
public:
// ~~~~~~~~~~~~~~~~~ Constructors ~~~~~~~~~~~~~~~~~
/* Default Constructor that sets:
*/
  Course();
/* User Defined Constructor that sets:
Course name (name), Number of exams (numgrades), and Student Capacity (cap)*/
  Course(string n, int g,int c);

// ~~~~~~~~~~~~~~~~~ Mutators ~~~~~~~~~~~~~~~~~
// Name mutator (sets course name)
  void setName(string n);
// Numgrades mutator (sets numgrades)
  void setnumgrades(int n);
// Capacity mutator (sets capacity of students in a given course)
  void setcap(int c);
// Instructor mutator (Sets Instructor name based on Instructor class)
  void setInstructor(Instructor i);
// Instructor mutator overload (Sets Instructors name based on string value)
  void setInstructor(string i);
// Number of Students enrolled mutator (sets numstudents)
  void setNumStudents(int n);
// Student mutator (Adds a Student object into an array if space is available)
  void addStudent(int i,Student s);
// Studant Remover (Removes student from array by index)
//  void removeStudent(int i);

// ~~~~~~~~~~~~~~~~~ Accessors ~~~~~~~~~~~~~~~~~
// Retrieves Course name
  string getName();
// Retrieves Course numgrades
  int getnumgrades();
// Retrieves Course (student) capacity
  int getcap();
// Retrieves number of student enrolled
  int getNumStudents();
// Retrieves instructor
  string getInstructor();

//~~~~~~~~~~~~~~~~~ Big Three ~~~~~~~~~~~~~~~~~
// Copy Constructor
    Course(const Course& e);
// Destructor
    ~Course();
// Assignment Operator Overload
    Course& operator=(const Course& e);

// ~~~~~~~~~~~~~~~~~ Extra & Outputs ~~~~~~~~~~~~~~~~~
// Calculates amount of students are enrolled (counts students array)
  void numStudents();
// outputs the course with the instructor and students enrolled
  void output();

private:
// Allows Student class to access numgrades value
  friend class Student;
// Course members: string name, integer amount of exams, integer student capacity.
//                 string Instructor that is set by Instructor class, but given default value "N/A"
//                 pointer Student Object Array
  string name;
  int numgrades;
  int numstudents=0;
  int cap;
  string instructor="N/A";
  Student *students;
};
#endif
