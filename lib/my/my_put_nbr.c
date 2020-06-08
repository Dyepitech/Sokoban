/*
** EPITECH PROJECT, 2019
** my_put_nbr$
** File description:
** print nbrs
*/

#include "my.h"

static void my_print_lim_int(void)
{
    my_putchar('-');
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}

int my_put_nbr(int nbr)
{
    if (nbr == -2147483648)
    {
        my_print_lim_int();
        return (0);
    }
    if (nbr < 0)
    {
        my_putchar('-');
        nbr = -nbr;
    }
    if (nbr / 10 != 0)
        my_put_nbr(nbr / 10);
    my_putchar((nbr % 10) + '0');
    return (0);
}
