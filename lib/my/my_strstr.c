/*
** EPITECH PROJECT, 2023
** Pool day 03
** File description:
** Placeholder
*/

#include "my.h"

int my_strncmp_rev(char const *str, char const *to_find, int n)
{
    int i = 0;
    int j = 0;
    int str_len;
    int to_find_len;

    for (str_len = n; str[str_len] != '\0'; str_len++)
        continue;
    for (to_find_len = 0; to_find[to_find_len] != '\0'; to_find_len++)
        continue;
    if (to_find_len > str_len)
        return 0;
    for (i = n; i < str_len && j < to_find_len; i++) {
        if (str[i] < to_find[j] || str[i] > to_find[j])
            return 0;
        j++;
    }
    return 1;
}

char *my_strstr(char *str, char const *to_find)
{
    if (str[0] == '\0' && to_find[0] == '\0')
        return &str[0];
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_strncmp_rev(str, to_find, i) == 1)
            return &str[i];
    }
    return 0;
}
