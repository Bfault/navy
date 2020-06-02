/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** open_and_read.c
*/

#include "navy.h"

int condition_choose(char *buffer, int i, int choose)
{
    switch(choose)
    {
        case 0:
            if (buffer[3] > buffer[6])
                return (buffer[2] - 65 + 8 * (buffer[3] - 49) - 8 * i);
            else
                return (buffer[2] - 65 + 8 * (buffer[3] - 49) + 8 * i);
        case 1:
            if (buffer[2] > buffer[5])
                return (buffer[2] - 65 + 8 * (buffer[3] - 49) - i);
            else
                return (buffer[2] - 65 + 8 * (buffer[3] - 49) + i);
    }
    return (0);
}

int which_ship(char *buffer, int i)
{
    if (buffer[2] == buffer[5])
        return (condition_choose(buffer, i, 0));
    else
        return (condition_choose(buffer, i, 1));
}

int *save_ship(char *buffer, int *pos_ship)
{
    for (int i = 0; i < buffer[0] - 48; i++)
        pos_ship[i] = which_ship(buffer, i);
    return (pos_ship);
}

int **open_and_read(char *file)
{
    int fd = open(file, O_RDONLY);
    char *buffer = my_malloc(sizeof(char) * 8);
    int **pos_ship = NULL;

    pos_ship = malloc(sizeof(int *) * 5);
    for (int i = 0; i < 4; i++) {
        read(fd, buffer, 8);
        pos_ship[buffer[0] - 50] = malloc(sizeof(int) * (buffer[0] - 47));
    }
    close (fd);
    fd = open(file, O_RDONLY);
    for (int i = 0; i < 4; i++) {
        read(fd, buffer, 8);
        pos_ship[buffer[0] - 50] = save_ship(buffer, pos_ship[buffer[0] - 50]);
    }
    close (fd);
    free(buffer);
    return (pos_ship);
}