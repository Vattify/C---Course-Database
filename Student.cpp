#include "Student.h"

// ~~~~~~~~~~~~~~~~~ Constructors ~~~~~~~~~~~~~~~~~
Student::Student():Student("First","Last") {}
Student::Student(string f, string l) : first(f), last(l) {
   grade = new int[cap];

   for(int i = 0; i < cap; i++){
     grade[i] = -1;}
 }

// ~~~~~~~~~~~~~~~~~ Mutators ~~~~~~~~~~~~~~~~~
 void Student::setName(string f, string l) {first = f; last = l;}
 void Student::setCapacity(Course c) {cap = c.numgrades;}
 void Student::setGradeByIndex(int i,int g){
   if(capacityValidation(i) == true)
     return;
   else{
      if(gradeValidation(g) == true)
        return;
      else
        grade[i] = g;
       }
 }
 void Student::addGrade(int g){
   for(int i = 0; i < cap; i++){
     if(grade[i] == -1){
       if(gradeValidation(g)==false){
         grade[i] = g;
       }
         return;
     }
   }
     cout << "No more room to add a Grade" << endl;
 }

 void Student::removeGrade(int i){
   if (i < 0 || i > numExams())
      cout << "This index is invalid";
   else{
      for(int j = i; i < numExams(); i++){
        grade[i] = grade[i+1];
      }
   }
 }

// ~~~~~~~~~~~~~~~~~ Accessors ~~~~~~~~~~~~~~~~~
string Student::getFirst() const {return first;}
string Student::getLast() const {return last;}
string Student::fullname() const {return (first + " " + last);}
void Student::getGradeByIndex(int i){
  if(capacityValidation(i) == true)
    return;
  else
    cout << grade[i] << endl;
}
int Student::getCap() {return cap;}

// ~~~~~~~~~~~~~~~~~ Big Three ~~~~~~~~~~~~~~~~~
Student::Student(const Student& e) {
  first = e.first;
  last = e.last;
  grade = new int (*(e.grade));
    for(int i = 0; i < cap; i++){
      grade[i] = e.grade[i]; }
// Testing //  cout << endl << "constructor called" << endl;
}
Student::~Student() {
  delete [] grade;
// Testing //  cout << endl << "deconstructor called" << endl;
 }
Student& Student::operator=(const Student& e){
    if(this != &e){
      first = e.first;
      last = e.last;
      for(int i = 0; i<cap; i++) {
        grade[i] = e.grade[i];
      }
    }
// Testing // cout << endl << "operator called" << endl;
  }

// ~~~~~~~~~~~~~~~~~ Extra & Outputs ~~~~~~~~~~~~~~~~~
bool Student::capacityValidation(int i){
  if(i >= cap || i < 0){
    cout << endl << "This number is out of bounds." << endl;
    return true;
  }
  else
    return false;
  }

bool Student::gradeValidation(int g){
  if (g < 0 || g > 100){
    cout << endl << "Grades must be between 0 and 100." << endl;
    return true;
  }
  else
    return false;
}

int Student::numExams(){
  int numExams = 0;
  for(int i = 0; i < cap; i++){
    if(grade[i] != -1){
      numExams++;
    }
  }
  return numExams;
}

int Student::GPA(){
  int GPA = 0;
  int numElements = 0;
  if(numExams() != 0){
    for(int i = 0; i < numExams(); i++){
        GPA += grade[i];
        numElements++;
    }
     return (GPA / numElements);
  }
  else
    return GPA;

 }

 void Student::outputgrades(){
   if(numExams() == 0)
     cout << "1. No Exam Records Found" << endl;
   else{
     for(int i = 0; i < numExams(); i++){
       cout << i + 1 << " : " << grade[i] << endl;
     }
   }
 }

 void Student::output(){
   cout << fullname() << endl;
   outputgrades();
   cout << "GPA: " << GPA();
 }
