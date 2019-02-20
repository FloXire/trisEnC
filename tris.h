#ifndef H_TRIS
#define H_TRIS

void switche(int *tab, int ind1, int ind2);
int quickSort(int *tab, int ind1, int ind2, int (*fctComp)(int, int));
int triBulles(int *tab, int ind1, int ind2, int (*fctComp)(int, int));
int triFusion(int *tab, int ind1, int ind2, int (*fctComp)(int, int));
int fusion(int *tab, int indDebTab1, int indFinTab1, int indFinTab2, int (*fctComp)(int, int));
int triParTas(int *tab, int ind1, int ind2, int (*fctComp)(int, int));
int tamiser(int *tab, int noeud, int n, int (*fctComp)(int, int));
int TriParInsertion(int *tab, int ind1, int ind2, int (*fctComp)(int, int));

#endif
