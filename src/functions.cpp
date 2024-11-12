#include "../include/functions.h"
#include "../include/structures.h"
#include <iostream>
#include <string>
#include <iomanip>

std::ostream& operator<<(std::ostream& os, const Speciality& speciality) {
  switch (speciality) {
    case COMPUTER_SCIENCE: os << "COMPUTER_SCIENCE"; break;
    case INFORMATIONAL_SYSTEMS_AND_TECHNOLOGIES: os << "INFORMATIONAL_SYSTEMS_AND_TECHNOLOGIES"; break;
    case TOURISM: os << "TOURISM"; break;
    case CYBER_SECURITY: os << "CYBER_SECURITY"; break;
    case COMPUTER_ENGINEERING: os << "COMPUTER_ENGINEERING"; break;
    case SYSTEMS_ANALYSIS: os << "SYSTEMS_ANALYSIS"; break;
  }
  return os;
}

std::istream& operator>>(std::istream& is, Speciality& speciality) {
  int value;
  is >> value;
  speciality = static_cast<Speciality>(value);
  return is;
}

using namespace std;

void Create(Student *s, const int N)
{
  for (int i = 0; i < N; i++)
  {
    cout << "Студент № " << i + 1 << ":" << endl;
    cin.get();
    cin.sync();
    cout << " прізвище: "; getline(cin, s[i].surname);
    cout << " курс: "; cin >> s[i].studying_year;
    cout << " спеціальність: "; cin >> s[i].speciality;
    cout << " оцінка з фізики: "; cin >> s[i].physics_mark;
    cout << " оцінка з математики: "; cin >> s[i].math_mark;
    cout << " оцінка з інформатики: "; cin >> s[i].informatics_mark;
    cout << endl;
  }
}

void Print(Student *s, const int N) {
  cout << "========================================================================================================================\n";
  cout << "|   № | Прізвище     | Курс  | Спеціальність                           | Оц(Фізика) | Оц(Математика) | Оц(Інформатика) |\n";
  cout << "------------------------------------------------------------------------------------------------------------------------\n";
  for (int i = 0; i < N; i++) {
    cout << "| " << setw(3) << right << i + 1 << " ";
    cout << "| " << setw(22) << left << s[i].surname
         << " | " << setw(4) << right << s[i].studying_year << " "
         << " | " << setw(40) << left << s[i].speciality
         << "| " << setw(10) << right << s[i].physics_mark << " "
         << "| " << setw(14) << right << s[i].math_mark << " "
         << "| " << setw(15) << right << s[i].informatics_mark << " |" << endl;
  }
  cout << "========================================================================================================================\n";
}

float CountAverageMark(Student *s, int i) {
  return (s[i].informatics_mark + s[i].math_mark + s[i].physics_mark) / 3.0;
}

void Sort(Student *s, const int N)
{
  Student tmp;
  for (int i0 = 0; i0 < N - 1; i0++) {
    for (int i1 = 0; i1 < N - i0 - 1; i1++) {
      if ((CountAverageMark(s, i1) < CountAverageMark(s, i1 + 1)) ||
          (CountAverageMark(s, i1) == CountAverageMark(s, i1 + 1) && s[i1].speciality > s[i1 + 1].speciality) ||
          (CountAverageMark(s, i1) == CountAverageMark(s, i1 + 1) && s[i1].speciality == s[i1 + 1].speciality && s[i1].surname > s[i1 + 1].surname)) {
        tmp = s[i1];
        s[i1] = s[i1 + 1];
        s[i1 + 1] = tmp;
          }
    }
  }
}

int *IndexSort(Student *s, const int N)
{
  int *I = new int[N];
  for (int i=0; i<N; i++)
    I[i]=i;
  int i, j, value;
  for (i = 1; i < N; i++)
  {
    value = I[i];
    for (j = i - 1;
    j >= 0 && ((CountAverageMark(s, j) < CountAverageMark(s, j + 1)) ||
          (CountAverageMark(s, j) == CountAverageMark(s, j + 1) && s[j].speciality > s[j + 1].speciality) ||
          (CountAverageMark(s, j) == CountAverageMark(s, j + 1) && s[j].speciality == s[j + 1].speciality && s[j].surname > s[j + 1].surname)) ;
    j--)
    {
      I[j + 1] = I[j];
    }
    I[j + 1] = value;
  }
  return I;
}

void PrintIndexSorted(Student *s, int *I, const int N) {
  cout << "========================================================================================================================\n";
  cout << "|   № | Прізвище     | Курс  | Спеціальність                           | Оц(Фізика) | Оц(Математика) | Оц(Інформатика) |\n";
  cout << "------------------------------------------------------------------------------------------------------------------------\n";
  for (int i = 0; i < N; i++) {
    cout << "| " << setw(3) << right << i + 1 << " ";
    cout << "| " << setw(22) << left << s[I[i]].surname
         << " | " << setw(4) << right << s[I[i]].studying_year << " "
         << " | " << setw(40) << left << s[I[i]].speciality
         << "| " << setw(10) << right << s[I[i]].physics_mark << " "
         << "| " << setw(14) << right << s[I[i]].math_mark << " "
         << "| " << setw(15) << right << s[I[i]].informatics_mark << " |" << endl;
  }
  cout << "========================================================================================================================\n";
}

int BinSearch(Student *p, const int N, const string surname, const float average_mark, const int speciality)
{
  int left = 0, right = N - 1, middle;
  while (left <= right)
  {
    middle = (left + right) / 2;
    if (p[middle].surname == surname && CountAverageMark(p, middle) == average_mark && p[middle].speciality == speciality)
      return middle;
    if (p[middle].surname > surname || (p[middle].surname == surname && CountAverageMark(p, middle) > average_mark) || (p[middle].surname == surname && CountAverageMark(p, middle) == average_mark && p[middle].speciality > speciality))
      right = middle - 1;
    else
      left = middle + 1;
  }
  return -1;
}