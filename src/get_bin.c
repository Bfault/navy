/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** get_bin.c
*/

#include "navy.h"

int get_bin(void)
{
    int pow = 0;
    int result = 0;

    for (int i = 0; i < 12; i++, pow++) {
        pause();
        if (global_var == 1) {
            result += my_pow(2, pow);
        }
    }
    return (result);
}