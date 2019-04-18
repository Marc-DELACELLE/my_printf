/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** print %lld nb
*/

void my_putchar(char c);

int my_put_div_evol(long long int nb, int *nb_char, int *mod_nbs, int *cond)
{
    char ch = ' ';

    (*nb_char)++;
    if (nb >= 10) {
        my_put_div_evol(nb / 10, nb_char, mod_nbs, cond);
    }
    if (mod_nbs[3] != 45) {
        if (mod_nbs[3] == 48)
            ch = '0';
        if ((mod_nbs[0])-- > 0)
            (*nb_char)++;
        while (mod_nbs[1] - (*nb_char)++ - (*cond) > 0)
            my_putchar(ch);
    }
    if ((*cond)-- > 0)
        my_putchar('-');
    my_putchar('0' + nb % 10);
    return (0);
}

int other_cond(int var, int *nb_char, int *mod_nbs)
{
    if (mod_nbs[3] == 45) {
        if ((mod_nbs[0])--)
            (*nb_char)++;
        while (mod_nbs[1] - (*nb_char)++ - var > 0)
            my_putchar(' ');
    }
    return (0);
}

int my_put_nbr_evol(long long int nb, char const *str, int *i, int *mod_nbs)
{
    int nb_char = 0;
    int cond = 0;
    int var = 0;

    if (str[*i] != 'c' && mod_nbs[0] && !mod_nbs[6] && (int)nb >= 0)
        my_putchar(' ');
    else if (str[*i] != 'c' && mod_nbs[0] && mod_nbs[6] && (int)nb >= 0)
        my_putchar('+');
    if (nb < 0) {
        var = ++cond;
        if (mod_nbs[0])
            var--;
        nb = nb * (-1);
    }
    if (cond && mod_nbs[3] == 48) {
        my_putchar('-');
        cond--;
    }
    my_put_div_evol(nb, &nb_char, mod_nbs, &cond);
    return (other_cond(var, &nb_char, mod_nbs));
}
