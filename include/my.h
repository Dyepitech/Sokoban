/*
** EPITECH PROJECT, 2019
** libmy.h
** File description:
** header for libmy
*/

#include <stdarg.h>
#ifndef MY_POOL_LIBRARY_H__
# define MY_POOL_LIBRARY_H__

int my_putchar(char);
int my_isneg (int);
int my_put_nbr(int);
void my_swap(int *, int *);
int my_putstr(char const *);
int my_strlen(char const *);
int my_getnbr(char const *);
void my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_find_prime_sup(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);
int my_putnbr_base(int, char const *);
int my_getnbr_base(char const *, char const *);
int my_showstr(char const *);
int my_showmem(char const *, int);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
char *my_strdup(char const *);
int my_show_word_array(char * const *);
char **my_str_to_word_array(char const *);
void my_remove_from_str(char const *, char *);
void my_printf(char *s, ...);
void s_printf(va_list *my_printf);
void d_printf(va_list *my_printf);
void f_printf(va_list *my_printf);
void c_printf(va_list *my_printf);
void n_printf(va_list *my_printf);
void l_printf(va_list *my_printf);
void x_printf(va_list *my_printf);
void o_printf(va_list *my_printf);
void pr_printf(va_list *my_printf);
void b_printf(va_list *my_printf);
void pt_printf(va_list *my_printf);
void smaj_printf(va_list *my_printf);
int my_putlongnbr_base(long long, char const *);

#endif
