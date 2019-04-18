/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my own printf file 0
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

void my_putchar(char c);
int my_putstr(char const *str);
int modulo_ready(int *i, char const *str, va_list *list, int *mod);
void check_space(char const *str, int *i, va_list *list, int *mod_nbs);
int modulo_int(int *i, char const *str, va_list *list, int *mod_nbs);
int modulo_base(char const *str, int *i, unsigned long long rep, int *mod_nbs);
int modulo_str(int *i, char const *str, va_list *list, int *mod_nbs);

int manage_flags(char const *str, int *i, int *mod_nbs)
{
    mod_nbs[4] = 0;
    if (str[*i] == 'o')
        my_putchar('0');
    if (str[*i] == 'x' || str[*i] == 'p')
        my_putstr("0x");
    if (str[*i] == 'X')
        my_putstr("0X");
    return (0);
}

int backup_modulo(char const *str, int *i)
{
    while (str[*i] != '%')
        (*i)--;
    (*i)++;
    my_putchar('%');
    if (str[*i] == ' ')
        my_putchar(' ');
    while (str[*i] == ' ')
        (*i)++;
    (*i)--;
    return (0);
}

int modulo_ready2(int *i, char const *str, va_list *list, int *mod_nbs)
{
    switch (str[*i]) {
    case '%':
        my_putchar('%');
        return (0);
    case 'p':
        mod_nbs[4] = 1;
        modulo_base(str, i, va_arg(*list, unsigned long long), mod_nbs);
        return (0);
    case '#':
        (*i)++;
        mod_nbs[4] = 1;
        modulo_ready(i, str, list, mod_nbs);
        return (0);
    default:
        if (!(mod_nbs[5])++)
            check_space(str, i, list, mod_nbs);
        else
            backup_modulo(str, i);
        return (0);
    }
}

int modulo_ready(int *i, char const *str, va_list *list, int *mod)
{
    switch (str[*i]) {
    case 'c':
        my_putchar(va_arg(*list, int));
        return (0);
    case 'd':
    case 'i':
    case 'u':
    case 'l':
        return (modulo_int(i, str, list, mod));
    case 'o':
    case 'b':
    case 'x':
    case 'X':
        return (modulo_base(str, i, va_arg(*list, unsigned long long), mod));
    case 's':
    case 'S':
        return (modulo_str(i, str, list, mod));
    default:
        return (modulo_ready2(i, str, list, mod));
    }
}

int my_printf(char const *str, ...)
{
    va_list list;
    int i = 0;
    int mod_nbs[6] = {0, 0, 0, 0, 0, 0};

    va_start(list, str);
    while (str[i]) {
        if (str[i] == '%') {
            i++;
            modulo_ready(&i, str, &list, mod_nbs);
        } else {
            my_putchar(str[i]);
            i++;
            continue;
        }
        for (int v = 0; v < 7;v++)
            mod_nbs[v] = 0;
        i++;
    }
    va_end(list);
    return (0);
}
