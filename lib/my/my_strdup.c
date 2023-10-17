/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** my_strdup
*/

#include "my.h"

char *my_strdup(char const *src)
{
    int len;
    char *dest;

    for (len = 0; src[len] != '\0'; len++)
        continue;
    dest = (char *)malloc(sizeof(char) * (len + 1));
    my_strcpy(dest, src);
    return dest;
}
