/*
** EPITECH PROJECT, 2023
** Pool day 03
** File description:
** Placeholder
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    for (int i = nb; ; i++)
        if (my_is_prime(i))
            return i;
}
