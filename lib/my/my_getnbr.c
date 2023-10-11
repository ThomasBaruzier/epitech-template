/*
** EPITECH PROJECT, 2023
** Pool day 03
** File description:
** <placeholder>
*/

#include "my.h"

int suite(char *number_str, int number_pos, int minus_count)
{
    char *number_rev = my_revstr(number_str);
    long int final_num = 0;
    long int p10 = 1;

    number_str[number_pos] = '\0';
    for (int i = 0; number_rev[i] != '\0'; i++) {
        if (number_pos > 12)
            return 0;
        final_num += p10 * (number_rev[i] - 48);
        p10 *= 10;
    }
    if (minus_count % 2 == 1)
        final_num *= -1;
    if (final_num < -2147483648 || final_num > 2147483647)
        return 0;
    return final_num;
}

int count_minus(char const *str)
{
    int minus_count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-')
            minus_count++;
        if (str[i] == '+' || str[i] == '-')
            continue;
        break;
    }
    return minus_count;
}

int my_getnbr(char const *str)
{
    char number_str[1000];
    int number_pos = 0;
    int minus_count = count_minus(str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 48 && str[i] < 58) {
            number_str[number_pos] = str[i];
            number_pos++;
            number_str[number_pos] = '\0';
            continue;
        }
        if ((str[i] == '+' || str[i] == '-') && number_pos == 0)
            continue;
        break;
    }
    return suite(number_str, number_pos, minus_count);
}
