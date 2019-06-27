/*
** EPITECH PROJECT, 2018
** tetris.c
** File description:
** Is tetris a battle royale?
*/
#include "sbml.h"

int count_word(char *str, char c)
{
    int i;
    int n;

    i = 0;
    n = 1;
    while (str[i] != '\0') {
        if (str[i] == c && str[i + 1] != '\0')
            n++;
        i++;
    }
    return (n);
}

int countchar(char *str, char car)
{
    int c = 0;

    while ((str[c] != car) && (str[c] != '\0') && (str[c] != '\n'))
        c++;
    c += 1;
    return (c);
}

int increment(char *str, int i, char c)
{
    while (str[i] == c)
        i++;
    return (i);
}

char **my_str_to_wordtab(char *str, char c)
{
    char **tab;
    int i = 0;
    int b = 0;
    int a = 0;
    tab = malloc(sizeof(*tab) * ((count_word(str, c) + 1)));
    while (str[i] != '\t' && str[i] != '\0') {
        if (str[i] == c || str[i] == '\n') {
            i = increment(str, i, c);
            a = a + 1;
            b = 0;
        }
        tab[a] = malloc(sizeof(**tab) * ((countchar(str + i, c) + 1)));
        while ((str[i] != c) && (str[i] != '\n') && (str[i] != '\0'))
            tab[a][b++] = str[i++];
        tab[a][b] = '\0';
    }
    tab[a] = NULL;
    return (tab);
}