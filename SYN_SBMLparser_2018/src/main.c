/*
** EPITECH PROJECT, 2018
** tetris.c
** File description:
** Is tetris a battle royale?
*/

#include "sbml.h"

int main(int ac, char **av)
{
    SBMODEL_t *sbml;
    sbml = malloc(sizeof(SBMODEL_t));
    norm_is_bae(ac, av, sbml);
    if (ac >= 4) {
        tag_counter(sbml);
        COMP_t *comp;
        comp = malloc(sizeof(COMP_t) * sbml->nbr_tag[0]);
        SPECIES_t *spec;
        spec = malloc(sizeof(SPECIES_t) * sbml->nbr_tag[1]);
        REAC_t *reac;
        reac = malloc(sizeof(REAC_t)* sbml->nbr_tag[2]);
        fillator(sbml, comp, spec, reac);
        is_compartment(sbml, comp, spec);
        is_species(sbml, spec, reac);
        if (av[4][0] == '-' && av[4][1] == 'e' && av[4][2] == '\0')
            isee_reaction(sbml, reac);
        else is_reaction(sbml, reac);
    }
}

void isee_reaction(SBMODEL_t *sbml, REAC_t *reac)
{
    int x = 0;
    int i = 0;
    while (i < sbml->nbr_tag[2] && my_strcmp(reac[i].id, sbml->ze_tag) != 0) {
        i++;
    }
    if (i < sbml->nbr_tag[2] && my_strcmp(reac[i].id, sbml->ze_tag) == 0) {
        while (reac[i].spe_reac_species[x] != NULL) {
            printf("%s %s",reac[i].spe_reac_stoichio[x], reac[i].spe_reac_species[x]);
            x++;
            if(reac[i].spe_reac_species[x] != NULL)
                printf(" + ");
        }
        x = 0;
        if (my_strcmp(reac[i].reversible, "true") == 0)
            printf(" <-> ");
        else if (my_strcmp(reac[i].reversible, "false") == 0)
            printf(" -> ");
        while (reac[i].spe_prod_species[x] != NULL) {
            printf("%s %s",reac[i].spe_prod_stoichio[x], reac[i].spe_prod_species[x]);
            x++;
            if(reac[i].spe_reac_species[x] != NULL)
                printf(" + ");
        }
        printf("\n");
        exit(0);
    }
}

void is_reaction(SBMODEL_t *sbml, REAC_t *reac)
{
    int x = 0;
    int i = 0;
    while (i < sbml->nbr_tag[2] && my_strcmp(reac[i].id, sbml->ze_tag) != 0) {
        i++;
    }
    if (i < sbml->nbr_tag[2] && my_strcmp(reac[i].id, sbml->ze_tag) == 0) {
        printf("List of reactants of reaction %s\n", sbml->ze_tag);
        while (reac[i].spe_reac_species[x] != NULL) {
            printf("--->%s\n", reac[i].spe_reac_species[x]);
            x++;
        }
        x = 0;
        printf("List of products of reaction %s\n", sbml->ze_tag);
        while (reac[i].spe_prod_species[x] != NULL) {
            printf("--->%s\n", reac[i].spe_prod_species[x]);
            x++;
        }
        exit(0);
    }
}

void is_species(SBMODEL_t *sbml, SPECIES_t *spec, REAC_t *reac)
{
    int x = 0;
    int i = 0;
    int *j = 0;
    while (i < sbml->nbr_tag[1] && my_strcmp(spec[i].id, sbml->ze_tag) != 0) {
        i++;
    }
    if (i < sbml->nbr_tag[1] && my_strcmp(spec[i].id, sbml->ze_tag) == 0) {
        j = spec_checker(sbml, spec, reac);
        if (j[0] > 0)
            printf("List of reactions consuming species %s (quantities)\n", sbml->ze_tag);
        while (x < j[0]) {
            printf("--->%s (%d)\n", reac[x].id, spec_counter(sbml, spec, reac ,x));
            x++;
        }
        return (0);
    }
}

int spec_counter(SBMODEL_t *sbml, SPECIES_t *spec, REAC_t *reac, int x)
{
    int i = 0;
    int p = 0;
    while (reac[x].spe_reac_species[i] != NULL) {
        if (my_strcmp(reac[x].spe_reac_species[i], sbml->ze_tag) == 0) {
            p++;
        }
        i++;
    }
    i = 0;
    while (reac[x].spe_prod_species[i] != NULL) {
        if (my_strcmp(reac[x].spe_prod_species[i], sbml->ze_tag) == 0) {
            p++;
        }
        i++;
    }
    return (p);
}

int *spec_checker(SBMODEL_t *sbml, SPECIES_t *spec, REAC_t *reac)
{
    int x = 0;
    int i = 0;
    int k = 1;
    while (x < sbml->nbr_tag[2]) {
        if (spechecker(sbml, reac, x) == 1) {
            i++;
        }
        x++;
    }
    int *j = malloc(sizeof(int) * i);
    j[0] = x;
    x = 0;
    while (x < sbml->nbr_tag[2]) {
        if (spechecker(sbml, reac, x) == 1) {
            j[k] = x;
        }
        x++;
    }
    return (j);
}

int spechecker(SBMODEL_t *sbml, REAC_t *reac, int x)
{
    int i = 0;
    while (reac[x].spe_reac_species[i] != NULL) {
        if (my_strcmp(reac[x].spe_reac_species[i], sbml->ze_tag) == 0) {
            return (1);
        }
        i++;
    }
    while (reac[x].spe_prod_species[i] != NULL) {
        if (my_strcmp(reac[x].spe_prod_species[i], sbml->ze_tag) == 0) {
            return (1);
        }
        i++;
    }
    return (0);
}

void is_compartment(SBMODEL_t *sbml, COMP_t *comp, SPECIES_t *spec)
{
    int x = 0;
    int i = 0;
    while (i < sbml->nbr_tag[0] && my_strcmp(comp[i].id, sbml->ze_tag) != 0 ) {
        i++;
    }
    if (i < sbml->nbr_tag[0] && my_strcmp(comp[i].id, sbml->ze_tag) == 0) {
        printf("List of species in compartment Cytosol\n");
        while (x < sbml->nbr_tag[1]) {
            if (my_strcmp(comp[i].id, spec[x].comp) == 0) {
                printf("--->%s\n", spec[x].name);
            }
            x++;
        }
        exit(0);
    }
}

void norm_is_bae(int ac, char** av, SBMODEL_t *sbml)
{
    char *txt = read_file(av[1]);
    sbml->text = my_str_to_wordtab(txt, '\n');
    declarer_sbmodel(sbml, txt);
    parser(ac, av, sbml);
}