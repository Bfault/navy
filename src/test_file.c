/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** file_error_handling.c
*/

#include "navy.h"

int check_offset(int const *ship, char *buffer, int length)
{
    int test = 0;

    if (buffer[2] < 65 || buffer[2] > 72 || buffer[3] < 49 || buffer[3] > 56 ||
    buffer[5] < 65 || buffer[5] > 72 || buffer[6] < 49 || buffer[6] > 56)
        return (error_msg(1,
        "Ship can only be place between A and H and 1 and 8.\n"));
    if (buffer[5] == buffer[2] && buffer[6] == buffer[3])
        return (error_msg(1, "Ship can't have a lenght of 0.\n"));
    if (buffer[5] != buffer[2])
        test = buffer[5] - buffer[2] + 1;
    else
        test = buffer[6] - buffer[3] + 1;
    if (test != length)
        return (error_msg(1, "Lenght different with given cords.\n"));
    if (ship[length - 2] == 1)
        return (error_msg(1, "Lenght already use.\n"));
    return (test);
}

int check_buffer(char *buffer)
{
    static int ship[4] = {0};
    int length = 0;

    if (my_strlen(buffer) != 7)
        return (error_msg(1, "Use LENGTH:FIRST_SQUARE:LAST_SQUARE format.\n"));
    if (buffer[1] != ':' || buffer[4] != ':' || (buffer[7] != 0))
        return (error_msg(1, "Use LENGTH:FIRST_SQUARE:LAST_SQUARE format.\n"));
    if (buffer[2] != buffer[5] && buffer[3] != buffer[6])
        return (error_msg(1, "Ship can't be set in diagonal.\n"));
    length = check_offset(ship, buffer, buffer[0] - 48);
    if (length == 1) return (1);
    ship[length - 2] = 1;
    return (0);
}

int test_file(int fd)
{
    int count = 0;
    char *buffer = NULL;

    while ((buffer = get_next_line(fd))) {
        if (check_buffer(buffer)) return (0);
        count++;
    }
    if (count != 4)
        return (error_msg(0, "only 4 ships are managed.\n"));
    return (1);
}