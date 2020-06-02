/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** binary_convert.c
*/

#include "navy.h"

void *dec_to_bin(int msg)
{
    char *result = NULL;
    int count = 0;
    int j = 0;

    for (int i = msg; i != 0; i = i / 2, i -= i % 2)
        count++;
    result = my_malloc(sizeof(char) * count + 2);
    for (int i = msg; i != 0; i -= i % 2, i /= 2, j++) {
        if (i % 2 == 1)
            result[j] = '1';
        else
            result[j] = '0';
    }
    return (result);
}

void *bin_to_dec(char *msg)
{
    void *result = 0;

    for (int i = 0; msg[i]; i++)
        if (msg[i] == 1)
            *(int *)result += my_pow(2, i);
    return (result);
}

void *binary_convert(void *msg, int choice)
{
    void *result = NULL;

    if (choice)
        result = dec_to_bin(*(int *)msg);
    if (!choice)
        result = bin_to_dec((char *)msg);
    return (result);
}