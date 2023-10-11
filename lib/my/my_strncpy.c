/*
** EPITECH PROJECT, 2023
** Pool day 03
** File description:
** Placeholder
*/

//    int i;
//    int len;
//
//    for (len = 0; src[len] != '\0'; len++)
//        continue;
//
//    for (i = 0; i < len && i < n; i++)
//       dest[i] = src[i];
//
//    if (n > len)
//        dest[i] = '\0';
//    else
//        dest[i] = '\0';

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; i < n; i++)
        if (src[i] != '\0')
            dest[i] = src[i];
        else
            dest[i] = '\0';
    return dest;
}
