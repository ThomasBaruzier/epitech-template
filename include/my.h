/*
** EPITECH PROJECT, 2023
** Pool day 03
** File description:
** Placeholder
*/

#include <unistd.h>

#ifndef FUNCTIONS_H
    #define FUNCTIONS_H

int my_add(int a, int b);

#endif

#ifndef LIBMY_H
    #define LIBMY_H

char *my_revstr(char *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_isneg(int n);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
int my_strncmp(char const *s1, char const *s2, int n);
int my_strncmp_rev(char const *str, char const *to_find, int n);
void my_putchar(char c);
void my_sort_int_array(int *array, int size);
void my_swap(int *a, int *b);

#endif
