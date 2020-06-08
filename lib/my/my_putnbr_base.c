/*
** EPITECH PROJECT, 2019
** putnbr_base
** File description:
** prints nbr in given base
*/

#include "my.h"

static int my_true_putnbr_base(int nbr, char const *base, int len)
{
    if (nbr / len != 0)
        my_true_putnbr_base(nbr / len, base, len);
    my_putchar(base[nbr % len]);
    return (0);
}

int my_putnbr_base(int nbr, char const *base)
{
    int len = my_strlen(base);

    if (len < 2)
        return (0);
    if (nbr < 0)
    {
        my_putchar('-');
        nbr = nbr * -1;
    }
    my_true_putnbr_base(nbr, base, len);
    return (0);
}
