/*
** EPITECH PROJECT, 2018
** tetris.c
** File description:
** Is tetris a battle royale?
*/
#include "sbml.h"

int count_word_deluxe(char *str)
{
    int i;
    int n;

    i = 0;
    n = 1;
    while (str[i] != '\0') {
        if (((str[i] >= 48 && str[i] <= 57) ||
         (str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 
         && str[i] <= 122)) && (str[i + 1] != '\0'))
            n++;
        i++;
    }
    return (n);
}

int countchar_deluxe(char *str)
{
    int c = 0;

    while ((str[c] >= 48 && str[c] <= 57) ||
         (str[c] >= 65 && str[c] <= 90) || (str[c] >= 97 && str[c] <= 122))
        c++;
    c += 1;
    return (c);
}

int increment_deluxe(char *str, int i)
{
    while ((str[i] <= 48 || str[i] >= 57) &&
         (str[i] <= 65 || str[i] >= 90) && (str[i] <= 97 || str[i] >= 122))
        i++;
    return (i);
}

char **my_str_to_wordtab_deluxe(char *str)
{
    char **tab;
    int i = 0;
    int b = 0;
    int a = 0;
    tab = malloc(sizeof(*tab) * ((count_word_deluxe(str) + 1)));
    while (str[i] != '\t' && str[i] != '\0') {
        if ((str[i] <= 48 || str[i] >= 57) &&
         (str[i] <= 65 || str[i] >= 90) && (str[i] <= 97 || str[i] >= 122)) {
            i = increment_deluxe(str, i);
            a = a + 1;
            b = 0;
        }
        tab[a] = malloc(sizeof(**tab) * ((countchar_deluxe(str + i) + 1)));
        while (((str[i] >= 48 && str[i] <= 57) ||
         (str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)))
            tab[a][b++] = str[i++];
        tab[a][b] = '\0';
    }
    tab[a + 1] = NULL;
    a = 0;
    while (tab[a] != NULL) {
        a++;
    }
    return (tab);
}

char *read_file(char *path)
{
    int fd = open(path, O_RDONLY);
    if (fd == -1)
        return ("R");
    char *buff = malloc(2000);
    int ret = read(fd, buff, 2000);
    buff[ret] = '\0';
    return (buff);
}