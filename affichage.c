#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"
#include "comparaison.h"
#include "tris.h"

// affiche le tableau
void printTab(int *tab, int tailleTab)
{
    for (int i=0; i<tailleTab; i++)
    {
        printf("%16d\n", tab[i]);
    }
}

// retourne 1 si le tableau est trié, 0 sinon
int verifTabTrie(int *tab, int tailleTab, PtrFonctComp fctComp)
{
    for (int i=0; i<(tailleTab-1); i++)
    {
        if (fctComp(tab[i+1], tab[i])) return 0;
    }
    return 1;
}

void printTrie(int *tab, int tailleTab, PtrFonctComp fctComp)
{
    if (verifTabTrie(tab, tailleTab, fctComp) != 1) printf("Tableau non trié\n\n");
    else printf("Tableau trié\n\n");
}

/* MENU
    Le menu renvoie une structure avec un tableau de pointeurs vers des fonctions de tris et un
    pointeur vers une fonction de comparaison.
*/
PtrFoncTriComp_s menu(void)
{
    // pointeur vers un structure qui sera le retour de la fonction
    PtrFoncTriComp_s choixFctUser;

    PtrFonctTri fonctionsTri[nbFctTri] = {quickSort, triBulles};
    int choixAlgosTri[nbFctTri] = {0, 0};
    PtrFonctTri choixFonctionsTri[nbFctTri] = {NULL, NULL};

    int cpt = 0;
    int choixCourant;
    char choixAutreAlgo;

    printf("Quelle fonction de tri voulez vous utiliser ? Vous pourrez en choisir plusieurs...\n\n");

    do
    {
        printf("Entrez 1 pour un quicksort\n");
        printf("Entrez 2 pour un tri à bulles\n\n");

        printf("Votre choix : ");
        scanf("%d", &choixCourant);
        choixAlgosTri[cpt] = choixCourant;

        printf("\n\nVoulez vous choisir un autre algorithme (o ou n) ? ");
        scanf("%c", &choixAutreAlgo);
        printf("\n");

        cpt++;
    } while ((choixAutreAlgo == 'o') && (cpt < nbFctTri));

    for (int i=0; i<cpt; i++)
    {
        choixFonctionsTri[i] = fonctionsTri[choixAlgosTri[i]-1];
    }

    if ((choixFctUser = malloc(6*sizeof(int))) != NULL)
    {
        choixFctUser->nbFctChoisies = cpt;
        choixFctUser->fonctionsTriChoisies = choixFonctionsTri;
    } else printf("Erreur initialisation structure\n");


    PtrFonctComp fonctionsComp[nbFctComp] = {triCroissant, triDecroissant, triPairCroissant, triPairDecroissant, triImpairCroissant, triImpairDecroissant};
    int typeFct;

    printf("\n\nQuelle fonction de comparaison voulez vous utiliser ?\n\n");

    printf("Entrez 1 pour un tri croissant\n");
    printf("Entrez 2 pour un tri décroissant\n");
    printf("Entrez 3 pour un tri croissant avec les nombres pairs en premier puis les nombres impairs\n");
    printf("Entrez 4 pour un tri décroissant avec les nombres pairs en premier puis les nombres impairs\n");
    printf("Entrez 5 pour un tri croissant avec les nombres impairs en premier puis les nombres pairs\n");
    printf("Entrez 6 pour un tri décroissant avec les nombres impairs en premier puis les nombres pairs\n\n");

    printf("Votre choix : ");
    scanf("%d", &typeFct);

    choixFctUser->fonctionCompChoisie = fonctionsComp[typeFct-1];

    return choixFctUser;
}
