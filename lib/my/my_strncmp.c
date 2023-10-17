/*
** EPITECH PROJECT, 2023
** my_strncmp
** File description:
** my_strncmp
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int len;

    if (n < 0) {
        for (len = 0; s1[len] != '\0'; len++)
            continue;
        n = len + 1;
    }
    for (int i = 0; i < n; i++) {
        if (s1[i] == s2[i])
            continue;
        if (s1[i] < s2[i] || s1[i] > s2[i])
            return s1[i] - s2[i];
    }
    return 0;
}
