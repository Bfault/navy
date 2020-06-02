/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** game_loop.c
*/

#include "navy.h"

void draw_board(char **land)
{
    char num[1];
    char alpha[1];

    my_fwr(1, " |");
    for (int i = 2; i < 17; i++) {
        alpha[0] = 64 + i / 2;
        my_fwr(1, (i % 2 == 0) ? alpha : " ");
    }
    my_fwr(1, "\n");
    for (int i = 0; i < 17; i++)
        my_fwr(1, (i == 1) ? "+" : "-");
    my_fwr(1, "\n");
    for (int i = 0; land[i]; i++) {
        num[0] = i + 49;
        my_fwr(1, num);
        my_fwr(1, "|");
        my_fwr(1, land[i]);
        my_fwr(1, "\n");
    }
}

void print_board(char **land, char **enemy_land)
{
        my_fwr(1, "\n");
        my_fwr(1, "my positions:\n");
        draw_board(land);
        my_fwr(1, "\n");
        my_fwr(1, "enemy's positions:\n");
        draw_board(enemy_land);
}

int who_win(cargo_t *cg)
{
    if (cg->m_ship_down == 14) {
        my_fwr(1, "Enemy won\n");
        return (0);
    } else {
        my_fwr(1, "I won\n");
        return (1);
    }
}

void msg_loop(int turn, char *aim, cargo_t *cg)
{
    if (turn == 1) {
        my_fwr(1, "\nattack: ");
        while (attack(aim = get_stdin(), cg->enemy_pid))
            my_fwr(1, "wrong position\nattack: ");
        print_touch(get_bin(), aim, cg);
        if (cg->m_ship_down == 14 || cg->h_ship_down == 14) return;
        my_fwr(1, "\nwaiting for enemy's attack...\n");
        check_touch(get_bin(), cg);
    } else {
        my_fwr(1, "\nwaiting for enemy's attack...\n");
        check_touch(get_bin(), cg);
        if (cg->m_ship_down == 14 || cg->h_ship_down == 14) return;
        my_fwr(1, "\nattack: ");
        while (attack(aim = get_stdin(), cg->enemy_pid))
            my_fwr(1, "wrong position\nattack: ");
        print_touch(get_bin(), aim, cg);
    }
}

int game_loop(cargo_t *cg, int turn)
{
    char *aim = NULL;

    while (cg->m_ship_down < 14 && cg->h_ship_down < 14) {
        print_board(cg->land, cg->enemy_land);
        msg_loop(turn, aim, cg);
    }
    print_board(cg->land, cg->enemy_land);
    my_fwr(1, "\n");
    return (who_win(cg));
}