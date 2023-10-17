/*
** EPITECH PROJECT, 2023
** my_show_word_array
** File description:
** my_show_word_array
*/

#include "my.h"

int my_show_word_array(char const **tab)
{
    for (int i = 0; tab[i] != 0; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++)
            write(1, &tab[i][j], 1);
        write(1, "\n", 1);
    }
    return 0;
}
