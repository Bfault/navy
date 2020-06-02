/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** navy.h
*/

#ifndef _NAVY_H_
#define _NAVY_H_

#define _XOPEN_SOURCE 700

#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>
#include "my.h"
#include <stdio.h>

int global_var;

typedef struct cargo
{
    int pid;
    int enemy_pid;
    char **land;
    char **enemy_land;
    int m_ship_down;
    int h_ship_down;
} cargo_t;

int usage(int, char **);
int test_file(int);
int test_pid(int);
int **open_and_read(char *);
int player_1(int, char *, cargo_t *);
int player_2(int, int, char *, cargo_t *);
void draw_pid(void);
void draw_connection_1(void);
int game_loop(cargo_t *, int);
void send_pid(int);
int receive_pid(void);
void set_signal(void);
void send_bin(int, int);
int get_bin(void);
void *binary_convert(void *, int);
char **set_ship_on_board(char **, int **);
int attack(char *, int);
void check_touch(int, cargo_t *);
void print_touch(int, char *, cargo_t *);

#endif