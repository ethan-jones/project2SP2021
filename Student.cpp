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
  return false;
}
bool operator != (const Student &s2)
{
  return id == s2.id;
}
bool operator == (const Student &s2)
{
  return id == s2.id;
}
//operator < to check if the id of this object is less than s2.id
bool operator < (const Student &s2)
{
  return id < s2.id;
}

//operator > to check if the id of this object is greater than s2.id
bool operator > (const Student &s2)
{
  return id > s2.id;
}

