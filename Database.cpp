#include "Database.h"

int numLines(ifstream& fin) {
  string text;
  int numLines = 0;

  while(getline(fin,text)) {
    numLines++;
  }
// resets file to be read back at line 0.
  fin.clear();
  fin.seekg(0, ios::beg);

  return numLines;
}

void lineArray (ifstream& fin, string a[]) {
  string text;
  int i = 0;
  while(getline(fin,text)){
    a[i] = text;
    i++;
  }
  // resets file to be read back at line 0.
    fin.clear();
    fin.seekg(0, ios::beg);
}

void seperateArray (int& x, int& y, ifstream& fin, string a[], string c[], string s[]){
  for (int i = 0; i < numLines(fin); i++){
      if (a[i].find("Course") == 0){
        c[x] = a[i];
        x++;
      }
      if (a[i].find("Student") == 0){
        s[y] = a[i];
        y++;
      }
  }
}

void CourseArray(int x, string courseline[], Course c[]){
for (int i = 0; i < x; i++){
  int start = 0;
  int pos = 0;
  string value = "";
  string temp[5];
  int j = 0;

      string s = courseline[i];
      pos = s.find("|");

        while(pos != string::npos) {
          value = s.substr(start, pos - start);
          start = ++pos;
          pos = s.find("|",pos);
          temp[j] = value;
          j++;

          if (pos == string::npos) {
            value = s.substr(start,s.length());
            temp[j] = value;
          }
        }
        c[i].setName(temp[1]);
        c[i].setInstructor(temp[2]);
        c[i].setnumgrades(stoi(temp[3]));
        c[i].setNumStudents(stoi(temp[4]));
        c[i].setcap(stoi(temp[5]));
    }
  }
