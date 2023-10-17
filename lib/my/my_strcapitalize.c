/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include "my.h"

static char upcase(char character)
{
    if (character >= 97 && character <= 122)
        character -= 32;
    return character;
}

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (i == 0 || str[i - 1] == '-' || str[i - 1] == '+') {
            str[i] = upcase(str[i]);
            continue;
        }
        if (i == 0 || str[i - 1] == ' ') {
            str[i] = upcase(str[i]);
            continue;
        }
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
    }
    return str;
}
