/*
** EPITECH PROJECT, 2018
** tetris.c
** File description:
** Is tetris a battle royale?
*/

#include "sbml.h"

void displayer_parser(SBMODEL_t *sbml)
{
    if (sbml->is_comp == 1)
        printf("compartment\n--->id\n--->name\n");
    if (sbml->is_model == 1)
        printf("model\n--->id\n--->name\n");
    if (sbml->is_reaction == 1)
        printf("reaction\n--->id\n--->name\n--->reversible\n");
    if (sbml->is_sbml == 1)
        printf("sbml\n--->level\n--->version\n--->xmlns\n");
    if (sbml->is_species == 1)
        printf("species\n--->compartment\n--->id\n--->name\n");
    if (sbml->is_spe_ref == 1)
        printf("speciesReference\n--->species\n--->stoichiometry\n");
}

void declarer_sbmodel(SBMODEL_t *sbml, char *txt)
{
    sbml->is_sbml = text_finder(txt, "<sbml");
    sbml->is_model = text_finder(txt, "<model");
    sbml->is_comp = text_finder(txt, "<listOfCompartments>");
    sbml->is_species = text_finder(txt, "<listOfSpecies>");
    sbml->is_reaction = text_finder(txt, "<listOfReactions>");
    sbml->is_spe_ref = text_finder(txt, "<speciesReference");
    sbml->tag_finder = malloc(sizeof(char *)* 3);
    sbml->tag_finder[0] = "<compartment name=";
    sbml->tag_finder[1] = "<species compartment=";
    sbml->tag_finder[2] = "<reaction compartment=";
    sbml->nbr_tag = malloc(sizeof(int) * 3);
    sbml->nbr_tag[0] = 0;
    sbml->nbr_tag[1] = 0;
    sbml->nbr_tag[2] = 0;
}