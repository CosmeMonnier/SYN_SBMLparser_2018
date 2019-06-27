/*
** EPITECH PROJECT, 2018
** tetris.c
** File description:
** Is tetris a battle royale?
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct {
    char *name;
    char *id;
}COMP_t;

typedef struct {
    char *comp;
    char *name;
    char *id;
}SPECIES_t;

typedef struct {
    char *comp;
    char *reversible;
    char *name;
    char *id;
    char **spe_reac_stoichio;
    char **spe_reac_species;
    char **spe_prod_stoichio;
    char **spe_prod_species;
    int reac_nbr;
    int prod_nbr;
}REAC_t;

typedef struct {
    char **text;
    int is_sbml;
    int is_model;
    int is_comp;
    int is_species;
    int is_reaction;
    int is_spe_ref;
    int ac;
    char *ze_tag;
    int *nbr_tag;
    char **tag_finder;
}SBMODEL_t;

char *read_file(char *path);
char **my_str_to_wordtab_deluxe(char *str);
int text_finder(char *str, char *text);
char *text_taker_two(int i, char *str);
char *text_taker(char*str, char *text);
int main(int ac, char **av);
void parser(int ac, char **av, SBMODEL_t *sbml);
int	my_strlen(char const *str);
void declarer_sbmodel(SBMODEL_t *sbml, char *txt);
void displayer_parser(SBMODEL_t *sbml);
void tag_counter(SBMODEL_t *sbml);
int increment(char *str, int i, char c);
int countchar(char *str, char car);
int count_word(char *str, char c);
char **my_str_to_wordtab(char *str, char c);
void norm_is_bae(int ac, char** av, SBMODEL_t *sbml);
void dec_spe_reaction(SBMODEL_t *sbml, REAC_t *reac);
void filler_reac(SBMODEL_t *sbml, REAC_t *reac);
void filler_comp(SBMODEL_t *sbml, COMP_t *comp);
void filler_spec(SBMODEL_t *sbml, SPECIES_t *spec);
void fillator(SBMODEL_t *sbml, COMP_t *comp, SPECIES_t *spec, REAC_t *reac);
int spechecker(SBMODEL_t *sbml, REAC_t *reac, int x);
int *spec_checker(SBMODEL_t *sbml, SPECIES_t *spec, REAC_t *reac);
void is_species(SBMODEL_t *sbml, SPECIES_t *spec, REAC_t *reac);
void is_compartment(SBMODEL_t *sbml, COMP_t *comp, SPECIES_t *spec);
int my_strcmp(char const *s1, char const *s2);
int spec_counter(SBMODEL_t *sbml, SPECIES_t *spec, REAC_t *reac, int x);