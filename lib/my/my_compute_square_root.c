/*
** EPITECH PROJECT, 2023
** my_compute_square_root
** File description:
** my_compute_square_root
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    if (nb == 1)
        return 1;
    for (int i = 0; i < nb; i++)
        if (i * i == nb)
            return i;
    return 0;
}
