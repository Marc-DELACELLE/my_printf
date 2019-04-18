/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** print nb
*/
void my_putchar(char c);

int my_put_div(int nb)
{
    if (nb >= 10)
        my_put_div(nb / 10);
    my_putchar('0' + nb % 10);
    return (0);
}

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        nb = 147483648;
    } else if (nb < 0) {
        my_putchar('-');
        nb = nb *(-1);
    }
    my_put_div(nb);
    return (0);
}
