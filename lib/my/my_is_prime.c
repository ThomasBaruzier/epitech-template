/*
** EPITECH PROJECT, 2023
** my_is_prime
** File description:
** my_is_prime
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
