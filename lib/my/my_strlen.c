/*
** EPITECH PROJECT, 2023
** Pool day 03
** File description:
** <placeholder>
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
