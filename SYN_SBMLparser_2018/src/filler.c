/*
** EPITECH PROJECT, 2018
** tetris.c
** File description:
** Is tetris a battle royale?
*/

#include "sbml.h"

void filler_spec(SBMODEL_t *sbml, SPECIES_t *spec)
{
    int x = 0;
    int j = 0;
    while (j < sbml->nbr_tag[1] || sbml->text[x] == NULL) {
        if (text_finder(sbml->text[x], sbml->tag_finder[1]) == 1) {
            spec[j].comp = text_taker(sbml->text[x], "compartment=");
            spec[j].name = text_taker(sbml->text[x], "name=");
            spec[j].id = text_taker(sbml->text[x], "id=");
            j++;
        }
        x++;
    }
}

void filler_comp(SBMODEL_t *sbml, COMP_t *comp)
{
    int x = 0;
    int j = 0;
    while (j < sbml->nbr_tag[0] || sbml->text[x] == NULL) {
        if (text_finder(sbml->text[x], sbml->tag_finder[0]) == 1) {
            comp[j].name = text_taker(sbml->text[x], "<compartment name=");
            comp[j].id = text_taker(sbml->text[x], "id=");
            j++;
        }
        x++;
    }
}

void filler_reac(SBMODEL_t *sbml, REAC_t *reac)
{
    int x = 0;
    int j = 0;
    int i = 0;
    while (j < sbml->nbr_tag[2] || sbml->text[x] != NULL) {
        if (text_finder(sbml->text[x], sbml->tag_finder[2]) == 1) {
            reac[j].comp = text_taker(sbml->text[x], "compartment=");
            reac[j].reversible = text_taker(sbml->text[x], "reversible=");
            reac[j].name = text_taker(sbml->text[x], "name=");
            reac[j].id = text_taker(sbml->text[x], "id=");
            x = x + 2;
            while (i < reac[j].reac_nbr) {
                reac[j].spe_reac_stoichio[i] = text_taker(sbml->text[x], "stoichiometry=");
                reac[j].spe_reac_species[i] = text_taker(sbml->text[x], " species=");
                i++;
                x++;
            } x = x + 2;
            i = 0;
            while (i < reac[j].prod_nbr) {
                reac[j].spe_prod_stoichio[i] = text_taker(sbml->text[x], "stoichiometry=");
                reac[j].spe_prod_species[i] = text_taker(sbml->text[x], "species=");
                i++;
                x++;
            }
            i = 0;
            j++;
        }
        x++;
    }
}

void dec_spe_reaction(SBMODEL_t *sbml, REAC_t *reac)
{
    int x = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    while(sbml->text[x] != NULL) {
        while (text_finder(sbml->text[x], "speciesReference") == 1) {
            l++;
            x++;
        }
        if ((k == 0) && (l >= 1)) {
            l++;
            reac[j].spe_reac_stoichio = malloc(sizeof(char *) * l);
            reac[j].spe_reac_species = malloc(sizeof(char *) * l);
            reac[j].reac_nbr = l - 1;
            k++;
            l = 0;
        } else if ((k == 1) && (l >= 1)) {
            l++;
            reac[j].spe_prod_stoichio = malloc(sizeof(char *)* l);
            reac[j].spe_prod_species = malloc(sizeof(char *)* l);
            reac[j].prod_nbr = l - 1;
            k = 0;
            j++;
            l = 0;
        }
        x++;
    }
}

void fillator(SBMODEL_t *sbml, COMP_t *comp, SPECIES_t *spec, REAC_t *reac)
{
    dec_spe_reaction(sbml, reac);
    filler_comp(sbml, comp);
    filler_spec(sbml, spec);
    filler_reac(sbml, reac);
}