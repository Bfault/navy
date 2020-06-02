/*
** EPITECH PROJECT, 2019
** lib
** File description:
** ls_create.c
*/

#include "lklist.h"
#include "my.h"

lklist_t *ls_create(void *data)
{
    lklist_t *car = malloc(sizeof(lklist_t));

    if (!car)
        return (0);
    car->data = data;
    car->next = 0;
    return (car);
}