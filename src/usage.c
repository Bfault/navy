/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** usage.c
*/

#include "navy.h"

int print_usage(void)
{
    my_fwr(0, CYAN_BRIGHT);
    my_fwr(1, "USAGE\n     ./navy [first_player_pid] navy_positions\nDESCRIP");
    my_fwr(1, "TION\n     first_player_pid: only for the 2nd player. pid of ");
    my_fwr(1, "the first player.\n     navy_positions: file representing the");
    my_fwr(1, " positions of the ships.\n");
    my_fwr(0, NORMAL_BRIGHT);
    return (1);
}

int usage(int ac, char **av)
{
    if (ac == 2 && strc(av[1], "-h"))
        return (print_usage());
    return (0);
}