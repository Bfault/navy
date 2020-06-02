/*
** EPITECH PROJECT, 2019
** lib_uni
** File description:
** str_to_word_array.c
*/

#include "my.h"

char **count(char *str, char **arr)
{
    int nb = 1;
    int temp;

    for (int i = 0; str[i] != 0; i++) {
        temp = str[i];
        if ((str[i + 1] == 32 || str[i + 1] == 0 || str[i + 1] == '\t')
                && temp != 32 && temp != '\t')
            nb++;
    }
    arr = malloc(sizeof(char *) * nb);
    arr[nb - 1] = NULL;
    return (arr);
}

char **sub_count(char *str, char **arr)
{
    int count = 0;
    int k = 0;

    for (int i = 0; str[i] != 0; i++, k++, count = 0) {
        while ((str[i] == 32 || str[i] == '\t') && str[i] != 0)
            i++;
        while (str[i] != 32 && str[i] != '\t' && str[i] != 0) {
            count++;
            i++;
        }
        arr[k] = my_malloc(sizeof(char) * count + 1);
        if (str[i] == 0)
            return (arr);
    }
    return (arr);
}

char **fill_arr(char *str, char **arr)
{
    int k = 0;
    int m = 0;

    for (int i = 0; str[i] != 0; i++, k++, m = 0) {
        while ((str[i] == 32 || str[i] == '\t') && str[i] != 0) {
            i++;
        }
        while (str[i] != 32 && str[i] != '\t' && str[i] != 0) {
            arr[k][m] = str[i];
            i++;
            m++;
        }
        if (str[i] == 0)
            return (arr);
    }
    return (arr);
}

char **str_to_word_array(char *str)
{
    char **arr = NULL;

    arr = count(str, arr);
    arr = sub_count(str, arr);
    arr = fill_arr(str, arr);
    return (arr);
}
