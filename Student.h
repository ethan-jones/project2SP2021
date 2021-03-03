#ifndef STUDENT_H
#define STUDENT_H
#include <string>

using namespace std;

class Student {
public:
  Student();
  Student(int i, string j);
  int getID();
  void setID(int newID);
  string getName();
  void setName(string newName);
  bool operator==(const Student& y);
private:
  int studentID;
  string studentName;
};

#endif
  
