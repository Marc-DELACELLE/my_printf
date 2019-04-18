/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my own printf file 1
*/

#include <stdarg.h>

int my_getnbr(char const *str, int *i, int *my_char);
void my_putchar(char c);
int modulo_ready(int *i, char const *str, va_list *list, int *mod);
int my_put_nbr(int nb);

int print_spaces(int *mod_nbs, int nb_char, int if_nb)
{
    int sum;
    int ch = ' ';

    if (mod_nbs[3] == '0' && if_nb)
        ch = '0';
    if (if_nb == 2 && mod_nbs[6])
        nb_char++;
    sum = mod_nbs[1] - nb_char;
    while (sum-- > 0)
        my_putchar(ch);
    if (if_nb == 2 && mod_nbs[6])
        my_putchar('+');
    return (0);
}

void check_space(char const *str, int *i, va_list *list, int *mod_nbs)
{
    int nbr2 = 0;
    int nbr = 0;
    int nbr_sp = 0;

    if (str[*i] == ' ') {
        nbr_sp++;
        while (str[*i] == ' ')
            (*i)++;
    }
    nbr += my_getnbr(str, i, mod_nbs);
    if (str[*i] == '.') {
        (*i)++;
        nbr2 = my_getnbr(str, i, mod_nbs);
    }
    mod_nbs[0] = nbr_sp;
    mod_nbs[1] = nbr;
    mod_nbs[2] = nbr2;
    modulo_ready(i, str, list, mod_nbs);
}

int check_base(char one, int *base)
{
    switch (one) {
    case 'p':
    case 'x':
        *base = 16;
        return (39);
    case 'X':
        *base = 16;
        return (7);
    case 'o':
        *base = 8;
        return (0);
    case 'b':
        *base = 2;
        return (0);
    default:
        *base = 10;
        return (0);
    }
}

int unprintable_char(char *rep, int v)
{
    char both[2];

    both[0] = rep[v];
    both[1] = '\0';
    my_putchar('\\');
    if (both[0] < 10 && both[0] >= 0)
        my_putchar('0');
    if (both[0] < 30 && both[0] >= 0)
        my_putchar('0');
    my_put_nbr(both[0]);
    return (0);
}
