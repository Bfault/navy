/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** test_pid.c
*/

#include "navy.h"

int test_pid(int pid)
{
    return (kill(pid, 0) == 0 ? 1 : 0);
}