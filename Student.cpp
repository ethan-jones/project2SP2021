#include "Student.h"

Student::Student() {
  id = 0;
  name = "N/A";
}

Student::Student(int newId, string newName) {
  id = newId;
  name = newName;
}

string Student::getName() {
  return name;
}

int Student::getID() {
  return id;
}

void Student::setName(string newName) {
  name = newName;
}

void Student::setID(int newID) {
  id = newID;
}
/*
bool Student::operator==(const Student& y) {
  if (id == y.id) {
    return true;
  }
  return false;
}

bool Student::operator>(const Student& y) {
  if (id > y.id) {
    return true;
  }
  return false;
}

bool Student::operator<(const Student& y) {
  if (id < y.id) {
    return true;
  }
  return false;
}
*/

