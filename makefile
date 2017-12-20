CXXFLAGS := -std=c++11

# executable file to create and its dependancies
prog.exe : driver.o Course.o Instructor.o Student.o Database.o Ui.o
	g++ -std=c++11 -o prog driver.o Course.o Instructor.o Student.o Database.o Ui.o

# file dependencies
driver.o : Course.h
	g++ -std=c++11 -c driver.cpp
Course.o : Course.h
	g++ -std=c++11 -c Course.cpp
Instructor.o : Instructor.h
	g++ -std=c++11 -c Instructor.cpp
Student.o : Student.h
	g++ -std=c++11 -c Student.cpp
Database.o : Database.h
	g++ -std=c++11 -c Database.cpp
Ui.o : Ui.h
	g++ -std=c++11 -c Ui.cpp


# files to remove
clean:
	del driver.o Course.o Instructor.o Student.o Database.o Ui.o
	del prog.exe
