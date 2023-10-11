/*
** EPITECH PROJECT, 2023
** Pool day 03
** File description:
** Placeholder
*/

#include <criterion/criterion.h>
#include "my.h"

Test (my_revstr, test_my_revstr)
{
    char str[15];

    strcpy(str, "Hello");
    my_revstr(str);
    cr_assert_str_eq(str, "olleH");
}
