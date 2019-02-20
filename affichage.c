#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

// affiche si le tableau est trié ou non
void printTrie(int *tab, int tailleTab, PtrFonctComp fctComp)
{
    if (verifTabTrie(tab, tailleTab, fctComp) != 1) printf("\nTableau non trié\n\n");
    else printf("\nTableau trié\n\n");
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

/* MENU
    Le menu renvoie une structure avec un tableau de pointeurs vers des fonctions de tris et un
    pointeur vers une fonction de comparaison.
*/
PtrFoncTriComp_s menu(void)
{
    // pointeur vers une structure qui sera le retour de la fonction
    PtrFoncTriComp_s choixFctUser;

    // on récupère les pointeurs vers toutes les fonctions de tri implémentées dans un tableau
    PtrFonctTri fonctionsTri[nbFctTri] = {quickSort, triBulles, triFusion, triParTas, triParInsertion};
    // tableau qui servira à recueillir les choix de l'utilisateur (numéro des fonctions de tri)
    int choixAlgosTri[nbFctTri] = {0, 0, 0, 0, 0};
    // tableau qui servira à recueillir les choix de l'utilisateur (pointeurs des fonctions de tri)
    PtrFonctTri choixFonctionsTri[nbFctTri] = {NULL, NULL, NULL, NULL, NULL};

    int cpt = 0;
    int choixCourant;
    char choixAutreAlgo;

    printf("Quelle fonction de tri voulez vous utiliser ? Vous pourrez en choisir plusieurs...\n");

    do
    {
        printf("\nEntrez 1 pour un quicksort\n");
        printf("Entrez 2 pour un tri à bulles\n");
        printf("Entrez 3 pour un tri fusion\n");
        printf("Entrez 4 pour un tri par tas\n");
        printf("Entrez 5 pour un tri par insertion\n");
        printf("Entrez 6 pour tous les choisir\n\n");

        printf("Votre choix : ");
        scanf("%d", &choixCourant);

        // si l'utilisateur choisi tous les algorithmes, on quitte la boucle
        if (choixCourant == 6) break;

        choixAlgosTri[cpt] = choixCourant;

        // si l'utilisateur n'a pas choisi toutes les fonctions de tri on lui propose d'en choisir d'autres
        if (cpt < nbFctTri-1)
        {
            printf("\n\nVoulez vous choisir un autre algorithme (o ou n) ? ");
            scanf(" %c", &choixAutreAlgo);
        }

        cpt++;
    } while ((choixAutreAlgo == 'o') && (cpt < nbFctTri));

    // si l'utilisateur a choisi tous les algorithmes de tri on copie directement le tableau des pointeurs vers les fonctions de tri
    if (choixCourant == 6)
    {
        memcpy(choixFonctionsTri, fonctionsTri, sizeof(fonctionsTri));
        cpt = 5;
    }
    // sinon on prend juste les fonctions qu'il a choisi
    else
    {
        for (int i=0; i<cpt; i++)
        {
            choixFonctionsTri[i] = fonctionsTri[choixAlgosTri[i]-1];
        }
    }

    // si l'initialisation de la structure s'est bien déroulée
    if ((choixFctUser = malloc(sizeof(*choixFctUser))) != NULL)
    {
        choixFctUser->nbFctChoisies = cpt;
        // on alloue de l'espace mémoire puis on copie le tableau des choix utilisateur
        // cela permet d'éviter de faire en sorte que choixFctUser->fonctionsTriChoisies pointe sur une variable locale qui peut être écrasée
        choixFctUser->fonctionsTriChoisies = malloc(sizeof(choixFonctionsTri));
        memcpy(choixFctUser->fonctionsTriChoisies, choixFonctionsTri, sizeof(choixFonctionsTri));
    }
    else printf("Erreur initialisation structure\n");


    // on récupère les pointeurs vers toutes les fonctions de comparaison d'éléments créées
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

    // on met le choix de l'utilisateur dans la structure de renvoi de la fonction
    choixFctUser->fonctionCompChoisie = fonctionsComp[typeFct-1];

    // renvoi de la structure contenant les choix de l'utilisateur
    return choixFctUser;
}
