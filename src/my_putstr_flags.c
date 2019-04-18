/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** my_putstr_flag
*/

void my_putchar(char c);
int my_putstr(char const *str);

int my_putstr_flags(char const *str, int *mod_nbs, char const *O_str, int *i)
{
    int v = 0;

    if (mod_nbs[4]) {
        mod_nbs[4] = 0;
        if (O_str[*i] == 'x' || O_str[*i] == 'p')
            my_putstr("0x");
        if (O_str[*i] == 'X')
            my_putstr("0X");
        if (O_str[*i] == 'o')
            my_putchar('0');
    }
    while (str[v] != 0) {
        my_putchar(str[v]);
        v++;
    }
    return (0);
}
