/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** main.c
*/

#include "navy.h"

int main(int ac, char **av)
{
    int fd = -1;
    cargo_t cg;

    cg.m_ship_down = 0;
    cg.h_ship_down = 0;
    global_var = -1;
    if (usage(ac, av))
        return (0);
    if ((ac != 2 && ac != 3) ||
    (fd = (ac == 3) ? open(av[2], O_RDONLY) : open(av[1], O_RDONLY)) == -1)
        return (error_msg(84, "Invalid input.\n"));
    if (ac == 2 && test_file(fd))
        return (player_1(fd, av[1], &cg));
    else if (ac == 3 && test_pid(my_atoi(av[1])) && test_file(fd))
        return (player_2(my_atoi(av[1]), fd, av[2], &cg));
    return (84);
}