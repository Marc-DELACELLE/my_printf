/*
** EPITECH PROJECT, 2018
** my_printf2
** File description:
** my own printf file 2
*/
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int print_spaces(int *mod_nbs, int nb_char, int if_nb);
int my_strlen(char const *rep);
int my_putstr(char const *str);
void my_putchar(char c);
int unprintable_char(char *rep, int v);
int my_put_nbr_evol(long long int nb, char const *str, int *i, int *mod_nbs);
int check_base(char one, int *base);
int manage_flags(char const *str, int *i, int *mod_nbs);
int my_putstr_flags(char const *str, int *mod_nbs, char const *O_str, int *i);

int modulo_str(int *i, char const *str, va_list *list, int *mod_nbs)
{
    char *rep = va_arg(*list, char *);
    int value = 0;
    int nb_char = my_strlen(rep);

    mod_nbs[3] != 45 ? print_spaces(mod_nbs, nb_char, value) : 0;
    if (str[*i] == 's') {
        my_putstr(rep);
        if (mod_nbs[3] == '-')
            print_spaces(mod_nbs, nb_char, 0);
        return (0);
    }
    for (int v = 0; rep[v]; v++) {
        if (rep[v]>= 27 && rep[v] < 127)
            my_putchar(rep[v]);
        else
            unprintable_char(rep, v);
    }
    mod_nbs[3] == '-' ? print_spaces(mod_nbs, nb_char, 0) : 0;
    return (0);
}

int modulo_int(int *i, char const *str, va_list *list, int *mod_nbs)
{
    if (str[*i] == 'c' || str[*i] == 'd' || str[*i] == 'i')
        my_put_nbr_evol(va_arg(*list, int), str, i, mod_nbs);
    else if (str[*i] == 'u')
        my_put_nbr_evol(va_arg(*list, unsigned int), str, i, mod_nbs);
    else {
        if (str[++*i]== 'u')
            my_put_nbr_evol(va_arg(*list, unsigned long int), str, i, mod_nbs);
        else if (str[*i] == 'd')
            my_put_nbr_evol(va_arg(*list, long int), str, i, mod_nbs);
        else
            return (84);
    }
    return (0);
}

char *calc_base(char *result, unsigned long long rep, int *nb_char, char one)
{
    int base;
    int type_base = check_base(one, &base);
    unsigned long long pow = 1;
    unsigned long long c = rep;
    int v = 0;
    int len_malloc = 0;

    for (; pow <= rep; len_malloc++)
        pow *= base;
    result = malloc(sizeof(char) * (len_malloc + 1));
    for (pow /= base; pow != 0; v++, pow /= base, rep = c) {
        rep /= pow;
        if (rep > 9 && type_base)
            result[v] = '0' + rep + type_base;
        else
            result[v] = '0' + rep;
        c = c - pow * rep;
        (*nb_char)++;
    }
    result[v] = '\0';
    return (result);
}

int mod_base(int *mod_nbs, char const *str, int *i, int *nb_char)
{
    int thecond = 1;

    if (mod_nbs[0] && !(mod_nbs[6]))
        my_putchar(' ');
    else if (mod_nbs[6] && str[*i] == 'p' && mod_nbs[3] == '-') {
        (*nb_char)++;
        my_putchar('+');
        thecond--;
    }
    if (str[*i] == 'p')
        thecond++;
    if (mod_nbs[4])
        (*nb_char)++;
    if (mod_nbs[4] && (str[*i] == 'X' || str[*i] == 'x' || str[*i] == 'p'))
        (*nb_char)++;
    return (thecond);
}

int modulo_base(char const *str, int *i, unsigned long long rep, int *mod_nbs)
{
    char *result = NULL;
    int nb_char = 0;
    int thecond = 0;
    char one = str[*i];

    result = calc_base(result, rep, &nb_char, one);
    thecond = mod_base(mod_nbs, str, i, &nb_char);
    if (mod_nbs[4] && mod_nbs[3] == '0')
        manage_flags(str, i, mod_nbs);
    if (mod_nbs[3] == '-') {
        my_putstr_flags(result, mod_nbs, str, i);
        return (print_spaces(mod_nbs, nb_char, thecond));
    } else if (!print_spaces(mod_nbs, nb_char, thecond))
        return (my_putstr_flags(result, mod_nbs, str, i));
    return (0);
}
