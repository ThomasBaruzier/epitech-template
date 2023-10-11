/*
** EPITECH PROJECT, 2023
** Pool day 03
** File description:
** Placeholder
*/

#include "my.h"

char *my_revstr(char *str)
{
    int len;
    char tmp;

    for (len = 0; str[len] != '\0'; len++)
        continue;
    for (int i = 0; i < len / 2; i++) {
        tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
    return str;
}
