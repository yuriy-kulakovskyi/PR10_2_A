#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structures.h"

void Create(Student *s, int N);
void Print(Student *s, int N);
float CountAverageMark(Student *s, int i);
void Sort(Student *s, int N);
int *IndexSort(Student *s, int N);
void PrintIndexSorted(Student *s, int *index, int N);
int BinSearch(Student *p, int N, std::string surname, float average_mark, int speciality);


#endif
