#include "Ui.h"
#include "Database.h"
#include "Course.h"
#include "Student.h"

void Header(){
  cout << "================================================================= " << endl <<
          "PROJECT I FALL 2017 : KIRA BOETTCHER" << endl <<
          "==================================================================" << endl<<endl<<endl;
}

void MainMenu(ifstream& fin, Course c[], int x){
  Header();
  cout << "MAIN MENU" << endl <<
          "==================================================================" << endl <<
          "1. Display Courses" << endl <<
          "2. Exit Program" << endl << endl <<
          "Select an Option: ";

          int input;
          cin >> input;

          switch (input) {
            case 1:
              system("CLS");
              CoursesMenu(fin, c, x);
              break;
            case 2:
          	  exit;
              break;

            default:
        		  cout << "That option is invalid!" << endl << endl;
        		}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void CoursesMenu(ifstream& fin, Course c[], int x){
  Header();
  cout << "COURSES" << endl <<
          "==================================================================" << endl;
  for (int i = 0; i < x; i++){
    cout << i+1 << ". ";
    c[i].output();
    cout << endl;
  }

   cout << "Course Options: " << endl <<
          "-----------------------------------------------------------------" << endl <<
          "1. Add a Course" << endl <<
          "2. Edit a Course" << endl <<
          "3. Return to Main Menu" << endl <<
          "Select an Option: ";

          int input;
          cin >> input;

          switch (input) {
            case 1: {
              system("CLS");
              int inputa;
              string inputb;
              x++;

              cout << "Course Name: ";
              cin >> inputb;
              c[x-1].setName(inputb);
              cout << endl << "Course Instructor: ";
              cin >> inputb;
              c[x-1].setInstructor(inputb);
              cout << endl << "Student Capacity: ";
              cin >> inputa;
              c[x-1].setcap(inputa);
              cout << endl << "Amount of Exams: ";
              cin >> inputa;
              c[x-1].setnumgrades(inputa);

              system("CLS");
              CoursesMenu(fin,c,x);
              break; }

            case 2: {
              cout << endl << endl << "Select a Course by it's number: ";
              int input2;
              cin >> input2;
              cout << endl;
                  c[input2-1].output();
              cout << endl << endl << "What do you want to change?" << endl;
              cout << "1. Name" << endl <<
                      "2. Number of Exams" << endl <<
                      "3. Student Capacity" << endl <<
                      "4. Professor Taught by" << endl <<
                      "5. Cancel (Return Back)" << endl <<
                      "Option: ";
            //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
              int input3;
              string input4;
              cin >> input3;


              switch (input3) {
                case 1:
                  cout << endl << "Input New Name: ";
                  cin >> input4;
                  c[input2-1].setName(input4);
                  cout << endl << "Process Complete" << endl;

                  system("PAUSE");
                  system("CLS");

                  MainMenu(fin,c,x);
                  break;

                case 2:
                  cout << endl << "Input New Exam number: ";
                  int exam;
                  cin >> exam;
                  c[input2-1].setnumgrades(exam);
                  cout << endl << "Process Complete" << endl;

                  system("PAUSE");
                  system("CLS");

                  MainMenu(fin,c,x);
                  break;

                case 3:
                    cout << endl << "Input New Student Capacity: ";
                    int cap;
                    cin >> cap;
                    c[input2-1].setcap(cap);
                    cout << endl << "Process Complete" << endl;

                    system("PAUSE");
                    system("CLS");

                    MainMenu(fin,c,x);
                	  system("CLS");
                    break;

                  case 4:
                    cout << endl << "Input New Name: ";
                    cin >> input4;
                    c[input2-1].setInstructor(input4);
                    cout << endl << "Process Complete" << endl;

                    system("PAUSE");
                    system("CLS");

                    MainMenu(fin,c,x);
                    break;

                  case 5:
                    system("CLS");
                    MainMenu(fin,c,x);
                    break;

                default:
                  cout << "That option is invalid!" << endl << endl;
                }
              }
          //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
              break;
            case 3:
                system("CLS");
                MainMenu(fin,c,x);
                break;
        		}
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
