/*
** EPITECH PROJECT, 2023
** Pool day 03
** File description:
** <placeholder>
*/

#include "my.h"

void swap(int *a, int *b)
{
    int swap;

    if (*a > *b) {
        swap = *a;
        *a = *b;
        *b = swap;
    }
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            swap(&array[j], &array[j + 1]);
        }
    }
}
