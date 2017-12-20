#include "UI.h"
#include "Database.h"
#include "Course.h"
#include "Student.h"

int main() {

// Step One - Setup Class Objects from database
  ifstream fin;
  fin.open("database.txt");

  string *databaseLines = new string[numLines(fin)];
  lineArray(fin,databaseLines);

  int x = 0;
  int y = 0;
  string *courseline = new string[numLines(fin)];
  string *studentline = new string[numLines(fin)];
  seperateArray(x,y,fin,databaseLines,courseline,studentline);

  Course *c = new Course [10];
  CourseArray(x,courseline,c);

  MainMenu(fin,c,x);

  return 0;
}
