/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include "my.h"

static int is_alpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return 1;
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

static int get_word_count(char const *str)
{
    int i = 0;
    int count = 0;

    for (; !is_alpha(str[i]) && str[i] != '\0'; i++)
        continue;
    if (is_alpha(str[i]))
        count++;
    for (; str[i] != '\0'; i++)
        if (!is_alpha(str[i]) && is_alpha(str[i + 1]))
            count++;
    return count;
}

static int get_word_len(char const *str, int i)
{
    for (int count = i; str[i] != 0; count++)
        if (!is_alpha(str[count]))
            return count - i;
    return 0;
}

// Debugging lines in case of failure
//    printf("Malloc for all: %d\n", word_count + 1);
//        printf("Malloc for word %d: %d\n", word, word_size + 1);
//            printf("dest[%d][%d] = %c\n", word, letter, str[str_i]);
//        printf("dest[%d][%d] = '\\0'\n", word, letter);
//    printf("dest[%d] = 0\n", word);
char **my_str_to_word_array(char const *str)
{
    int str_i = 0;
    int word = 0;
    int word_size;
    int word_count = get_word_count(str);
    char **dest = (char **)malloc(sizeof(char *) * (word_count + 1));

    for (int letter = 0; word < word_count; word++) {
        for (; !is_alpha(str[str_i]) && str[str_i] != '\0'; str_i++)
            continue;
        word_size = get_word_len(str, str_i);
        dest[word] = (char *)malloc(sizeof(char) * (word_size + 1));
        for (int limit = str_i + word_size; str_i < limit; str_i++) {
            dest[word][letter] = str[str_i];
            letter++;
        }
        dest[word][letter] = '\0';
        letter = 0;
    }
    dest[word] = 0;
    return dest;
}
