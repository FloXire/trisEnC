#include <stdio.h>
#include "affichage.h"
#include "comparaison.h"

// affiche le tableau
void printTab(int *tab, int tailleTab)
{
    for (int i=0; i<tailleTab; i++)
    {
        printf("%16d\n", tab[i]);
    }
}

// retourne 1 si le tableau est trié, 0 sinon
int verifTabTrie(int *tab, int tailleTab, int (*fctComp)(int, int))
{
    for (int i=0; i<(tailleTab-1); i++)
    {
        if (fctComp(tab[i+1], tab[i])) return 0;
    }
    return 1;
}

void printTrie(int *tab, int tailleTab, int (*fctComp)(int, int))
{
    if (verifTabTrie(tab, tailleTab, fctComp) != 1)
    {
        printf("Tableau non trié\n\n");
    }
    else printf("Tableau trié\n\n");
}

int (*menu(void))(int, int)
{
    int (*listeFonction[6])(int, int) = {triCroissant, triDecroissant, triPairCroissant, triPairDecroissant, triImpairCroissant, triImpairDecroissant};
    int typeFct;

    printf("Quelle fonction de comparaison voulez vous utiliser ?\n\n");
    printf("Entrez 1 pour un tri croissant\n");
    printf("Entrez 2 pour un tri décroissant\n");
    printf("Entrez 3 pour un tri croissant avec les nombres pairs en premier puis les nombres impairs\n");
    printf("Entrez 4 pour un tri décroissant avec les nombres pairs en premier puis les nombres impairs\n");
    printf("Entrez 5 pour un tri croissant avec les nombres impairs en premier puis les nombres pairs\n");
    printf("Entrez 6 pour un tri décroissant avec les nombres impairs en premier puis les nombres pairs\n\n");

    printf("Votre choix : ");
    scanf("%d", &typeFct);

    return listeFonction[typeFct-1];
}
