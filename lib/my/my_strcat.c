/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int len;
    int j = 0;

    for (len = 0; dest[len] != '\0'; len++)
        continue;
    for (int i = len; src[j] != '\0'; i++) {
        dest[i] = src[j];
        j++;
    }
    return dest;
}
