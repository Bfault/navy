/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** signal.c
*/

#include "navy.h"

static void bin(int sig, siginfo_t *siginfo, void *context)
{
    (void)context;
    if (global_var == -1) {
        global_var = siginfo->si_pid;
        return;
    }
    if (sig == SIGUSR1)
        global_var = 0;
    else if (sig == SIGUSR2)
        global_var = 1;
}

void set_signal(void)
{
    struct sigaction usr1 = {0};
    struct sigaction usr2 = {0};

    usr1.sa_sigaction = &bin;
    usr2.sa_sigaction = &bin;
    usr1.sa_flags = SA_SIGINFO;
    usr2.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &usr1, NULL);
    sigaction(SIGUSR2, &usr2, NULL);
}