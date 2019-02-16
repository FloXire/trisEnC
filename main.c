#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "affichage.h"
#include "tris.h"


// initialise le tableau avec des valeurs aléatoires
void remplirTab(int *tab, int tailleTab)
{
    time_t t;
    srand(time(&t));
    for (int i=0; i<tailleTab; i++)
    {
        tab[i] = rand();
    }
}

int main(void)
{
    int tailleTab = 1000000;
    int tab[tailleTab];
    remplirTab(tab, tailleTab);

    PtrFoncTriComp_s choixFctUser;

    choixFctUser = menu();

    if (tailleTab < 20000) printTab(tab, tailleTab);
    printTrie(tab, tailleTab, choixFctUser->fonctionCompChoisie);

    /* for (int i=0; i<(choixFctUser->nbFctChoisies); i++)
    {
        quickSort(tab, 0, tailleTab-1, fctComp);
    } */

    choixFctUser->fonctionsTriChoisies[0](tab, 0, tailleTab-1, choixFctUser->fonctionCompChoisie);

    if (tailleTab < 20000) printTab(tab, tailleTab);
    printTrie(tab, tailleTab, choixFctUser->fonctionCompChoisie);

    return 0;
}
