/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** sokoban
*/

#include <stdlib.h>
#include <ncurses.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "sokoban.h"
#include "soko.h"

void usage(void)
{
    my_printf("USAGE\n");
    my_printf("     ./my_sokoban map\n");
    my_printf("DESCRIPTION\n");
    my_printf("    map  file representing the warehouse map ");
    my_printf("containing '#' for walls\n");
    my_printf("    'P' for the player, 'X' for boxes and 'O' ");
    my_printf("for storage locations.\n");
}

char *set_level(int fd)
{
    struct stat st;
    char *map;
    int size_file;

    fstat(fd, &st);
    size_file = st.st_size;
    map = malloc(size_file + 1);
    read(fd, map, size_file);
    control_map(map);

    return (map);
}

char *get_line_from_str(char *str_map, int *i)
{
    int j = 0;
    char *line;

    line = malloc(sizeof(char) * (nb_col(str_map, *i) + 1));
    while (str_map[*i] != '\n' && str_map[*i] != 0)
    {
        line[j] = str_map[*i];
        j++;
        *i = *i + 1;
    }
    line[j] = 0;
    return (line);
}

char **str_to_array(char *str_map)
{
    char **map;
    int i = 0;
    int j = 0;
    int rows = nb_row(str_map);

    map = malloc(sizeof(char *) * (rows + 1));
    while (j < rows)
    {
        map[j] = get_line_from_str(str_map, &i);
        if (str_map[i] != '\0')
            i++;
        j++;
    }
    map[j] = 0;
    return (map);
}

int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDONLY);

    if (argc != 2) {
        my_printf("Type: ./my_sokoban -h for help\n");
        return (84);
    }
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        usage();
        if (fd == -1)
            return (84);
    }
    play_soko (fd, argv[1]);
    close (fd);
}
