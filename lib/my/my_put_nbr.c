/*
** EPITECH PROJECT, 2023
** Pool day 03
** File description:
** Placeholder
*/

#include "my.h"

void printall(long p10, long new_nb, long i)
{
    while (i > 0) {
        p10 /= 10;
        my_putchar(((new_nb / p10) % 10) + 48);
        i--;
    }
}

int my_put_nbr(int nb)
{
    long p10 = 10;
    long div = 1;
    long neg = 0;
    long new_nb = nb;
    long i;

    if (new_nb < 0) {
        new_nb *= -1;
        neg = 1;
    }
    for (i = 0; div >= 1; i++) {
        div = new_nb / p10;
        p10 *= 10;
    }
    if (neg == 1)
        my_putchar('-');
    p10 = p10 / 10;
    printall(p10, new_nb, i);
    return 0;
}
