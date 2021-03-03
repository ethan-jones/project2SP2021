#include "Student.h"

Student::Student() {
  studentID = 0;
  studentName = "N/A";
}

Student::Student(int newId, string newName) {
  studentID = newId;
  studentName = newName;
}

string Student::getName() {
  return studentName;
}

int Student::getID() {
  return studentID;
}

void Student::setName(string newName) {
  studentName = newName;
}

void Student::setID(int newID) {
  studentID = newID;
}

bool Student::operator==(const Student& y) {
  if (studentID == y.studentID && studentName == y.studentName) {
    return true;
  }
  return false;
}
