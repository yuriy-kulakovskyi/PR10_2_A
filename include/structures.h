#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <string>
#include <iostream>

enum Speciality {
  COMPUTER_SCIENCE,
  INFORMATIONAL_SYSTEMS_AND_TECHNOLOGIES,
  TOURISM,
  CYBER_SECURITY,
  COMPUTER_ENGINEERING,
  SYSTEMS_ANALYSIS
};

std::istream& operator>>(std::istream& is, Speciality& speciality);
std::ostream& operator<<(std::ostream& os, const Speciality& speciality);

struct Student {
  std::string surname;
  int studying_year;
  Speciality speciality;
  int physics_mark;
  int math_mark;
  int informatics_mark;
};

#endif // STRUCTURES_H