/*
** EPITECH PROJECT, 2019
** lib_uni
** File description:
** my.h
*/

#ifndef _MY_H_
#define _MY_H_

#include "my_macro.h"
#include "lklist.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

char *add_char(char *, char);
int alphanumeric(char *, char , ...);
int char_in_str(char *, char);
char *del_from(char *, char *);
int error_msg(int, char *);
char *fusion_word(char *, ...);
char *get_next_line(int);
char *get_stdin(void);
int isnum(char *);
/*___________LINKED_LIST_____________________**/
lklist_t *ls_add(lklist_t *, void *, int);  /**/
lklist_t *ls_create(void *);                /**/
int ls_empty(lklist_t *);                   /**/
lklist_t *ls_free(lklist_t *);              /**/
void *ls_get(lklist_t *, int);              /**/
size_t ls_len(lklist_t *);                  /**/
lklist_t *ls_rm(lklist_t *, int);           /**/
void ls_set(lklist_t *, void *, int);       /**/
/*___________________________________________**/
int my_atoi(char *);
void *my_free(void *);
void my_fwr(int, char *);
void *my_malloc(int);
int my_pow(int, int);
void my_putchar(char);
void my_putnbr(int);
char *my_strdup(char *);
int my_strlen(char *);
char *prefix_del(char *, char *);
char *replace_in(char *, char *, char *);
char *reverse_str(char *);
char **str_to_word_array(char *);
int strc(char *, char *);
char *word_array_to_str(char **);

#endif