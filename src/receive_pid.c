/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** receive_pid.c
*/

#include "navy.h"

int receive_pid(void)
{
    int pid = 0;

    pause();
    pid = global_var;
    global_var = 0;
    return (pid);
}