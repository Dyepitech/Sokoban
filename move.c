/*
** EPITECH PROJECT, 2019
** movement sokoban
** File description:
** move
*/

#include <stdlib.h>
#include <ncurses.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "my.h"
#include "sokoban.h"
#include "soko.h"

void mv_up(char **map, soko_t *pos)
{
    if (map[pos->x -1][pos->y] != '#' &&  map[pos->x -1][pos->y] != 'X' &&
    map[pos->x -1][pos->y] != 'O') {
        map[pos->x -1][pos->y] = 'P';
        map[pos->x][pos->y] = ' ';
    }
    else if (map[pos->x -1][pos->y] == 'X' && map[pos->x -2][pos->y] != '#' &&
    map[pos->x -2][pos->y] != 'X') {
        map[pos->x -2][pos->y] = 'X';
        map[pos->x -1][pos->y] = 'P';
        map[pos->x][pos->y] = ' ';
    }
    else if (map[pos->x -1][pos->y] == 'X' && map[pos->x - 2][pos->y] == '#' &&
    map[pos->x - 2][pos->y] != '0' && (map[pos->x -1][pos->y -1] == '#' ||
    map[pos->x -1][pos->y +1] == '#'))
        loose_panel();
    return;
}

void mv_down(char **map, soko_t *pos)
{
    if (map[pos->x +1][pos->y] != '#' && map[pos->x +1][pos->y] != 'X' &&
    map[pos->x +1][pos->y] != 'O') {
        map[pos->x +1][pos->y] = 'P';
        map[pos->x][pos->y] = ' ';
    }
    else if (map[pos->x +1][pos->y] == 'X' && map[pos->x +2][pos->y] != '#' &&
    map[pos->x +2][pos->y] != 'X') {
        map[pos->x +2][pos->y] = 'X';
        map[pos->x +1][pos->y] = 'P';
        map[pos->x][pos->y] = ' ';
    }
    else if (map[pos->x +1][pos->y] == 'X' && map[pos->x + 2][pos->y] == '#' &&
    map[pos->x +2][pos->y] != '0' && (map[pos->x +1][pos->y -1] == '#' ||
    map[pos->x +1][pos->y +1] == '#'))
        loose_panel();
    return;
}

void mv_right(char **map, soko_t *pos)
{
    if (map[pos->x][pos->y +1] != '#' && map[pos->x][pos->y +1] != 'X' &&
    map[pos->x][pos->y +1] != 'O') {
        map[pos->x][pos->y +1] = 'P';
        map[pos->x][pos->y] = ' ';
    }
    else if (map[pos->x][pos->y +1] == 'X' && map[pos->x][pos->y +2] != '#' &&
    map[pos->x][pos->y +2] != 'X') {
        map[pos->x][pos->y +2] = 'X';
        map[pos->x][pos->y +1] = 'P';
        map[pos->x][pos->y] = ' ';
    }
    else if (map[pos->x][pos->y +1] == 'X' && map[pos->x][pos->y +2] == '#' &&
    map[pos->x][pos->y +2] != '0' && map[pos->x +1][pos->y + 1] == '#')
        loose_panel();
    return;
}

void mv_left(char **map, soko_t *pos)
{
    if (map[pos->x][pos->y -1] != '#' && map[pos->x][pos->y -1] != 'X' &&
    map[pos->x][pos->y -1] != 'O') {
        map[pos->x][pos->y -1] = 'P';
        map[pos->x][pos->y] = ' ';
    }
    else if (map[pos->x][pos->y -1] == 'X' && map[pos->x][pos->y -2] != '#') {
        map[pos->x][pos->y -2] = 'X';
        map[pos->x][pos->y -1] = 'P';
        map[pos->x][pos->y] = ' ';
    }
    else if (map[pos->x][pos->y -1] == 'X' && map[pos->x][pos->y -2] == '#' &&
    map[pos->x][pos->y -2] != '0' && map[pos->x +1][pos->y - 1] == '#') {
        loose_panel();
    }
    return;
}

void key_pressed(char **map, int key, soko_t *pos)
{
    if (key == 27) {
        endwin();
        free (map);
        exit(0);
    }
    if (key == KEY_UP)
        mv_up(map, pos);
    if (key == KEY_DOWN)
        mv_down(map, pos);
    if (key == KEY_RIGHT)
        mv_right(map, pos);
    if (key == KEY_LEFT)
        mv_left(map, pos);
}