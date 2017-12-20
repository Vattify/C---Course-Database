#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int numLines(ifstream& fin) {
  string text;
  int numLines = 0;

  while(getline(fin,text)) {
    numLines++;
  }

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
}

void seperateArray (int num, string a[], string c[], string s[]){
  int x = 0;
  int y = 0;

  for (int i = 0; i < num; i++){
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

void CourseArray(string courseline[]){
  string s = courseline[0];
  string delim = "|";
  int start = 0;
  int pos = s.find(delim);
  string o;

  while (pos != string::npos) {
    o = s.substr(start, pos - start);
    start = ++pos;
    pos = s.find(delim,pos);
    cout << o << endl;

    if (pos == string::npos){
    o = s.substr(start,s.length());
    cout << o << endl;
    }
  }
}

int main(){

  ifstream fin;

  fin.open("database.txt");
  string text;

  int num = numLines(fin);
  string *a = new string[numLines(fin)];

  lineArray(fin,a);

  string *courseline = new string[5];
  string *studentline = new string[15];
  seperateArray(num,a,courseline,studentline);
  cout << courseline[3] << endl;
  cout << studentline[3] << endl;

  Course c = new Course [5];

  CourseArray(courseline[1], c[1]);


}
