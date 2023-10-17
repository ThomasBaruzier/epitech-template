/*
** EPITECH PROJECT, 2023
** my_find_prime_sup
** File description:
** my_find_prime_sup
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    for (int i = nb; ; i++)
        if (my_is_prime(i))
            return i;
}
