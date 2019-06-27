/*
** EPITECH PROJECT, 2018
** tetris.c
** File description:
** Is tetris a battle royale?
*/

#include "sbml.h"

int	my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i;

    i = 0;
    while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0')) {
        i++;
    }
    return (s1[i] - s2[i]);
}