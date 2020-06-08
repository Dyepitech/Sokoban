/*
** EPITECH PROJECT, 2019
** my_getnbr_base
** File description:
** convert str in int from base
*/

static int is_str_neg(char const *str, int *i)
{
    int is_neg = 0;

    while (str[*i] != 0 && (str[*i] == '+' || str[*i] == '-'))
    {
        if (str[*i] == '-' && is_neg == 0)
            is_neg = 1;
        else if (str[*i] == '-' && is_neg == 1)
            is_neg = 0;
        *i = *i + 1;
    }
    return (is_neg);
}

static int find_in_base(char c, char const *base)
{
    int i = 0;

    while (base[i] != 0)
    {
        if (base[i] == c)
            return (i);
        i++;
    }
    return (-1);
}

static int check_uoflow(int is_neg, int *to_neg, int *ret)
{
    if (*ret > 0 && *to_neg == 1)
    {
        *ret = *ret * -1;
        *to_neg = 0;
    }
    if (*ret != 0 && is_neg == 1 && *ret > 0)
        return (1);
    if (*ret != 0 && is_neg == 0 && *ret < 0)
        return (1);
    return (0);
}

static int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != 0)
        i++;
    return (i);
}

int my_getnbr_base(char const *str, char const *base)
{
    int len = my_strlen(base);
    int i = 0;
    int ret = 0;
    int is_neg = is_str_neg(str, &i);
    int to_neg = is_neg;

    if (len < 2)
        return (0);
    while (str[i] != 0 && find_in_base(str[i], base) >= 0)
    {
        if (is_neg == 0 || to_neg == 1)
            ret = (ret * len) + (find_in_base(str[i], base));
        else if (is_neg == 1 && to_neg == 0)
            ret = (ret * len) - (find_in_base(str[i], base));
        if (check_uoflow(is_neg, &to_neg, &ret) == 1)
            return (0);
        i++;
    }
    return (ret);
}
