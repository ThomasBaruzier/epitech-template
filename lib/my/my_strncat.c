/*
** EPITECH PROJECT, 2023
** Pool day 03
** File description:
** Placeholder
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int len;
    int j = 0;

    for (len = 0; dest[len] != '\0'; len++)
        continue;
    for (int i = len; src[j] != '\0' && j < nb; i++) {
        dest[i] = src[j];
        j++;
    }
    return dest;
}
