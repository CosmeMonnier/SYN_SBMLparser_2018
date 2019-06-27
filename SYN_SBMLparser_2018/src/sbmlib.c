/*
** EPITECH PROJECT, 2018
** tetris.c
** File description:
** Is tetris a battle royale?
*/

#include "sbml.h"

int text_finder(char *str, char *text)
{
    int i = 0;
    int x = 0;
    while (str[i] != '\0') {
        while (text[x] == str[i] && text[x] != '\0' && str[i] != '\0') {
            x++;
            i++;
        }
        if (text[x] == '\0' && str[i] != '\0') {
            return (1);
        }
        i++;
        x = 0;
        
    }
    return (0);
}

char * text_taker_two(int i, char *str)
{
    int k = 0;
    int x = 0;
    int j = i;
    while (str[i] != '\"') {
        i ++;
    }
    x = i - j;
    char *id = malloc (sizeof(char) * (x));
    while(j < i) {
        id[k] = str[j];
        k++;
        j++;
    }
    return (id);
}

char *text_taker(char*str, char *text)
{
    int i = 0;
    int x = 0;
    int k = 0;
    char *id;
    while (str[i] != '\0' && k != 1) {
        while (text[x] == str[i] && text[x] != '\0' && str[i] != '\0') {
            x++;
            i++;
        }
        if (text[x] == '\0' && str[i] != '\0') {
            k = 1;
        }
        x = 0;
        i++;
    }
    id = text_taker_two(i, str);
    return (id);
}

void tag_counter(SBMODEL_t *sbml)
{
    int x = 0;
    int j = 0;
    while (j <= 2 || sbml->text[x] == NULL) {
        if (text_finder(sbml->text[x], sbml->tag_finder[j]) == 1) {
            sbml->nbr_tag[j]++;
        }
        x++;
        if (sbml->text[x] == NULL) {
            j++;
            x = 0;
        }
    }
}

void parser(int ac, char **av, SBMODEL_t *sbml)
{
    if (ac == 2) {
        displayer_parser(sbml);
        exit(0);
    } else if (ac >= 4)
        sbml->ze_tag = av[3];
}