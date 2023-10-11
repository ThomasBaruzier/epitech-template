/*
** EPITECH PROJECT, 2023
** Pool day 03
** File description:
** Placeholder
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    if (nb == 1)
        return 1;
    for (int i = 0; i < nb; i++) {
        if (i * i == nb)
            return i;
    }
    return 0;
}
