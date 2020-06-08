/*
** EPITECH PROJECT, 2019
** flags_flag3.C
** File description:
** flag_flag3
*/

#include <unistd.h>
#include <stdarg.h>
#include "my.h"

void pt_printf(va_list *my_printf)
{
    long long nb;
    char *str = "0123456789abcdef";

    nb = va_arg(*my_printf, long long);

    if (nb == 0)
        my_putstr("NULL");
    else {
        my_putstr("0x");
        my_putlongnbr_base(nb, str);
    }
}

void smaj_printf(va_list *my_printf)
{
    char *s;
    int i;
    int a;

    s = va_arg(*my_printf, char *);
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] < 32 || s[i] >= 127) {
            my_putchar(92);
            if (s[i] < 8)
                my_putstr("00");
            if (s[i] < 32 && s[i] >= 8 && s[i] < 64)
                my_putchar('0');
            a = s[i];
            my_putnbr_base(a, s);
        }
        else
            my_putchar(s[i]);
    }
}
