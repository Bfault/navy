/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** player_2.c
*/

#include "navy.h"

int player_2(int enemy_pid, int fd, char *file, cargo_t *cg)
{
    int **pos_ship = NULL;

    cg->land = NULL;
    cg->enemy_pid = 0;
    cg->enemy_pid = enemy_pid;
    set_signal();
    close(fd);
    pos_ship = open_and_read(file);
    draw_pid();
    send_pid(enemy_pid);
    if (get_bin() == 84)
        my_fwr(1, "successfully connected\n");
    cg->land = set_ship_on_board(cg->land, pos_ship);
    cg->enemy_land = set_ship_on_board(cg->land, NULL);
    return (game_loop(cg, -1));
}
