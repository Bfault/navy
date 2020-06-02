/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** send_bin.c
*/

#include "navy.h"

void send_bin(int nbr, int enemy_pid)
{
    char *table = binary_convert(&nbr, 1);
    struct timespec time = {0, 1000000};
    struct timespec tmp;
    int len = my_strlen(table);

    while (len < 12) {
        table = fusion_word(table, "0", NULL);
        len++;
    }
    for (int i = 0; table[i]; i++) {
        nanosleep(&time, &tmp);
        if (table[i] == '1')
            kill(enemy_pid, SIGUSR2);
        else
            kill(enemy_pid, SIGUSR1);
    }
    free(table);
}