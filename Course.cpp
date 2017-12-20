#include "Course.h"

// ~~~~~~~~~~~~~~~~~ Constructors ~~~~~~~~~~~~~~~~~
Course::Course() : Course("Course Name",0,1) {}
Course::Course(string n, int g, int c) : name(n),numgrades(g),cap(c){
  students = new Student[cap];
}

// ~~~~~~~~~~~~~~~~~ Mutators ~~~~~~~~~~~~~~~~~
void Course::setName(string n) {name = n;}
void Course::setnumgrades(int n) {numgrades = n;}
void Course::setcap(int c) {cap = c;}
void Course::setInstructor(Instructor i) {instructor = i.name;}
void Course::setInstructor(string i) {instructor = i;}
void Course::setNumStudents(int n) {numstudents = n;}
void Course::addStudent(int i, Student s) {
  students[i] = s;
}

// ~~~~~~~~~~~~~~~~~ Accessors ~~~~~~~~~~~~~~~~~
string Course::getName() {return name;}
int Course::getnumgrades() {return numgrades;}
int Course::getcap() {return cap;}
int Course::getNumStudents() {return numstudents;}
string Course::getInstructor() {return instructor;}

// ~~~~~~~~~~~~~~~~~ Big Three ~~~~~~~~~~~~~~~~~
Course::Course(const Course& e) {
  name = e.name;
  numgrades = e.numgrades;
  instructor = e.instructor;
  numstudents = e.numstudents;
  cap = e.cap;
  students = new Student (*(e.students));
    for(int i = 0; i < cap; i++){
      students[i] = e.students[i]; }
  cout << endl << "Constructor called" << endl;
}
Course::~Course() { delete [] students; cout << endl <<"deconstructor called" << endl; }

Course& Course::operator=(const Course& e){
    if(this != &e){
      name = e.name;
      numgrades = e.numgrades;
      instructor = e.instructor;
      numstudents = e.numstudents;
      cap = e.cap;
      for(int i = 0; i<cap; i++) {
        students[i] = e.students[i];
      }
    }
    cout << endl << "operator called" << endl;
  }
// ~~~~~~~~~~~~~~~~~ Extra & Outputs ~~~~~~~~~~~~~~~~~

void Course::numStudents(){
  int numStudents = 0;
  for(int i = 0; i < cap; i++){
    if (students[i].fullname() == "First Last") {
    numstudents = 0;
      break;
    }
    else {
      numStudents++;
      if(students[i+1].fullname() == "First Last"){
        break;
      }
    }
  }
  numstudents = numStudents;
}

void Course::output(){
  cout << name << " | " << numgrades << " exams | " << cap << " students capacity";
  cout << " | enrolled: " << numstudents << " | Taught by: " << instructor;
}
