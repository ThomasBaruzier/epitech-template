/*
** EPITECH PROJECT, 2023
** Pool day 03
** File description:
** Placeholder
*/

#include "my.h"

int my_is_prime(int nb)
{
    if (nb < 2)
        return 0;
    for (int i = 2; i * i <= nb; i++)
        if (nb / i * i == nb)
            return 0;
    return 1;
}
