/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** convert str in int
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int ret = 0;
    int is_neg = is_str_neg(str, &i);
    int to_neg = is_neg;

    while (str[i] != 0 && is_digit(str[i]) == 1)
    {
        if (is_neg == 0 || to_neg == 1)
            ret = (ret * 10) + (str[i] - '0');
        else if (is_neg == 1 && to_neg == 0)
            ret = (ret * 10) - (str[i] - '0');
        if (check_uoflow(is_neg, &to_neg, &ret) == 1)
            return (0);
        i++;
    }
    return (ret);
}
