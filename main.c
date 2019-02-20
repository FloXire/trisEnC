#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "affichage.h"
#include "tris.h"
#include <sys/time.h> //utilisée pour calculer le temps d'exécution des fonctions de tri


// initialise le tableau avec des valeurs aléatoires
void remplirTab(int *tab, int tailleTab)
{
    printf("Generation d'un tableau de %d nombres aleatoires\n", tailleTab);
    time_t t;
    srand(time(&t));
    for (int i=0; i<tailleTab; i++)
    {
        tab[i] = rand();
    }
}


// Function prenant en paramères un tableau non trié, le tri et renvoi le temps d'exécution
int testAlgoTri(FoncTriComp_s *choixFctUser, int *tab, int tailleTab) {

    struct timeval *start, *stop;
    start = malloc(sizeof(struct timeval));
    stop = malloc(sizeof(struct timeval));

    gettimeofday(start, NULL); // On enregistre l'heure dans start
    choixFctUser->fonctionsTriChoisies[0](tab, 0, tailleTab-1, choixFctUser->fonctionCompChoisie);
    gettimeofday(stop, NULL); // On enregistre l'heure dans stop

    // Si le compteur de secondes est supérieur à 0 (le start et le stop ne se sont pas produits durant la même seconde)
    if ((stop->tv_sec-start->tv_sec)>0) {
        if(stop->tv_usec < start->tv_usec){ // si stop(comteur us) < start(comteur us), alors on enlève 1 seconde
            return (stop->tv_sec-start->tv_sec-1)*1000000+(1000000-start->tv_usec)+stop->tv_usec;
        }
        else {
            return (stop->tv_sec-start->tv_sec)*1000000+(1000000-start->tv_usec)+stop->tv_usec;
        }
    }
    else { // Sinon, le tri a été effectué dans la même seconde
        return (stop->tv_usec-start->tv_usec);
    }

}


int main(void)
{
    // Attention, un tableau dont la taille est trop élevée peut entrainer une erreur de segementation (la limite dépend de votre ordinateur)
    int tailleTab = 500000;
    int tab[tailleTab];

    PtrFoncTriComp_s choixFctUser = menu();

    remplirTab(tab, tailleTab);

    if (tailleTab < 20000) printTab(tab, tailleTab);
    printTrie(tab, tailleTab, choixFctUser->fonctionCompChoisie);

    int tempsExec = testAlgoTri(choixFctUser, tab, tailleTab);
    printf("Temps execution : %d microsecondes\n", tempsExec);

    if (tailleTab < 20000) printTab(tab, tailleTab);
    printTrie(tab, tailleTab, choixFctUser->fonctionCompChoisie);

    return 0;
}
