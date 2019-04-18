/*
** EPITECH PROJECT, 2018
** MY_STRLEN
** File description:
** Count the nb of char
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str && str[i] != '\0')
        i = i + 1;
    return (i);
}
