#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdlib.h>
void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);
int getMaximum(int *array, int size);
int getDigit(int number, int n);
void countingSort(int *array, int exp, int size);
#endif /* SORT_H */
