/*
** EPITECH PROJECT, 2019
** soko
** File description:
** soko
*/

void my_printf(char *s, ...);
int nb_col(char *buf, int i);
int nb_row(char *buf);
soko_t findplayer(char **my_map, char *map, soko_t *pos);
int victory_check(char **my_map, char *map);
void key_pressed(char **map, int key, soko_t *pos);
void mv_up(char **map, soko_t *pos);
void mv_down(char **map, soko_t *pos);
void mv_left(char **map, soko_t *pos);
void mv_right(char **map, soko_t *pos);
int control_map(char *map);
char *set_level(int fd);
char *get_line_from_str(char *str_map, int *i);
char **str_to_array(char *str_map);
void my_show_map(char **map);
int loop_soko(char **my_map, char *map, soko_t pos);
int play_soko(int fd, char *map);
int	loose_panel(void);
int	win_panel(void);
int main(int argc, char *argv[]);