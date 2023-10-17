/*
** EPITECH PROJECT, 2023
** my_strncpy
** File description:
** my_strncpy
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        if (src[i] != '\0')
            dest[i] = src[i];
        else
            dest[i] = '\0';
    }
    return dest;
}
