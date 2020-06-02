/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** player_1.c
*/

#include "navy.h"

int player_1(int fd, char *file, cargo_t *cg)
{
    int **pos_ship = NULL;

    cg->land = NULL;
    cg->enemy_pid = 0;
    set_signal();
    close(fd);
    pos_ship = open_and_read(file);
    draw_pid();
    draw_connection_1();
    cg->enemy_pid = receive_pid();
    if (cg->enemy_pid != 0) {
        send_bin(84, cg->enemy_pid);
        my_fwr(1, "enemy connected\n");
    }
    cg->land = set_ship_on_board(cg->land, pos_ship);
    cg->enemy_land = set_ship_on_board(cg->land, NULL);
    return (game_loop(cg, 1));
}