#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Course.h"
#include "Student.h"

// returns amount of line (data values) in database file
  int numLines(ifstream& fin);

// Puts each database line into an array
  void lineArray(ifstream& fin,string a[]);

// Seperates courses and students into two arrsy
  void seperateArray(int& x, int& y, ifstream& fin, string a[], string c[], string s[]);

// Creates Course objects using data from courseline array
  void CourseArray(int x, string courseline[], Course c[]);

#endif
