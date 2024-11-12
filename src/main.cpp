#include "../include/functions.h"
#include "../include/structures.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  int N;

  cout << "Введіть N: "; cin >> N;

  Student *s = new Student[N];

  Create(s, N);
  Print(s, N);

  string surname;
  int speciality;
  float average_mark;
  int found;
  int menuItem;

  do {
    cout << endl << endl << endl;
    cout << "Меню:\n";
    cout << "1. Впорядкувати за середнім балом -> назвою спеціальності -> за прізвищем\n";
    cout << "2. Створити індексний масив впорядкований за середнім балом -> назвою спеціальності -> за прізвищем\n";
    cout << "3. Перевірити, де навчається студент\n";
    cout << "0. вихід та завершення роботи програми" << endl << endl;
    cout << "Введіть значення: "; cin >> menuItem;
    cout << endl << endl << endl;

    switch ( menuItem )
    {
      case 1:
        Sort(s, N);
        Print(s, N);
      break;
      case 2:
        PrintIndexSorted(s, IndexSort(s, N), N);
        break;
      case 3:
        cout << "Введіть ключі пошуку:" << endl;
        cout << "прізвище: ";
        cin >> surname;

        cout << "спеціальність: ";
        cin >> speciality;

        cout << "середній бал: ";
        cin >> average_mark;


        if ( (found = BinSearch(s, N, surname, average_mark, speciality)) != -1 )
          cout << "Знайдено студента в позиції " << found+1 << endl;
        else
          cout << "Шуканого студента не знайдено" << endl;
        break;
      case 0:
        break;
      default:
        cout << "Ви ввели помилкове значення! "
        "Слід ввести число - номер вибраного пункту меню" << endl;
    }
  } while ( menuItem != 0 );

  return 0;
}