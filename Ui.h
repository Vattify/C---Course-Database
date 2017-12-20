#ifndef GUI_H
#define GUI_H

#include <iostream>
using namespace std;

// Including references to the Instructor class, Student class, and Course Class
#include "Instructor.h"
#include "Student.h"
#include "Course.h"

void Header();
void MainMenu(ifstream& fin, Course c[], int x);
void CoursesMenu(ifstream& fin, Course c[], int x);
void CourseDetails(Course c);

#endif
