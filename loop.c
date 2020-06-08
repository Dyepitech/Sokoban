/*
** EPITECH PROJECT, 2019
** loop
** File description:
** loop
*/

#include <stdlib.h>
#include <ncurses.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "sokoban.h"
#include "soko.h"

int	loose_panel(void)
{
    int key;

    while (key != 27)
    {
        clear();
        mvprintw(LINES/2, (COLS/2) - (50/2),
        "[LOOSE] Press ESC to quit");
        refresh();
        key = getch();
        if (key == 27) {
            endwin();
            return (0);
        }
    }
    return (key);
}

int	win_panel(void)
{
    int key;

    while (key != 27)
    {
        clear();
        mvprintw(LINES/2, (COLS/2) - (50/2),
        "[WIN] Congratulation you win !\nPress ESC to quit");
        refresh();
        key = getch();
        if (key == 27) {
            endwin();
            return (0);
        }
    }
    return (key);
}

void my_show_map(char **map)
{
    int i = 0;

    while (map[i] != NULL)
    {
        printw("%s\n", map[i]);
        i++;
    }
}

int loop_soko(char **my_map, char *map, soko_t pos)
{
    int key = 0;
    while (1) {
    	initscr();
        noecho();
        keypad(stdscr, TRUE);
        refresh();
        clear();
        findplayer(my_map, map, &pos);
        my_show_map(my_map);
        if (victory_check(my_map, map) == 1)
            win_panel();
        key = getch();
        if (key == -1) {
        exit(84);
            free (map);
        }
        key_pressed(my_map, key, &pos);
    }
}

int play_soko(int fd, char *map)
{
    char **my_map;
    soko_t pos;
    fd = open(map, O_RDONLY);
    map = set_level(fd);
    my_map = str_to_array(map);
    loop_soko(my_map, map, pos);
    endwin();
    return (0);
}