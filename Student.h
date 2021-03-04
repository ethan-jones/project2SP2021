#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>

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
  bool operator>(const Student& y);
  bool operator<(const Student& y);
  friend ostream& operator<<(ostream& os, const Student& s);
  friend istream& operator>>(istream& is, Student& s);
  
private:
  int id;
  string name;
};

#endif
  
