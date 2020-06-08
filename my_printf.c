/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** myprintf
*/

#include <stdarg.h>
#include "my.h"

int sum_stdarg(int i, int nb, ...)
{
    int res;
    va_list ap;

    va_start(ap, nb);

    if (i == 0) {
        while (nb > 0) {
            res = va_arg(ap, int) + res;
            nb = nb - 1;
        }
    }
    if (i == 1) {
        while (nb > 0) {
            res = my_strlen(va_arg(ap, char *)) + res;
            nb = nb - 1;
        }
    }
    va_end(ap);
    return (res);
}

int final_check(char *tableau, char find)
{
    int i;

    for (i = 0; tableau[i] != 0; i++){
        if (tableau[i] == find)
            return (i);
    }
    return (-1);
}

void my_printf(char *s, ...)
{
    va_list my_printf;
    va_start(my_printf, s);
    int i;
    int match;
    void (*ptrtab[13]) (va_list *) = {s_printf, d_printf, b_printf, c_printf,
    n_printf, l_printf, x_printf, o_printf,
    smaj_printf, x_printf, pr_printf, pt_printf};
    char flgs[14] = {'s', 'd', 'b', 'c', 'n', 'l', 'x', 'o', 'S', 'X', '%', 'p',
    0};

    for (i = 0; s[i] != 0; i++) {
        if (i != 0 && s[i -1] == '%') {
            match = final_check(flgs, s[i]);
            if (match >= 0)
                (*ptrtab[match]) (&my_printf);
        } else if (s[i] != '%')
            my_putchar(s[i]);
    }
}
