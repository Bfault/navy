/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** receive_attack.c
*/

#include "navy.h"

int is_ship(char ch)
{
    for (int i = 50; i < 54; i++)
        if (ch == i)
            return (1);
    return (0);
}

void check_touch(int pos, cargo_t *cg)
{
    int pos_x = pos % 8;
    int pos_y = (pos - pos_x) / 8;

    if (is_ship(cg->land[pos_y][pos_x * 2])) {
        cg->land[pos_y][pos_x * 2] = 'x';
        send_bin(99, cg->enemy_pid);
        cg->m_ship_down++;
        my_putchar(pos_x + 65);
        my_putchar(pos_y + 49);
        my_fwr(1, ": hit\n");
    } else {
        if (cg->land[pos_y][pos_x * 2] != 'x') {
            cg->land[pos_y][(pos_x) * 2] = 'o';
            send_bin(100, cg->enemy_pid);
        } else
            send_bin(101, cg->enemy_pid);
        my_putchar(pos_x + 65);
        my_putchar(pos_y + 49);
        my_fwr(1, ": missed\n");
    }
}

void write_enemy_land(char *aim, cargo_t *cg, int choice)
{
    int pos_x = aim[0] - 65;
    int pos_y = aim[1] - 49;

    if (choice) {
        cg->enemy_land[pos_y][pos_x * 2] = 'x';
        cg->h_ship_down++;
    }
    else
        cg->enemy_land[pos_y][pos_x * 2] = 'o';
}

void print_touch(int choice, char *pos, cargo_t *cg)
{
    if (choice == 99) {
        my_fwr(1, pos);
        my_fwr(1, ": hit\n");
        write_enemy_land(pos, cg, 1);
    } else if (choice == 100) {
        my_fwr(1, pos);
        my_fwr(1, ": missed\n");
        write_enemy_land(pos, cg, 0);
    } else {
        my_fwr(1, pos);
        my_fwr(1, ": missed\n");
    }
}