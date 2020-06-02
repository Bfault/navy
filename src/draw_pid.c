/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** draw_start.c
*/

#include "navy.h"

void draw_pid(void)
{
    my_fwr(1, "my_pid: ");
    my_putnbr(getpid());
    my_fwr(1, "\n");
}