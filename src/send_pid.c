/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** send_pid.c
*/

#include "navy.h"

void send_pid(int enemy_pid)
{
    kill(enemy_pid, SIGUSR1);
}