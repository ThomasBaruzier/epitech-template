/*
** EPITECH PROJECT, 2023
** Pool day 03
** File description:
** Placeholder
*/

#include "my.h"

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 97 || str[i] > 122) && (str[i] < 65 || str[i] > 90))
            return 0;
    }
    return 1;
}
