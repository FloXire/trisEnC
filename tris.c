#include <stdlib.h>
#include <stdio.h>
#include "tris.h"
#include "comparaison.h"
#include "affichage.h"

// Fonction permettant de permuter les valeurs des indices ind1 et ind2 contenues dans un tableau
void switche(int *tab, int ind1, int ind2)
{
    int temp = tab[ind1];
    tab[ind1] = tab[ind2];
    tab[ind2] = temp;
}

int quickSort(int *tab, int ind1, int ind2, int (*fctComp)(int, int))
{
    int nbElmts = ind2-ind1+1; // Nombre d'éléments dans la partie du tableau que l'on traite
    // Si on a un ou deux éléments dans cette partie du tableau on arrête la récursion
    if (nbElmts <= 2)
    {
        if ((nbElmts == 2) && fctComp(tab[ind2], tab[ind1])) switche(tab, ind1, ind2);
        // Terminaison de la récursion
        return 0;
    }

    int i = ind1+1;
    int j = ind2;
    int pivot = tab[ind1];

    while (i<j)
    {
        /* Cas d'un tri croissant
        On incrémente i de 1 si l'élément à l'indice i est
        plus petit que le pivot. De la même façon on décrémente j
        si l'élément à l'indice j est plus grand que le pivot */
        if (fctComp(tab[i], pivot) || fctComp(pivot, tab[j]))
        {
            if (fctComp(tab[i], pivot)) i++;
            if (fctComp(pivot, tab[j])) j--;
        }
        /* Cas d'un tri croissant
        Sinon, on switch les deux valeurs, on se retrouve
        avec la plus petite des deux valeurs dans la première
        partie du tableau et la plus grande dans la deuxième */
        else
        {
            switche(tab, i, j);
            i++;
            j--;
        }
    } // à partir d'ici i == j
    if (fctComp(tab[j], pivot))
    {
        switche(tab, ind1, j);
    }

    // Appel récursif sur la partie gauche du tableau
    quickSort(tab, ind1, j-1, fctComp);

    // Appel récursif sur la partie droite du tableau
    quickSort(tab, i, ind2, fctComp);

    return 0;
}

/* Compare les éléments voisins du tableau deux à deux.
   Cette fonction boucle sur le tableau jusqu'à ce qu'il soit trié */
int triBulles(int *tab, int ind1, int ind2, int (*fctComp)(int, int))
{
    int trie;
    for (int i=ind1; i<ind2; i++)
    {
        trie = 1; // par défaut on suppose que le tableau est trié

        for (int j=0; j<ind2; j++)
        {
            if (fctComp(tab[j+1], tab[j]))
            {
                switche(tab, j, j+1);
                trie = 0;
            }
        }

        if (trie) return 0;
    }

    return 0;
}

// Algorithme de tri Fusion
int triFusion(int *tab, int ind1, int ind2, int (*fctComp)(int, int))
{
    // Si le tableau est non vide
    if (ind1<ind2) {
        // On fractionne le tableau en deux parties
        int milieu = (ind1+ind2)/2;
        // Puis on refractionne chaque partie du tableau
        triFusion(tab, ind1, milieu, fctComp);
        triFusion(tab, milieu+1, ind2, fctComp);
        // Enfin, on fusionne nos bouts de tableau entre eux, en suivant la fonction de comparaison
        fusion(tab, ind1, milieu, ind2, fctComp);
    }

    return 0;
}

// Fonction servant à la fusion de deux tableaux
int fusion(int *tab, int indDebTab1, int indFinTab1, int indFinTab2, int (*fctComp)(int, int))
{
    int cpt1, cpt2, i;

    // On crée une table temporaire afin d'effectuer notre fusion
    int *tabTemp;
    tabTemp=(int*) malloc((indFinTab2+indFinTab1)*sizeof(int));

    // On parcourt nos deux tableaux à l'aide de compteurs que l'on incrémentera
    for(cpt1=indDebTab1, cpt2=indFinTab1+1, i=indDebTab1; cpt1<=indFinTab1 && cpt2<=indFinTab2; i++) {
        // Si la comparaison satisfait la fonction de comparaison
        if(fctComp(tab[cpt1], tab[cpt2])){
            tabTemp[i] = tab[cpt1++];
        }
        else {
            tabTemp[i] = tab[cpt2++];
        }
    }

    // Si il nous reste des éléments dans le tableau 1
    while(cpt1<=indFinTab1){
        tabTemp[i++] = tab[cpt1++];
    }

    // Si il nous reste des éléments dans le tableau 2
    while(cpt2<=indFinTab2){
        tabTemp[i++] = tab[cpt2++];
    }

    // On copie tout le contenu du tableau temporaire dans le vrai tableau
    for(i=indDebTab1; i<=indFinTab2; i++){
        tab[i] = tabTemp[i];
    }

    free(tabTemp); //On libère la mémoire

    return 0;
}

// Algorithme de tri par tas
int triParTas(int *tab, int ind1, int ind2, int (*fctComp)(int, int))
{
    // On construit la partie droite de l'arbre
    for(int i = ind2/2; i>=0; i--){
        tamiser(tab, i, ind2, fctComp);
    }

    // On construit la partie gauche de l'arbre
    for(int i = ind2; i>=1; i--){
        switche(tab, i, 0);
        tamiser(tab, 0, i-1, fctComp);
    }

    return 0;
}

// Descend tab[noeud] à sa place, sans dépasser l'indice n
int tamiser(int *tab, int noeud, int n, int (*fctComp)(int, int))
{
    int k = noeud;
    int j = 2*k;

    while(j <= n) {
        if (j < n && fctComp(tab[j], tab[j+1])) {
            j = j+1;
        }
        if (fctComp(tab[k], tab[j])) {
            switche(tab, k, j);
            k = j;
            j = 2*k;
        }
        else {
            j = n+1;
        }
    }

    return 0;
}

// Algorithme de tri par insertion
int triParInsertion(int *tab, int ind1, int ind2, int (*fctComp)(int, int))
{
    int temp;
    int j;

    for (int i=ind1; i<=ind2; i++)
    {
        temp = tab[i];
        j = i;

        while (j>0 && fctComp(temp, tab[j-1])) {
            tab[j] = tab[j-1];
            j = j-1;
        }

        tab[j] = temp;
    }

    return 0;
}
