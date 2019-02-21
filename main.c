#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h> //utilisée pour calculer le temps d'exécution des fonctions de tri
#include "affichage.h"
#include "tris.h"


// initialise le tableau avec des valeurs aléatoires
void remplirTab(int *tab, int tailleTab)
{
    printf("\nGeneration d'un tableau de %d nombres aleatoires\n", tailleTab);
    time_t t;
    srand(time(&t)); //Initialisation de la "graine" de la fonction random en fonction du temps
    for (int i=0; i<tailleTab; i++) //On remplit notre tableau de valeurs aléatoires
    {
        tab[i] = rand();
    }
}

// Function prenant en paramères un tableau non trié, le tri et renvoi le temps d'exécution
int testAlgoTri(FoncTriComp_s *choixFctUser, int *tab, int tailleTab, int compteur)
{
    // Initialisation des variables start et stop dans lesquelles nous allons enregistrer nos timers
    struct timeval *start, *stop;
    start = malloc(sizeof(struct timeval));
    stop = malloc(sizeof(struct timeval));

    gettimeofday(start, NULL); // On enregistre l'heure dans start
    // On trie le tableau avec la fonction de tri et de comparaison voulues
    choixFctUser->fonctionsTriChoisies[compteur](tab, 0, tailleTab-1, choixFctUser->fonctionCompChoisie);
    gettimeofday(stop, NULL); // On enregistre l'heure dans stop

    // Affichage de l'algorithme utilisé
    if (choixFctUser->fonctionsTriChoisies[compteur] == quickSort) printf("\nTri quicksort - ");
    else if (choixFctUser->fonctionsTriChoisies[compteur] == triBulles) printf("\nTri à bulles - ");
    else if (choixFctUser->fonctionsTriChoisies[compteur] == triFusion) printf("\nTri fusion - ");
    else if (choixFctUser->fonctionsTriChoisies[compteur] == triParTas) printf("\nTri par tas - ");
    else if (choixFctUser->fonctionsTriChoisies[compteur] == triParInsertion) printf("\nTri par insertion - ");

    //On renvoie le temps mis par la fonction de tri pour trier notre tableau
    // Si le compteur de secondes est supérieur à 0 (le start et le stop ne se sont pas produits durant la même seconde)
    if ((stop->tv_sec-start->tv_sec)>0) {
        if(stop->tv_usec < start->tv_usec){ // si stop(compteur us) < start(compteur us), alors on enlève 1 seconde
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
    int tailleTab = 15;
    int tab[tailleTab];

    // On récupère les choix de l'utilisateur (fonctions de tri et de comparaison à utiliser)
    PtrFoncTriComp_s choixFctUser = menu();

    // Initialisation du tableau
    remplirTab(tab, tailleTab);

    // Affiche si le tableau passé en paramètre est trié selon la fonction de comparaison choisie
    printTrie(tab, tailleTab, choixFctUser->fonctionCompChoisie);

    // Si le tableau est suffisamment petit on l'affiche (ici il est censé ne pas être trié)
    if (tailleTab < 200)
    {
        printf("\n");
        printTab(tab, tailleTab);
        printf("\n");
    }

    int tabEnCours[tailleTab];

    // Pour chaque algorithme de tri choisi par l'utilisateur
    for (int i=0; i<choixFctUser->nbFctChoisies; i++)
    {
        // On remet le tableau dans l'ordre initial pour pouvoir comparer les différents tris
        memcpy(tabEnCours, tab, tailleTab*sizeof(int));
        // On récupère le temps d'exécution de l'algorithme de tri
        int tempsExec = testAlgoTri(choixFctUser, tabEnCours, tailleTab, i);
        printf("Temps execution : %d microsecondes\n", tempsExec); // Affichage du temps d'exécution
        // Affiche si le tableau passé en paramètre est trié selon la fonction de comparaison choisie
        printTrie(tabEnCours, tailleTab, choixFctUser->fonctionCompChoisie); //
    }

    // Si le tableau est suffisamment petit on l'affiche (ici il est censé être trié)
    if (tailleTab < 200)
    {
        printf("\n");
        printTab(tabEnCours, tailleTab);
        printf("\n");
    }

    return 0;
}
