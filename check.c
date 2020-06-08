/*
** EPITECH PROJECT, 2019
** check sokoban
** File description:
** check
*/

#include <stdlib.h>
#include <ncurses.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "sokoban.h"
#include "soko.h"

int nb_col(char *buf, int i)
{
    int nbr = 0;

    while (buf[i + nbr] != '\n' && buf[i + nbr] != 0)
        nbr++;
    return (nbr);
}

int control_map(char *map)
{
    int player = 0;
    int object = 0;
    int box = 0;
    int i = 0;

    for (; map[i] != '\0'; i++) {
        if (map[i] == 'P')
            player = player + 1;
        if (map[i] == 'O')
            object = object + 1;
        if (map[i] == 'X')
            box = box + 1;
    }
    if (player != 1 || box != object)
        exit(84);
    else
        return (box);
}

int nb_row(char *buf)
{
    int i = 0;
    int nb_row = 0;

    for (i = 0; buf[i] != '\0'; i++){
        if (buf[i] == '\n')
            nb_row++;
    }
    return (nb_row + 1);
}

soko_t findplayer(char **my_map, char *map, soko_t *pos)
{
    int i;
    int j;
    int row = nb_row(map);

    for (i = 0; i < row; i++) {
        for (j = 0; my_map[i][j] != '\0'; j++) {
            if (my_map[i][j] == 'P') {
                pos->x = i;
                pos->y = j;
            }
        }
    }
    return *pos;
}

int victory_check(char **my_map, char *map)
{
    int i;
    int j;
    int box = control_map(map);
    int count = 0;
    int row = nb_row(map);
    char **copy;

    copy = str_to_array(map);

    for (i = 0; i < row; i++) {
        for (j = 0; copy[i][j] != '\0' && my_map[i][j] != '\0' ; j++) {
            if (copy[i][j] == 'O' && my_map[i][j] == 'X') {
                count = count +1;
            }
        }
    }
    if (count == box)
        return (1);
    return 0;
}