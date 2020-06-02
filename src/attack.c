/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** attack.c
*/

#include "navy.h"

int check_aim(char *aim)
{
    if (my_strlen(aim) != 2) return (1);
    if (aim[0] < 65 || aim[0] > 72) return (1);
    if (aim[1] < 49 || aim[1] > 56) return (1);
    return (0);
}

int attack(char *aim, int enemy_pid)
{
    int result = 0;

    if (check_aim(aim)) return (1);
    result = aim[0] - 65 + (aim[1] - 49) * 8;
    send_bin(result, enemy_pid);
    return (0);
}