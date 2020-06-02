/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** set_ship_on_board.c
*/

#include "navy.h"

void free_ship_pos(int **ship_pos)
{
    for (int i = 0; ship_pos[i]; i++)
        free(ship_pos[i]);
    free(ship_pos);
}

char **set_ship(char **land, int **shit_pos)
{
    int test = 0;
    int pos_x = 0;
    int pos_y = 0;

    for (int i = 0; shit_pos[i]; i++)
        for (int j = 0; shit_pos[i][j]; j++, pos_x = 0, pos_y = 0) {
            test = shit_pos[i][j];
            while (test >= 8) {
                test -= 8;
                pos_y++;
            }
            pos_x = test;
            land[pos_y][(pos_x * 2)] = i + 50;
        }
    return (land);
}

char **set_board(char **land)
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 16; j++)
            land[i][j] = (j % 2 == 0) ? '.' : ' ';
    return (land);
}

char **set_ship_on_board(char **land, int **ship_pos)
{
    land = malloc(sizeof(char *) * 9);
    land[8] = NULL;
    for (int i = 0; i < 8; i++)
        land[i] = my_malloc(sizeof(char) * 17);
    land[8] = NULL;
    set_board(land);
    if (ship_pos != NULL) {
        land = set_ship(land, ship_pos);
        free_ship_pos(ship_pos);
    }
    return (land);
}