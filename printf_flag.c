/*
** EPITECH PROJECT, 2019
** my_printf_flags
** File description:
** my_printf
*/

#include <unistd.h>
#include <stdarg.h>
#include "my.h"

void s_printf(va_list *my_printf)
{
    char *s;

    s = va_arg(*my_printf, char *);

    my_putstr(s);
}

void d_printf(va_list *my_printf)
{
    int d;

    d = va_arg(*my_printf, int);

    my_put_nbr(d);
}

void f_printf(va_list *my_printf)
{
    double f;

    f = va_arg(*my_printf, double);

    my_put_nbr(f);
}

void c_printf(va_list *my_printf)
{
    int c;

    c = va_arg(*my_printf, int);

    my_putchar(c);
}

void l_printf(va_list *my_printf)
{
    long int l;

    l = va_arg(*my_printf, long int);

    my_put_nbr(l);
}