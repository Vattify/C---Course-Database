#include "Instructor.h"

Instructor::Instructor() : Instructor("Name","Department") {}
Instructor::Instructor(string n, string d) : name(n), department(d) {}

void Instructor::setInstructor(string n, string d) {name = n; department = d;}

string Instructor::getName() {return name;}
string Instructor::getDepartment() {return department;}

void Instructor::output() {
  cout << name << " : " << department;
}
