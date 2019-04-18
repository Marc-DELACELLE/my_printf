/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** pass char * to int
*/

void my_putchar(char c);
int value_final(long result, int minus);

int value_inter(long *result, char nb_c, int minus)
{
    *result = *result * 10 + nb_c - '0';
    if (value_final(*result, minus) != (*result * minus))
        return (1);
    else
        return (0);
}

int value_final(long result, int minus)
{
    return ((int)(result * minus));
}

int my_getnbr(char const *str, int *i, int *mod_nbs)
{
    int minus = 1;
    long result = 0;

    while ((str[*i] == '+' || str[*i] == '0'|| str[*i] == '-') && str[*i]) {
        if (str[(*i)++] == '+') {
            mod_nbs[6] = 1;
            mod_nbs[0] = 1;
        } else if (mod_nbs[3] != '-')
            mod_nbs[3] = str[*i - 1];
    }
    while (str[*i]) {
        if (str[*i] == '-')
            minus = minus * (-1);
        if (str[*i] < '0' || str[*i] > '9')
            return (value_final(result, minus));
        if (value_inter(&result, str[*i], minus))
            return (0);
        (*i)++;
    }
    return (value_final(result, minus));
}
